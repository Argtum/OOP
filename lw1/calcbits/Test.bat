set PROGRAM="%~1"
set OUT="%TEMP%\out.txt"

%PROGRAM% 5 > %OUT% || goto err
fc %OUT% five-out.txt || goto err

:: Проверка количества аргументов. Если не соответствует 2-м, то выводит сообщение об ошибке
%PROGRAM% > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% expected-output-when-number-of-arguments-is-not-2.txt || goto err

:: Проверка типа аргументов. Если тип не соответствует, то выводит сообщение об ошибке
%PROGRAM% Привет > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% expected-output-when-argument-wrong_type.txt || goto err



echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1
