set PROGRAM="%~1"
set OUT="%TEMP%\out.txt"

%PROGRAM% 5 > %OUT% || goto err
fc %OUT% five-out.txt || goto err

:: �������� ���������� ����������. ���� �� ������������� 2-�, �� ������� ��������� �� ������
%PROGRAM% > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% expected-output-when-number-of-arguments-is-not-2.txt || goto err

:: �������� ���� ����������. ���� ��� �� �������������, �� ������� ��������� �� ������
%PROGRAM% ������ > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% expected-output-when-argument-wrong_type.txt || goto err



echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1
