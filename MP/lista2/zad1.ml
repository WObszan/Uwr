let rec fib n =
  if n = 0
    then 0
  else if n = 1
    then 1
    else fib (n-1) + fib(n-2);;

let fib_iter n =
  let rec it n acc_a acc_b=
  if n = 0
    then acc_a
else if n = 1
  then acc_b
else it (n-1) acc_b (acc_a + acc_b) 
  in it n 0 1;;
