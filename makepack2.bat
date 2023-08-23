@echo off
set /p "filename=Enter filename (without .pak at the end): "
echo Writing into %filename%.pak ...
rem pause
packer.bat "%filename%.pak" data
rem pause