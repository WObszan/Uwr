let rec mem x xs =
  match xs with 
  | [] -> false
  | a :: xs' -> if x = a then true
  else mem x xs';;