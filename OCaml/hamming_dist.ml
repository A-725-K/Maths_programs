type nucleotide = A | C | G | T;;

let hamming_distance seq1 seq2 = 
  let rec aux acc = function
      (n1::l1, n2::l2) -> aux (if n1 = n2
                               then acc
                               else acc + 1)
                            (l1, l2)
    | ([], []) -> Some acc
    | _ -> None
  in aux 0 (seq1, seq2);;
