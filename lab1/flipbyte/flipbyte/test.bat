echo off

echo test good input data 
flipbyte.exe 6 > 6.txt
IF ERRORLEVEL 1 GOTO testFailed
fc /b 6.txt standart/6.txt
IF ERRORLEVEL 1 GOTO testFailed

echo test good input data 
flipbyte.exe 0 > 0.txt
IF ERRORLEVEL 1 GOTO testFailed
fc /b 0.txt standart/0.txt
IF ERRORLEVEL 1 GOTO testFailed

echo test good input data 
flipbyte.exe 255 > 255.txt
IF ERRORLEVEL 1 GOTO testFailed
fc /b 255.txt standart/255.txt
IF ERRORLEVEL 1 GOTO testFailed

echo test good input data 
flipbyte.exe 13 > 13.txt
IF ERRORLEVEL 1 GOTO testFailed
fc /b 13.txt standart/13.txt
IF ERRORLEVEL 1 GOTO testFailed

echo test without arguments
flipbyte.exe
IF NOT ERRORLEVEL 1 goto testFailed

echo test wrong data
flipbyte.exe -3
IF NOT ERRORLEVEL 1 goto testFailed

echo test not a number input data
flipbyte.exe notANumber
IF NOT ERRORLEVEL 1 GOTO testFailed

echo OK
pause
exit /B

:testFailed
echo Testing failed
pause
exit /B

 