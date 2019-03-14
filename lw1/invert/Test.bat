set PROGRAM="%~1"
set OUT="%TEMP%\output.txt"

%PROGRAM% 3x3-matrix.txt > %OUT% || goto err
fc %OUT% 3x3-matrix-out.txt || goto err

%PROGRAM% > %OUT%
fc %OUT% expected-output-when-number-of-arguments-is-not-2.txt || goto err

%PROGRAM% matrix.txt matrix.txt > %OUT%
fc %OUT% expected-output-when-number-of-arguments-is-not-2.txt || goto err

%PROGRAM% non-existing-file-name.txt > %OUT%
fc %OUT% expected-output-when-one-of-arguments-is-missing.txt || goto err

%PROGRAM% 4x4-matrix.txt > %OUT% || goto err
fc %OUT% 4x4-matrix-out.txt || goto err

%PROGRAM% 2x3-matrix.txt > %OUT% || goto err
fc %OUT% 2x3-matrix-out.txt || goto err

%PROGRAM% 3x2-matrix.txt > %OUT% || goto err
fc %OUT% 3x2-matrix-out.txt || goto err

%PROGRAM% matrix-with-determinant-equale-null.txt > %OUT% || goto err
fc %OUT% expected-output-when-matrix-determinate-is-0.txt || goto err

%PROGRAM% empty.txt > %OUT% || goto err
fc %OUT% empty-out.txt || goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1
