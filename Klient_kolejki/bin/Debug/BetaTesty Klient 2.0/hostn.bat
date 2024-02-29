@echo off
Title Klient
hostname >> \\192.168.0.7\Marunia\hosty.txt
:Start
if exist \\192.168.0.7\Marunia\Kochana-Nikol.txt goto Istnieje
goto Start
:Istnieje
del \\192.168.0.7\Marunia\Kochana-Nikol.txt
echo MarkoSoft > Start.txt
:StartA
if exist Gotowe.txt goto Dalej
goto StartA
:Dalej
del Gotowe.txt
echo > \\192.168.0.7\Marunia\Dalej.txt
exit
