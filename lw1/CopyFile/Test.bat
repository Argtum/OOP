set PROGRAM="%~1"
set OUT="out.txt"

%PROGRAM% Hello.txt OUT || goto err
fc OUT Hello-out.txt || goto err

%PROGRAM% Empty.txt OUT || goto err
fc OUT Empty-out.txt || goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1
