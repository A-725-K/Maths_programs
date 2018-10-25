%%% to show all the elements in the lists
:- set_prolog_flag(answer_write_options,[max_depth(0)]). 

line(_, [], _) :- fail.
line(L, [_], Res) :-
	!, append(L, [1], Res). 
line(L, [T,R|Before], Res) :-
	S is T+R,
	append(L, [S], Temp),
	line(Temp, [R|Before], Res).

pascal(0, []) :- !.
pascal(1, [[1]]) :- !.
pascal(X, L) :-
	Y is X-1,
	pascal(Y, Temp),
	last(Temp, LineBefore),
	line([1], LineBefore, NewLine),
	append(Temp, [NewLine], L).
