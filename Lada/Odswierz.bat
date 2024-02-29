@echo off
Title Odswierz
if exist \\192.168.8.239\Kochana\Lista_PC.txt goto istnieje
goto ods
:istnieje
del \\192.168.8.239\Kochana\Lista_PC.txt
:ods
if exist Lista_PC.txt del Lista_PC.txt
echo MarkoSoft >> \\192.168.8.239\Kochana\Odswierz.txt
exit
