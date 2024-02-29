@echo off
Title Pobieranie
hostname >> \\192.168.8.239\Kochana\Komputery.txt
:start
if exist \\192.168.8.239\Kochana\Polecenie.txt goto copr_0
if exist \\192.168.8.239\Kochana\Odswierz.txt goto odsw_0
goto copr_00
:odsw_0
xcopy \\192.168.8.239\Kochana\Odswierz.txt /Y /Q
timeout 3
del \\192.168.8.239\Kochana\Odswierz.txt
goto copr_00
:copr_0
xcopy \\192.168.8.239\Kochana\Polecenie.txt /Y /Q
timeout 3
del \\192.168.8.239\Kochana\Polecenie.txt
:copr_00
goto start