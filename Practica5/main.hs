-- Gari Arellano 848905
-- Alain Cascan 849183
import Tplot
import SVG(savesvg)
import Lsystem

main = do
    --savesvg "Prueba" $ tplot (1, 90, (0,0), 90) ">+>+>+"    
    savesvg "Curva de Koch" $ tplot (1, 60, (0, 0), 0) $ lsystem rulesCurvaKoch "F" 3
    savesvg "Curva de Koch cuadrada" $ tplot (1, -90, (0, 0), 0) $ lsystem rulesCurvaKochCuadrada "F" 3
    savesvg "Koch Snowflake" $ tplot (1, -60, (0, 0), 0) $ lsystem rulesKochSnowflake "F++F++F" 3
    savesvg "Koch Anti-Snowflake" $ tplot (1, -60, (0, 0), 0) $ lsystem rulesAntiSnowflake "F++F++F" 3


     
    savesvg "Isla de Minkowski" $ tplot (1, -90, (0, 0), 0) $ lsystem rulesIslaMinkowski "F+F+F+F" 4
    savesvg "Triágulo de Sierpinsky" $ tplot (1, -120, (0, 0), 0) $ lsystem rulesSierpinsky "F-G-G" 4
    savesvg "Sierpinsky Arrowhead" $ tplot (1, -60, (0, 0), 0) $ lsystem rulesArrowhead "F" 6
    savesvg "Curva de Gosper" $ tplot (1, -60, (0, 0), 0) $ lsystem rulesGosper "F" 3
    savesvg "Curva de Hilbert" $ tplot (1, -90, (0, 0), 0) $ lsystem rulesHilbert "f" 6

   

