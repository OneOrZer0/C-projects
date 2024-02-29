@echo off
Title Czekam na Dalej.txt
:start
if exist \\192.168.0.7\Marunia\Dalej.txt goto dalej
goto start
:dalej
del \\192.168.0.7\Marunia\Dalej.txt
echo MarkoSoft > Dalej.txt
exit
