@echo off

%1
echo %ERRORLEVEL%

%1 0
echo %ERRORLEVEL%

%1 1
echo %ERRORLEVEL%

%1 15
echo %ERRORLEVEL%