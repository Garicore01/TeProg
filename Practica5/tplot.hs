-- Gari Arellano 848905
-- Alain Cascan 849183
module Tplot where
import Turtle

listPosition :: Turtle -> [Position]
listPosition (paso,giro,p,orientacion) = [p]

tplot :: Turtle -> String -> [Position]
tplot tortuga [] = listPosition tortuga
tplot tortuga (s:rest) = case s of
    '>' -> listPosition tortuga ++ tplot (moveTurtle tortuga Forward) rest 
    '+' -> listPosition tortuga ++ tplot (moveTurtle tortuga TurnRight) rest 
    '-' -> listPosition tortuga ++ tplot (moveTurtle tortuga TurnLeft) rest 
    'F' -> listPosition tortuga ++ tplot (moveTurtle tortuga Forward) rest 
    'G' -> listPosition tortuga ++ tplot (moveTurtle tortuga Forward) rest 
    _   -> tplot tortuga rest -- Ignoro los demas caracteres
    