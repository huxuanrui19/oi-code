@echo off
setlocal EnableExtensions DisableDelayedExpansion
chcp 65001 >nul
pushd "%~dp0" || exit /b 1
set "data="
for /d %%D in ("..\*评测数据") do if exist "%%~fD\序列修缮\*.in" set "data=%%~fD\序列修缮"
if not defined data (
    echo No T2 judge inputs found.
    exit /b 1
)

set "work=%TEMP%\repair-test-%RANDOM%-%RANDOM%"
mkdir "%work%" || exit /b 1
if not defined CXX set "CXX=g++"
set "result=1"
"%CXX%" -std=c++14 -O2 repair.cpp -o "%work%\repair.exe" || goto finish

set /a passed=0, total=0 >nul
for %%F in ("%data%\*.in") do (
    set "input=%%~fF"
    set "answer=%%~dpnF.ans"
    set "case_id=%%~nF"
    call :check
)
echo %passed%/%total% passed
if %passed% equ %total% set "result=0"

:finish
rmdir /s /q "%work%"
popd
exit /b %result%

:check
set /a total+=1 >nul
if not exist "%answer%" (
    echo %case_id%  MISSING ANSWER
    exit /b
)
"%work%\repair.exe" < "%input%" > "%work%\actual.txt" || (
    echo %case_id%  RUNTIME ERROR
    exit /b
)
powershell.exe -NoProfile -NonInteractive -Command "$expected = [IO.File]::ReadAllText($env:answer).Trim(); $actual = [IO.File]::ReadAllText((Join-Path $env:work 'actual.txt')).Trim(); if ($actual -ceq $expected) { exit 0 }; if (!$actual) { $actual = '<empty>' }; Write-Host ($env:case_id + '  FAIL  expected ' + $expected + ', got ' + $actual); exit 1"
if errorlevel 1 exit /b
echo %case_id%  PASS
set /a passed+=1 >nul
exit /b
