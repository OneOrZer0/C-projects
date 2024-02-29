@echo off
Title Lista
if exist \\192.168.8.239\Kochana\Lista_PC.txt goto istnieje
if exist \\192.168.8.239\Kochana\Odswierz.txt goto ist_ods
goto wyjscie
:istnieje
xcopy \\192.168.8.239\Kochana\Lista_PC.txt /Y /Q
if exist \\192.168.8.239\Kochana\Odswierz.txt goto ist_ods
:wyjscie
exit
:ist_ods
del \\192.168.8.239\Kochana\Odswierz.txt
goto wyjscie
