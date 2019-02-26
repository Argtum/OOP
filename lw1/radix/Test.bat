set PROGRAM="%~1"
set OUT="%TEMP%\out.txt"

%PROGRAM% 2 10 01001 4 > "%TEMP%\output.txt"
if NOT ERRORLEVEL 1 goto err
fc "%TEMP%\output.txt" expected-output-when-number-of-arguments-is-not-4.txt || goto err

%PROGRAM% 10 2 > "%TEMP%\output.txt"
if NOT ERRORLEVEL 1 goto err
fc "%TEMP%\output.txt" expected-output-when-number-of-arguments-is-not-4.txt || goto err

%PROGRAM% 1 10 0 > "%TEMP%\output.txt"
if NOT ERRORLEVEL 1 goto err
fc "%TEMP%\output.txt" expected-output-when-incorrect-notation.txt || goto err

%PROGRAM% 2 37 1 > "%TEMP%\output.txt"
if NOT ERRORLEVEL 1 goto err
fc "%TEMP%\output.txt" expected-output-when-incorrect-notation.txt || goto err

%PROGRAM% 2 10 3 > "%TEMP%\output.txt"
if NOT ERRORLEVEL 1 goto err
fc "%TEMP%\output.txt" expected-output-when-incorrect-number.txt || goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1
