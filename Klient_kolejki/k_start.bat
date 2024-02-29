@echo off
Title MarkWare
if exist \\192.168.0.101\Marunia\Kochana.txt goto cos
if exist \\192.168.0.101\Marunia\kolejkaALL.txt goto kolejka
goto exit
:cos
del \\192.168.0.101\Marunia\Kochana.txt
echo dzialaj > k_start.txt
goto exit
:kolejka
echo Jedziem! >> kolejkaALL.txt
goto exit
:exit
exit
