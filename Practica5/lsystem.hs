-- Gari Arellano 848905
-- Alain Cascan 849183
module Lsystem where


-- Curva de Koch
-- Reglas: F → F+F--F+F
-- Axioma: F
-- Distancia: 1
-- Angulo: 60 grados
rulesCurvaKoch :: Char -> String
rulesCurvaKoch 'F' = "F+F--F+F"
rulesCurvaKoch '+' = "+"
rulesCurvaKoch '-' = "-"
rulesCurvaKoch _ = ""




-- Curva de Koch cuadrada
-- Reglas: F → F+F-F-F+F
-- Axioma: F
-- Distancia: 1
-- Angulo: 90 grados

rulesCurvaKochCuadrada :: Char -> String
rulesCurvaKochCuadrada 'F' = "F+F-F-F+F"
rulesCurvaKochCuadrada '+' = "+"
rulesCurvaKochCuadrada '-' = "-"
rulesCurvaKochCuadrada _ = ""



-- Koch Snowflake
-- Reglas: F → F-F++F-F
-- Axioma: F++F++F
-- Distancia: 1
-- Angulo: 60 grados

rulesKochSnowflake :: Char -> String
rulesKochSnowflake 'F' = "F-F++F-F"
rulesKochSnowflake '+' = "+"
rulesKochSnowflake '-' = "-"
rulesKochSnowflake _ = ""



-- Koch Anti–Snowflake
-- Reglas: F → F+F--F+F
-- Axioma: F++F++F
-- Distancia: 1
-- Angulo: 60 grados

rulesAntiSnowflake :: Char -> String
rulesAntiSnowflake 'F' = "F+F--F+F"
rulesAntiSnowflake '+' = "+"
rulesAntiSnowflake '-' = "-"
rulesAntiSnowflake _ = ""

-- Isla de Minkowski
-- Reglas: F -> F+F-F-FF+F+F-FF
-- Axioma: F+F+F+F
-- Distancia: 1
-- Angulo: 90 grados
rulesIslaMinkowski :: Char -> String
rulesIslaMinkowski 'F' = "F+F-F-FF+F+F-FF"
rulesIslaMinkowski '+' = "+"
rulesIslaMinkowski '-' = "-"
rulesIslaMinkowski _ = ""



-- Triángulo de Sierpinsky
-- Reglas: F → F-G+F+G-F
-- G → GG
-- Axioma: F-G-G
-- Distancia: 1
-- Angulo: 120 grados

rulesSierpinsky :: Char -> String
rulesSierpinsky 'F' = "F-G+F+G-F"
rulesSierpinsky 'G' = "GG"
rulesSierpinsky '+' = "+"
rulesSierpinsky '-' = "-"
rulesSierpinsky _ = ""



-- Sierpinsky Arrowhead
-- Reglas: F → G-F-G
--         G → F+G+F
-- Axioma: F
-- Distancia: 1
-- Angulo: 60 grados

rulesArrowhead :: Char -> String
rulesArrowhead 'F' = "G-F-G"
rulesArrowhead 'G' = "F+G+F"
rulesArrowhead '+' = "+"
rulesArrowhead '-' = "-"
rulesArrowhead _ = ""




-- Curva de Hilbert
-- Reglas: f → -g>+f>f+>g
--         g → +f>-g>g->f+
-- Axioma: f
-- Distancia: 1
-- Angulo: 90 grados

rulesHilbert :: Char -> String
rulesHilbert 'f' = "-g>+f>f+>g-"
rulesHilbert 'g' = "+f>-g>g->f+"
rulesHilbert '+' = "+"
rulesHilbert '-' = "-"
rulesHilbert '>' = ">"
rulesHilbert _ = ""


-- Curva de Gosper
-- Reglas: F → F-G--G+F++FF+G
--         G → +F-GG--G-F++F+G
-- Axioma: F
-- Distancia: 1
-- Angulo: 60 grados

rulesGosper :: Char -> String
rulesGosper 'F' = "F-G--G+F++FF+G-"
rulesGosper 'G' = "+F-GG--G-F++F+G"
rulesGosper '+' = "+"
rulesGosper '-' = "-"
rulesGosper _ = ""







evaluate :: (Char -> String) -> String -> String
evaluate _ "" = ""
evaluate f (s:rest) = (f s) ++ evaluate f rest

lsystem :: (Char -> String) -> String -> Int -> String
lsystem _ s 0 = s -- Si la distancia es 0, entonces devuelvo la misma string que me pasan
lsystem _ "" _ = "" -- Si la string es vacia, devuelvo vacio
lsystem f s n = lsystem f (evaluate f s) (n-1)
