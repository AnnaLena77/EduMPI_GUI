mkdir windows-build

C:\Qt\Tools\CMake_64\bin\cmake.exe -G "Ninja" -S . -B windows-build -DCMAKE_MAKE_PROGRAM="C:\Qt\Tools\Ninja\ninja.exe"

cd windows-build

C:\Qt\Tools\Ninja\ninja.exe

C:\Qt\6.8.1\mingw_64\bin\windeployqt.exe --qmldir .. --dir release appGUI_Cluster.exe

copy appGUI_Cluster.exe release