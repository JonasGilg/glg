rem ---------------------------------------------------------------------------------------------- #
rem Make sure to run "git submodule update --init" before executing this script!                   #
rem Default build mode is release, if "set GLG_DEBUG_BUILD=true" is executed before, all    #
rem dependecies will be built in debug mode.                                                       #
rem Usage:                                                                                         #
rem    make_externals.bat [additional CMake flags, defaults to -G "Visual Studio 15 Win64"]        #
rem Examples:                                                                                      #
rem    make_externals.bat                                                                          #
rem    make_externals.bat -G "Visual Studio 15 Win64"                                              #
rem    make_externals.bat -G "Visual Studio 16 2019" -A x64                                        #
rem ---------------------------------------------------------------------------------------------- #

rem The CMake generator and other flags can be passed as parameters.
set CMAKE_FLAGS=-G "Visual Studio 15 Win64"
IF NOT "%~1"=="" (
  SET CMAKE_FLAGS=%*
)

rem Check if GLG debug build is enabled with "set GLG_DEBUG_BUILD=true".
IF "%GLG_DEBUG_BUILD%"=="true" (
  echo GLG debug build is enabled!
  set BUILD_TYPE=debug
) else (
  set BUILD_TYPE=release
)

rem Create some required variables. ----------------------------------------------------------------

rem This directory should contain all submodules - they are assumed to reside in the subdirectory
rem "externals" next to this script.
set EXTERNALS_DIR=%~dp0\externals

rem Get the current directory - this is the default location for the build and install directory.
set CURRENT_DIR=%cd%

rem The build directory.
set BUILD_DIR=%CURRENT_DIR%\build\windows-externals-%BUILD_TYPE%

rem The install directory.
set INSTALL_DIR=%CURRENT_DIR%\install\windows-externals-%BUILD_TYPE%

rem Create some default installation directories.
cmake -E make_directory "%INSTALL_DIR%/include"

rem doctest --------------------------------------------------------------------------------------------

echo.
echo Installing doctest ...
echo.

cmake -E copy_directory "%EXTERNALS_DIR%/doctest/doctest" "%INSTALL_DIR%/include/doctest" || exit /b

rem glm --------------------------------------------------------------------------------------------

echo.
echo Installing glm ...
echo.

cmake -E copy_directory "%EXTERNALS_DIR%/glm/glm" "%INSTALL_DIR%/include/glm" || exit /b

cd "%CURRENT_DIR%"
echo Finished successfully.