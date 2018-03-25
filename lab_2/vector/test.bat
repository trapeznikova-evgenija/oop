set PROGRAM="%~1"

REM start of the program without parameters
ECHO 1 TEST
ECHO start of the program without parameters 
%PROGRAM%
IF NOT ERRORLEVEL 1 GOTO err

ECHO 2 TEST 
ECHO input1.txt
%PROGRAM% input1.txt
IF ERRORLEVEL 1 GOTO err
FC output.txt outtest1.txt
IF ERRORLEVEL 1 GOTO err

ECHO 3 TEST 
ECHO input2.txt
%PROGRAM% input2.txt
IF ERRORLEVEL 1 GOTO err
FC output.txt outtest2.txt
IF ERRORLEVEL 1 GOTO err

                              
ECHO Program successfully tested
EXIT

:err
ECHO Program testing failed :(
EXIT