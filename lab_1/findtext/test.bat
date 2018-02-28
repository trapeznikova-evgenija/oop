set PROGRAM="%~1"

REM start of the program without parameters
ECHO start of the program without parameters 
%PROGRAM%
IF NOT ERRORLEVEL 1 GOTO err

REM start of the program with one parameter
ECHO start of the program with one parameter
%PROGRAM% OneParameters
IF NOT ERRORLEVEL 1 GOTO err

REM Start of the program with the number of parameters greater than 3
ECHO Start of the program with the number of parameters greater than 3
%PROGRAM% OneParameters "Lala" "Reagine" "Lacost" Calculate
IF NOT ERRORLEVEL 1 GOTO err

REM start of the program with an empty line as one of parameters
ECHO start of the program with an empty line as one of parameters
%PROGRAM% ""
IF NOT ERRORLEVEL 1 GOTO err

REM searchString = "the"
ECHO searchString = "the" 
ECHO the string is in the text 
%PROGRAM% input.txt "the"
IF ERRORLEVEL 1 GOTO err
FC output.txt outtest1.txt
IF ERRORLEVEL 1 GOTO err

REM searchString = "1234"
ECHO searchString = "1234"
ECHO the string is in the text
%PROGRAM% input.txt "1234"
IF ERRORLEVEL 1 GOTO err
FC output.txt outtest2.txt
IF ERRORLEVEL 1 GOTO err

REM searchString = "who was"
ECHO searchString = "who was"
ECHO the string is in the text
%PROGRAM% input.txt "who was"
IF ERRORLEVEL 1 GOTO err
FC output.txt outtest3.txt
IF ERRORLEVEL 1 GOTO err

REM searchString = "young is beautiful"
ECHO searchString = "young is beautiful"
ECHO the string is in the text
%PROGRAM% input.txt "young is beautiful"
IF ERRORLEVEL 1 GOTO err
FC output.txt outtest4.txt
IF ERRORLEVEL 1 GOTO err

REM find a string that is not in the text
ECHO find a string that is not in the text
%PROGRAM% input.txt "critical thinking"
IF NOT ERRORLEVEL 1 GOTO err
FC output.txt outtest5.txt
IF ERRORLEVEL 1 GOTO err 
                              
ECHO Program successfully tested
EXIT

:err
ECHO Program testing failed :(
EXIT