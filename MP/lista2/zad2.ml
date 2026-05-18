let matrix_id = (1, 0, 0, 1);;

let matrix_mult m n =
  match m, n with 
  | (a1, b1, c1, d1), (a2, b2, c2, d2) ->
    (a1 * a2 + b1 * c2, a1 * b2 + b1 * d2,
       c1 * a2 + d1 * c2, c1 * b2 + d1 * d2);;

let rec matrix_expt m k =
  if k = 0 then matrix_id
  else if k = 1 then m
  else matrix_mult m (matrix_expt m (k-1)) ;;

let fib_matrix k = 
  let (fk1, fk, x, y) = matrix_expt (1, 1, 1, 0) k 
in fk;;
