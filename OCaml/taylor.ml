(* function that computes the factorial of n *)
let rec fact n = 
  if n = 0. 
  then 1. 
  else n *. fact (n-.1.);;

(*
x -> Point in which we want to know the approximate value of e^x;
n -> Number of terms of Taylor's series we want to develop;
*)
let rec taylor x n = 
  if n = 0. 
  then 1. 
  else ((x ** n)/.(fact n)) +. taylor x (n -. 1.);;

(* Some sample case, for test *)
taylor (-3.) 25.;;
taylor 1. 10.;;
taylor 0. 10.;;
taylor 5. 10.;;
taylor 5. 15.;;
taylor 5. 20.;;
taylor 5. 25.;;

