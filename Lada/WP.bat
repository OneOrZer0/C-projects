@echo off
Title WP
if exist \\192.168.8.239\Kochana\Wynik.txt goto ist
goto pol
:ist
del \\192.168.8.239\Kochana\Wynik.txt
:pol
echo DESKTOP-B43LV3V > Polecenie.txt
echo mkdir test >> Polecenie.txt
timeout 1
xcopy Polecenie.txt \\192.168.8.239\Kochana /Y /Q
exit
