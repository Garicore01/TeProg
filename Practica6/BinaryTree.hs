module BinaryTree where
import Data.List
data BST a = Vacio | Nodo a (BST a) (BST a)


empty :: BST a
empty = Vacio

leaf :: a -> BST a
leaf x = Nodo x (Vacio) (Vacio)

tree :: a -> BST a -> BST a -> BST a
tree a Vacio Vacio = leaf a
tree a lc Vacio = Nodo a lc (Vacio)
tree a Vacio rc = Nodo a (Vacio) rc
tree a lc rc = Nodo a lc rc
    

size :: BST a -> Integer
size Vacio = 0 -- Arbol Vacio
size (Nodo _ (Vacio) (Vacio)) = 1 -- Arbol hoja
size (Nodo _ (Vacio) rc) = 1 + size rc
size (Nodo _ lc (Vacio)) = 1 + size lc
size (Nodo _ lc rc) = 1 + size lc + size rc

-- Funcion auxiliar para pintar las tabulaciones
tabular :: Integer -> String
tabular 0 = ""
tabular x = "   " ++ (tabular (x-1))


pintar :: (Show a) => BST a -> Integer -> String --Show a, significa que a tiene que ser mostrable.
pintar Vacio _ = "<>"
pintar (Nodo a (Vacio) (Vacio)) _ = show a
pintar (Nodo x (lc) (rc)) nivel = show x ++ ['\n'] ++ (tabular nivel) ++ "|- " ++ (pintar lc (nivel+1)) ++ ['\n'] ++ (tabular nivel) ++ "|- " ++ (pintar rc (nivel+1)  )

instance (Show a) => Show (BST a ) where 
                                        show a = pintar a 0



add :: (Ord a) => BST a -> a -> BST a
add Vacio x = leaf x
add (Nodo x lc rc) y
  | y == x = Nodo x lc (add rc y) -- Si el elemento es igual, se añade a la derecha o a la izq?
  | y < x = Nodo x (add lc y) rc
  | y > x = Nodo x lc (add rc y)

build :: (Ord a) => [a] -> BST a
build [] = Vacio
build x = buildRec x Vacio 
                        where
                            buildRec [] a = a
                            buildRec (x:xs) a = buildRec xs (add a x)

buildBalanced :: (Ord a) => [a] -> BST a  
buildBalanced [] = Vacio
buildBalanced x = Nodo raiz (build lc) (build rc)
    where   
        (lc, raiz:rc) = splitAt (div (length x) 2) (sort x) 


preorder :: BST a -> [a]
preorder Vacio = []
preorder (Nodo x lc rc) = [x] ++ preorder lc ++ preorder rc

postorder :: BST a -> [a]
postorder Vacio = []
postorder (Nodo x lc rc) = postorder lc ++ postorder rc ++ [x]

inorder :: BST a -> [a]
inorder Vacio = []
inorder (Nodo x lc rc) = inorder lc ++ [x] ++ inorder rc


balance :: (Ord a) => BST a -> BST a
balance Vacio = Vacio
balance (Nodo x lc rc) = buildBalanced (postorder (Nodo x lc rc))



between :: (Ord a) => BST a -> a -> a -> [a]
between Vacio _ _ = []
between (Nodo a lc rc) xmin xmax
    | a < xmin = between rc xmin xmax
    | a > xmax = between lc xmin xmax
    | otherwise = [a] ++ between lc xmin xmax ++ between rc xmin xmax