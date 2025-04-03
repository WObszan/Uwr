let rec suffixes xs =
  match xs with
  | [] -> [[]]
  | x::xs' -> xs :: suffixes xs';;