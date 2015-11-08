doubleMe x = x + x
doubleUs x y = x*2 + y*2
length' x = sum [1 | _ <- x]
odd' x = [y | z <- x, y <- z, odd y]

fact :: Integer -> Integer
fact 1 = 1
fact x = x * fact(x-1)

charName :: Char -> String
charName 'a' = "asdfkjsdlkf"
charName x = charName (pred x)

addVectors :: (Num a) => (a, a) -> (a, a) -> (a, a)
addVectors (x1, y1) (x2, y2) = (x1 + x2, y1 + y2)

mySum :: (Num a) => [a] -> a
mySum [] = 0
mySum (y:lim) = y + mySum lim

max' :: (Ord a, Int b) => [a] -> [a] -> b
max' [] [] = 0
max' (x:xs) [] = 1
max' [] (y:ys) = negate 1
max' (x:xs) (y:ys)
	| x > y = 1
	| x < y = negate 1
	| otherwise = max' xs ys