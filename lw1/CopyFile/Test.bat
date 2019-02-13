set PROGRAM="%~1"
set OUT="%TEMP%\out.txt"

%PROGRAM% Empty.txt OUT || goto err
fc OUT Empty-out.txt || goto err

%PROGRAM% OneLine.txt OUT || goto err
fc OUT OneLine-out.txt || goto err

%PROGRAM% MultiLine.txt OUT || goto err
fc OUT MultiLine-out.txt || goto err

%PROGRAM% non-existing-file-name.txt OUT > "%TEMP%\output.txt"
if NOT ERRORLEVEL 1 goto err
fc "%TEMP%\output.txt" expected-output-when-input-file-is-missing.txt || goto err

%PROGRAM% OneLine.txt > "%TEMP%\output.txt"
if NOT ERRORLEVEL 1 goto err
fc "%TEMP%\output.txt" expected-output-when-number-of-arguments-is-not-3.txt || goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1
