(* ----- Compress same consecutive elements ----- *)
let rec compress = function 
    [] -> []
  | [x] -> [x]
  | x::y::l -> 
      if x = y 
      then compress (y::l)
      else x::compress (y::l);;

(* test *)
compress ["a";"a";"a";"a";"b";"c";"c";"a";"a";"d";"e";"e";"e";"e"];;

(* ----- Unify same consecutive elements in a list ----- *)
let pack l =
  let rec aux acc curr = function
      [] -> acc
    | [x] -> (x::curr)::acc
    | x::y::l -> 
        if x = y
        then aux acc (x::curr) (y::l)
        else aux ((x::curr)::acc) [] (y::l)
  in List.rev(aux [] [] l);;

(* test *)
pack ["a";"a";"a";"a";"b";"c";"c";"a";"a";"d";"d";"e";"e";"e";"e"];;

(* ----- Run-length encoding data compression method  ----- *)
let encode_10 l =
  let rec aux acc how_many = function
      [] -> acc
    | [x] -> (x, how_many)::acc
    | x::y::l ->
        if x = y 
        then aux acc (how_many+1) (y::l)
        else aux ((x, how_many)::acc) 1 (y::l)
  in rev(aux [] 1 l);;

(* test *)
encode_10 ["a";"a";"a";"a";"b";"c";"c";"a";"a";"d";"e";"e";"e";"e"];;

(* ----- Extension of the above algorithm ----- *)
type 'a rle =
      One of 'a
    | Many of int * 'a;;

let encode_11 ls =
  let rec aux = function
      [] -> []
    | (x,hm)::l ->
        (if hm = 1
         then One x
         else Many(hm,x))::aux l
  in aux (encode_10 ls);;

encode_11 ["a";"a";"a";"a";"b";"c";"c";"a";"a";"d";"e";"e";"e";"e"];;

(* ----- Decoder of run-length encoder ----- *)
let decode ls =
  let rec aux acc = function
      [] -> acc
    | One x::l -> aux (x::acc) l
    | Many(hm, x)::l -> 
        if hm = 0 
        then aux (x::acc) l
        else aux (x::acc) (Many(hm-1,x)::l)
  in rev(aux [] ls);;

(* test *)
decode [Many (4,"a"); One "b"; Many (2,"c"); Many (2,"a"); One "d"; Many (4,"e")];;

(* Gray code *)
let gray n =
    let rec addn n = function
        [] -> []
        | x::l -> (n^x)::addn n l
    in
    let rec create_gray l =
        let rl = rev l
        in (addn "0" l)@(addn "1" rl)
    in
    let rec aux acc n =
        if n = 1 
        then acc
        else
            aux (create_gray acc) (n-1)
        in aux ["0";"1"] n
;;

(* tests *)
gray 2;;
gray 3;;
gray 4;;
