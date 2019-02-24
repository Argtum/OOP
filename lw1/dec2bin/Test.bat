set PROGRAM="%~1"
set OUT="%TEMP%\out.txt"

%PROGRAM% > "%TEMP%\output.txt"
if NOT ERRORLEVEL 1 goto err
fc "%TEMP%\output.txt" expected-output-when-number-of-arguments-is-not-2.txt || goto err

%PROGRAM% 1 2 > "%TEMP%\output.txt"
if NOT ERRORLEVEL 1 goto err
fc "%TEMP%\output.txt" expected-output-when-number-of-arguments-is-not-2.txt || goto err

%PROGRAM% Hello > "%TEMP%\output.txt"
if NOT ERRORLEVEL 1 goto err
fc "%TEMP%\output.txt" expected-output-when-arguments-is-not-decimal.txt || goto err

%PROGRAM% 4294967296 > "%TEMP%\output.txt"
if NOT ERRORLEVEL 1 goto err
fc "%TEMP%\output.txt" expected-output-when-arguments-is-out-of-range.txt || goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1
