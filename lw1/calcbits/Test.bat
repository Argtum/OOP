set PROGRAM="%~1"

%PROGRAM% 5 > "%TEMP%\output.txt" || goto err
fc "%TEMP%\output.txt" five-out.txt || goto err

:: �������� ���������� ����������. ���� �� ������������� 2-�, �� ������� ��������� �� ������
%PROGRAM% > "%TEMP%\output.txt"
if NOT ERRORLEVEL 1 goto err
fc "%TEMP%\output.txt" expected-output-when-number-of-arguments-is-not-2.txt || goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1
