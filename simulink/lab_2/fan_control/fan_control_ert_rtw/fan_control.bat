set MATLAB=D:\matlab_set

cd .

if "%1"=="" ("D:\matlab_set\bin\win64\gmake"  -f fan_control.mk all) else ("D:\matlab_set\bin\win64\gmake"  -f fan_control.mk %1)
@if errorlevel 1 goto error_exit

exit 0

:error_exit
echo The make command returned an error of %errorlevel%
exit 1
