set PROGRAM="%~1"

REM start of the program without parameters
ECHO 1 TEST
ECHO start of the program without parameters 
%PROGRAM%
IF NOT ERRORLEVEL 1 GOTO err

ECHO 2 TEST 
ECHO correct input matrix1
%PROGRAM% matrix1.txt
IF ERRORLEVEL 1 GOTO err
FC output.txt outtest1.txt
IF ERRORLEVEL 1 GOTO err

ECHO 3 TEST
ECHO correct input matrix2
%PROGRAM% matrix2.txt
IF ERRORLEVEL 1 GOTO err
FC output.txt outtest2.txt
IF ERRORLEVEL 1 GOTO err

ECHO 4 TEST
ECHO correct input matrix3
%PROGRAM% matrix3.txt
IF ERRORLEVEL 1 GOTO err
FC output.txt outtest3.txt
IF ERRORLEVEL 1 GOTO err

ECHO 5 TEST
ECHO input matrix4 - determinant = 0
%PROGRAM% matrix4.txt
IF ERRORLEVEL 1 GOTO err
FC output.txt outtest4.txt
IF ERRORLEVEL 1 GOTO err
                              
ECHO Program successfully tested
EXIT

:err
ECHO Program testing failed :(
EXIT