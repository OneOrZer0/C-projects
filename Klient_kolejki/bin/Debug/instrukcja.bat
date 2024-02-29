@echo off
Title Instrukcja MW
:Start
if exist \\192.168.0.100\Marunia\kolejka.txt goto kolejka
if exist \\192.168.0.100\Marunia\off_pc.txt goto off_pc
timeout /t 1
goto Start
:kolejka
echo MarkoWare > kolejka.txt
goto exit
:off_pc
shutdown /s /t 0
goto exit
:exit
echo DALEJ! > letsgo.txt
exit
