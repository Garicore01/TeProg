-- Gari Arellano 848905
-- Alain Cascan 849183
module Lsystem where


-- Curva de Koch
-- Reglas: F → F+F--F+F
-- Axioma: F
-- Distancia: 1
-- Angulo: 60 grados
-- rulesArrowhead :: Char -> String
-- rulesArrowhead 'F' = "F+F--F+F"
-- rulesArrowhead '+' = "+"
-- rulesArrowhead '-' = "-"
-- rulesArrowhead _ = ""




-- Curva de Koch cuadrada
-- Reglas: F → F+F-F-F+F
-- Axioma: F
-- Distancia: 1
-- Angulo: 90 grados

-- rulesArrowhead :: Char -> String
-- rulesArrowhead 'F' = "F+F-F-F+F"
-- rulesArrowhead '+' = "+"
-- rulesArrowhead '-' = "-"
-- rulesArrowhead _ = ""



-- Koch Snowflake
-- Reglas: F → F-F++F-F
-- Axioma: F++F++F
-- Distancia: 1
-- Angulo: 60 grados

-- rulesArrowhead :: Char -> String
-- rulesArrowhead 'F' = "F-F++F-F"
-- rulesArrowhead '+' = "+"
-- rulesArrowhead '-' = "-"
-- rulesArrowhead _ = ""




-- Koch Anti–Snowflake
-- Reglas: F → F+F--F+F
-- Axioma: F++F++F
-- Distancia: 1
-- Angulo: 60 grados

-- rulesArrowhead :: Char -> String
-- rulesArrowhead 'F' = "F+F--F+F"
-- rulesArrowhead '+' = "+"
-- rulesArrowhead '-' = "-"
-- rulesArrowhead _ = ""




-- Triángulo de Sierpinsky
-- Reglas: F → F-G+F+G-F
-- G → GG
-- Axioma: F-G-G
-- Distancia: 1
-- Angulo: 120 grados

-- rulesArrowhead :: Char -> String
-- rulesArrowhead 'F' = "F-G+F+G-F"
-- rulesArrowhead 'G' = "GG"
-- rulesArrowhead '+' = "+"
-- rulesArrowhead '-' = "-"
-- rulesArrowhead _ = ""



-- Sierpinsky Arrowhead
-- Reglas: F → G-F-G
--         G → F+G+F
-- Axioma: F
-- Distancia: 1
-- Angulo: 60 grados

-- rulesArrowhead :: Char -> String
-- rulesArrowhead 'F' = "G-F-G"
-- rulesArrowhead 'G' = "F+G+F"
-- rulesArrowhead '+' = "+"
-- rulesArrowhead '-' = "-"
-- rulesArrowhead _ = ""




-- Curva de Hilbert
-- Reglas: f → -g>+f>f+>g
--         g → +f>-g>g->f+
-- Axioma: f
-- Distancia: 1
-- Angulo: 90 grados

rulesArrowhead :: Char -> String
rulesArrowhead 'f' = "-g>+f>f+>g-"
rulesArrowhead 'g' = "+f>-g>g->f+"
rulesArrowhead '+' = "+"
rulesArrowhead '-' = "-"
rulesArrowhead _ = ""


-- Curva de Gosper
-- Reglas: F → F-G--G+F++FF+G
--         G → +F-GG--G-F++F+G
-- Axioma: F
-- Distancia: 1
-- Angulo: 60 grados

-- rulesArrowhead :: Char -> String
-- rulesArrowhead 'F' = "F-G--G+F++FF+G-"
-- rulesArrowhead 'G' = "+F-GG--G-F++F+G"
-- rulesArrowhead '+' = "+"
-- rulesArrowhead '-' = "-"
-- rulesArrowhead _ = ""







evaluate :: (Char -> String) -> String -> String
evaluate _ "" = ""
evaluate f (s:rest) = (f s) ++ evaluate f rest

lsystem :: (Char -> String) -> String -> Int -> String
lsystem _ s 0 = s -- Si la distancia es 0, entonces devuelvo la misma string que me pasan
lsystem _ "" _ = "" -- Si la string es vacia, devuelvo vacio
lsystem f s n = lsystem f (evaluate f s) (n-1)
