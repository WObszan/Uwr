let rec maximum xs =
  match xs with
  | [] -> false
  | [x] -> x
  | x :: xs' -> let max_tail = maximum xs' in if x > max_tail
     then x
     else max_tail;;


maximum [];;