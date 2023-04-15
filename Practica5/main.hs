-- Gari Arellano 848905
-- Alain Cascan 849183
import Tplot
import SVG(savesvg)
import Lsystem

main = do
    --savesvg "Prueba" $ tplot (1, 90, (0,0), 90) ">+>+>+"
    --savesvg "Triángulo de Sierpinsky" $ tplot (1, 120, (0, 0), 0) $ lsystem rulesArrowhead "F-G-G" 4
    savesvg "Curva de Hilbert" $ tplot (1, 90, (0, 0), 0) $ lsystem rulesArrowhead "f" 7
    savesvg "Curva de Gosper" $ tplot (1, 60, (0, 0), 0) $ lsystem rulesArrowhead "F" 3

