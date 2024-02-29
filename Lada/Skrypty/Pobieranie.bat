@echo off
Title Pobieranie

if exist \\192.168.8.239\Kochana\Polecenie.txt goto copy_a
goto copy_aa
:copy_a
xcopy \\192.168.8.239\Kochana\Polecenie.txt
timeout 3
if exist Polecenie.txt goto ist_a
goto copy_a
:ist_a
del \\192.168.8.239\Kochana\Polecenie.txt
:copy_aa

pause