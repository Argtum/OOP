set PROGRAM="%~1"

%PROGRAM% 5 > "%TEMP%\output.txt" || goto err
fc "%TEMP%\output.txt" five-out.txt || goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1
