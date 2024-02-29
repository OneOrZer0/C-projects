@echo off
Title SSSOF
:powtorz
if exist SOF.bat goto istnieje
goto powtorz
:istnieje
start SOF.vbs
:folder_start
if exist Loda goto otworz
goto folder_start
:otworz
start Loda
exit
