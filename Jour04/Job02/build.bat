@echo off
gcc -Wall -Wextra -g -o album_program main.c print_album.c
if %ERRORLEVEL% == 0 (
    echo Compilation successful! Run album_program.exe to start the program.
) else (
    echo Compilation failed with error code %ERRORLEVEL%.
)
