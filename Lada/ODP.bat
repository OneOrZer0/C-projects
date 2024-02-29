@echo off
Title ODP
if exist \\192.168.8.239\Kochana\Wynik.txt goto ist
goto koniec
:ist
xcopy \\192.168.8.239\Kochana\Wynik.txt /Y /Q
:koniec
exit
