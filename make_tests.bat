@echo off

rem ---------------------------------------------------------------------------------------------- #
rem Default build mode is release, if "export GLG_DEBUG_BUILD=true" is executed before, the #
rem application will be built in debug mode.                                                       #
rem Usage:                                                                                         #
rem    make_tests.bat [additional CMake flags, defaults to -G "Visual Studio 15 Win64"]                  #
rem Examples:                                                                                      #
rem    make_tests.bat                                                                                    #
rem    make_tests.bat -G "Visual Studio 15 Win64"                                                        #
rem    make_tests.bat -G "Visual Studio 16 2019" -A x64                                                  #
rem ---------------------------------------------------------------------------------------------- #

rem create some required variables -----------------------------------------------------------------

rem The CMake generator and other flags can be passed as parameters.
set CMAKE_FLAGS=-G "Visual Studio 15 Win64"
IF NOT "%~1"=="" (
  SET CMAKE_FLAGS=%*
)

rem Check if GLG debug build is set with the environment variable
IF "%GLG_DEBUG_BUILD%"=="true" (
  ECHO GLG debug build is enabled!
  set BUILD_TYPE=debug
) else (
  set BUILD_TYPE=release
)

rem This directory should contain the top-level CMakeLists.txt - it is assumed to reside in the same
rem directory as this script.
set CMAKE_DIR=%~dp0

rem Get the current directory - this is the default location for the build and install directory.
set CURRENT_DIR=%cd%

rem The build directory.
set BUILD_DIR=%CURRENT_DIR%\build\windows-%BUILD_TYPE%

rem The install directory.
set INSTALL_DIR=%CURRENT_DIR%\install\windows-%BUILD_TYPE%

rem This directory should be used as the install directory for make_externals.bat.
set EXTERNALS_INSTALL_DIR=%CURRENT_DIR%\install\windows-externals-%BUILD_TYPE%

rem create build directory if necessary -----------------------------------------------------------

if exist "%BUILD_DIR%" goto BUILD_DIR_CREATED
    mkdir "%BUILD_DIR%"
:BUILD_DIR_CREATED

rem configure, compile & install -------------------------------------------------------------------

cd "%BUILD_DIR%"
cmake %CMAKE_FLAGS% -DCMAKE_INSTALL_PREFIX="%INSTALL_DIR%"^
      -DGLG_EXTERNALS_DIR="%EXTERNALS_INSTALL_DIR%" "%CMAKE_DIR%"  || exit /b

cmake --build . --config %BUILD_TYPE% --target install --parallel 8  || exit /b

rem Delete empty files installed by cmake
robocopy "%INSTALL_DIR%\lib" "%INSTALL_DIR%\lib" /s /move || exit /b

cd "%CURRENT_DIR%"
echo Finished successfully.

@echo on