set PROGRAM="%~1"

REM start of the program without parameters
ECHO 1 TEST
ECHO start of the program without parameters 
%PROGRAM%
IF NOT ERRORLEVEL 1 GOTO err

ECHO 2 TEST 
ECHO input correct parametr 6
%PROGRAM% 6
IF ERRORLEVEL 1 GOTO err
FC output.txt outtest1.txt
IF ERRORLEVEL 1 GOTO err

ECHO 3 TEST
ECHO parameter input is not from the valid range 1345
%PROGRAM% 1345
IF NOT ERRORLEVEL 1 GOTO err

ECHO 4 TEST
ECHO parametr not numeric "lenght"
%PROGRAM% "length"
IF NOT ERRORLEVEL 1 GOTO err

ECHO 5 TEST
ECHO parametr not numeric beautiful
%PROGRAM% beautiful
IF NOT ERRORLEVEL 1 GOTO err

ECHO 6 TEST
ECHO input correct parametr 255
%PROGRAM% 255
IF ERRORLEVEL 1 GOTO err
FC output.txt outtest2.txt
IF ERRORLEVEL 1 GOTO err 

ECHO 7 TEST
ECHO input correct parametr 0
%PROGRAM% 0
IF ERRORLEVEL 1 GOTO err
FC output.txt outtest3.txt
IF ERRORLEVEL 1 GOTO err

ECHO 8 TEST
ECHO input correct parametr 1
%PROGRAM% 1
IF ERRORLEVEL 1 GOTO err
FC output.txt outtest4.txt
IF ERRORLEVEL 1 GOTO err
                              
ECHO Program successfully tested
EXIT

:err
ECHO Program testing failed :(
EXIT