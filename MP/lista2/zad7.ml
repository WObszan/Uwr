let rec is_sorted xs =
  match xs with
  | [] -> true
  | [x] -> true
  | x :: y :: xs' -> if x > y
    then false
  else is_sorted ( y :: xs') ;; 