maxStrOcc :: String -> Char -> Int -> Int -> Int
maxStrOcc [] _  cnt max' = max cnt max'
maxStrOcc (x:xs) c  cnt max'
    | x == c    = maxStrOcc xs  c (cnt+1) (max cnt max')
    | otherwise = maxStrOcc xs  x 1       (max cnt max')

main = do
    input <- getLine
    putStrLn $ show (maxStrOcc input ' ' 0 0)
