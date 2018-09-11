/* 
	Ex 1:
	Define a predicate "nat/1", namely a predicate whose name is nat and
	whose arity is 1, which is true on ground terms that represent 
	natural numbers	in the form of 0 and s(...)

	NAT(0) = TRUE
	NAT(x+1) = NAT(x)
*/

knat(0).
knat(s(X)) :- knat(X).

/*
	Ex 2.1:
	Define the addition of natural numbers, given in the representation 
	using 0	and s.

	SUM(x, 0) = x
	SUM(x+1, y) = 1 + SUM(x, y)
*/

ksum(0, Y, Y).
ksum(s(X), Y, s(Z)) :- ksum(X, Y, Z).

/* 
	Ex 2.2:
	Try to use the addition to perform difference: what do you get ?

	DIFF(x, 0) = x
	DIFF(x, y, n) = SUM(y, n, x)
*/

kdiff(X, Y, Z) :- ksum(Y, Z, X).

/* 
	Ex 3.1:
	Define the multiplication of natural numbers, given in the 
	representation using 0 and s.

	MUL(x, 0) = 0
	MUL(x+1, y) = SUM(y, MUL(x, y))
*/

kmul(0, _, 0).
kmul(s(X), Y, Z) :- kmul(X, Y, M), ksum(Y, M, Z).

/* 
	Ex 3.2:
	Try to use the multiplication to perform division: what do you get ?
	DIV(x, 0) = NaN
	DIV(x, y, n) = MUL(y, n, x)
*/

kdiv(_, 0, nan).
kdiv(X, Y, Z) :- kmul(Y, Z, X).

/**********************************************************************/

/*
    Ex 4:
    Implement a my_append(List1, List2, AppendedList) predicate that
    operates over the first two ground arguments, and the third one
    unbound, and unifies AppendedList with the concatenation of List1
    and List2.
*/

my_append([], L, L).
my_append([T|List1], List2, [T|AppendedList]) :- 
    my_append(List1, List2, AppendedList).

/*
    Ex 5:
    Implement a my_reverse(List, RevList) predicate that operates 
    over the first ground arguments, and the second one unbound, and
    unifies RevList with List reversed.
*/

my_reverse([], []).
my_reverse([T|List], RevList) :- 
	my_append(L, [T], RevList),
	my_reverse(List, L), !.

/*
    Ex 6:
    Implement a palindrome(List) predicate that succeeds if the ground
    List passwd as argument is palindrome.
*/

palindrome(List) :-
	my_reverse(List, List).

/*
    Ex 7:
    Implement a setUnion(List1, List2, Union) that takes two ground
    lists List1 and List2, each of which does not contain
    repeated elements, and unifies Union, unbound variable used as
    output parameter, with the set union of the elements
    belonging to List1 and List2, without repeated elements.

    Example: setUnion([a, b], [c, a, b], Union) unifies Union with 
    [a, b, c] (the order of the elements in Union does not
    matter: [a, c, b], [c, b, a], etc, would be correct results as
    well).
*/

setUnion([], L, L).
setUnion([T|List1], List2, Union) :-
	member(T, List2), !,
	setUnion(List1, List2, Union).
setUnion([T|List1], List2, [T|Union]) :-
	setUnion(List1, List2, Union).

/*
    Ex 8:
    Implement a setDifference(List1, List2, Difference) predicate that
    takes two ground lists List1 and List2, each of which
    does not contain repeated elements, and unifies Difference,
    unbound variable used as output parameter, with the list of
    elements that belong to List1 but not to List2. 

    Example: setDifference([a, b], [a, c], Difference) unifies 
    Difference with [b] (the order of the elements in Difference does
    not matter).
*/

setDifference([], _, []).
setDifference([T|List1], List2, Diff) :-
	member(T, List2), !,
	setDifference(List1, List2, Diff).
setDifference([T|List1], List2, [T|Diff]) :-
	setDifference(List1, List2, Diff).

/*
	Ex. 9:
	Implement a setIntersection(List1, List2, Intersection) predicate that takes two ground lists List1 
	and List2, each of which does not contain repeated elements, and unifies Intersection, unbound 
	variable used as output parameter, with the list of elements that belong both to List1 and to List2, 
	without repetitions. 

	Example: setIntersection([a, b], [c, a, b], Intersection) unifies Intersection with [a, b] 
	(the order of the elements in Intersection does not matter).
*/

setIntersection([], _, []).
setIntersection([T|List1], List2, [T|Inters]) :-
	member(T, List2), !,
	setIntersection(List1, List2, Inters).
setIntersection([_|List1], List2, Inters) :-
	setIntersection(List1, List2, Inters).

/*
	Ex. 10:
	Implement a powerSet(List, PowerSet) predicate that takes one ground list List that does not contain 
	repeated elements, and unifies PowerSet, unbound variable used as output parameter, with the list of
   	elements that belong to the power set of List, namely with the list of lists that represent all 
	List's subsets.

	Example: powerSet([a, b, c], PowerSet) unifies PowerSet with
	[[], [a], [b], [c], [a, b], [a, c], [b, c], [a, b, c]]
	(the order of the elements in PowerSet does not matter).
*/

unionAll([], _, []).
unionAll([T|List], E, [S1|Union]) :-
	setUnion(T, [E], S1),
	unionAll(List, E, Union), !.

powerSet([], [[]]).
powerSet([T|List], PowerSet) :-
	powerSet(List, ToUnion),
	unionAll(ToUnion, T, Unified),
	setUnion(ToUnion, Unified, PowerSet).

/*
	Ex. 11:
	Implement a cartesianProduct(List1, List2, Product) predicate that two ground lists List1 and List2,
   	each of which does not contain repeated elements, and unifies Product, unbound variable used as 
	output parameter, with the Cartesian Product of List1 and List2. Product must contain no repeated 
	entries.

	Example: cartesianProduct([a, b, c], [d, e], Product) unifies Product with
	[(a, d), (a, e), (b, d), (b, e), (c, d), (c, e)]
	(the order of the elements in Product does not matter).
*/

product(_, [], []).
product(E, [T|L], [(E,T)|X]) :-
	product(E, L, X), !.
	
cartesianProduct([], _, []). 
cartesianProduct([T|List1], List2, Product) :- 
	product(T, List2, S),
	cartesianProduct(List1, List2, ToUnion),
	my_append(ToUnion, S, Product).

/*
	Ex. 12:
	Implement a sortAndClean(List, SortedAndCleanedList) predicate that takes one ground List of integers
   	(List may contain repeated entries) and unifies SortedAndCleanedList with the elements of List, 
	ordered in increased order, and without repeated elements.
*/

pivoting([], _, [], _).
pivoting([T|List], [T|S1], S2, E) :-
	T < E,
	pivoting(List, S1, S2, E).
pivoting([T|List], S1, [T|S2], E) :-
	T > E,
	pivoting(List, S1, S2, E).
pivoting([_|List], S1, S2, E) :-
	pivoting(List, S1, S2, E), !.

sortAndClean([], []).
sortAndClean([T|List], Ord) :-
	pivoting(List, S1, S2, T),
	sortAndClean(S1, OrdS1),
	sortAndClean(S2, OrdS2),
	my_append(OrdS1, [T], Temp),
	my_append(Temp, OrdS2, Ord), !.
