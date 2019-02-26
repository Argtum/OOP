set PROGRAM="%~1"
set OUT="%TEMP%\out.txt"

:: Проверка количества аргументов. Если не соответствует 3-м, то выводит сообщение об ошибке
%PROGRAM% empty.txt > "%TEMP%\output.txt"
if NOT ERRORLEVEL 1 goto err
fc "%TEMP%\output.txt" expected-output-when-number-of-arguments-is-not-3.txt || goto err

:: Проверка количества аргументов. Если не соответствует 3-м, то выводит сообщение об ошибке
%PROGRAM% matrix.txt matrix.txt matrix.txt > "%TEMP%\output.txt"
if NOT ERRORLEVEL 1 goto err
fc "%TEMP%\output.txt" expected-output-when-number-of-arguments-is-not-3.txt || goto err

%PROGRAM% non-existing-file-name.txt matrix.txt > "%TEMP%\output.txt"
if NOT ERRORLEVEL 1 goto err
fc "%TEMP%\output.txt" expected-output-when-one-of-arguments-is-missing.txt || goto err

%PROGRAM% matrix.txt non-existing-file-name.txt > "%TEMP%\output.txt"
if NOT ERRORLEVEL 1 goto err
fc "%TEMP%\output.txt" expected-output-when-one-of-arguments-is-missing.txt || goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1
