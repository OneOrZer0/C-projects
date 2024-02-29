@echo off
Title Kopiowanie
if exist \\192.168.8.120\Marunia\Dalej.txt goto usun
goto CD
:usun
del \\192.168.8.120\Marunia\Dalej.txt
:CD
if exist hosty.txt del hosty.txt
del \\192.168.8.120\Marunia\Koniec.txt
xcopy \\192.168.8.120\Marunia\hosty.txt /Y
exit
