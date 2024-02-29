@echo off
Title SSSOF
:powtorz
if exist SOF.bat goto istnieje
goto powtorz
:istnieje
start SOF.bat
:folder_start
if exist Folder goto otworz
goto folder_start
:otworz
start Folder
exit
