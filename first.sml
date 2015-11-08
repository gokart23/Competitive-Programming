val x = 34;
val y = 17;

fun swap(pr : int*bool) =
	(#2 pr, #1 pr)

fun sum_list(xs : int list) = 
	if null xs
	then 0
	else hd xs + sum_list(tl xs)

fun append (xs : int list, ys : int list) = 
	if null xs
	then ys
	else (hd xs) :: append(tl xs, ys)