@echo off

REM ===== ENV =====
set QT=C:\Qt\6.5.3\mingw_64
set PATH=C:\msys64\mingw64\bin;%PATH%

echo ==== CLEAN ====
if exist build rmdir /s /q build
if exist deploy rmdir /s /q deploy

echo ==== CONFIGURE ====
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release

echo ==== BUILD ====
cmake --build build

echo ==== DEPLOY ====
mkdir deploy
copy build\QuanLyHoSoSinhVien.exe deploy\

REM ===== COPY QT DLL =====
echo ==== COPY QT DLL ====
copy %QT%\bin\Qt6Core.dll deploy\
copy %QT%\bin\Qt6Gui.dll deploy\
copy %QT%\bin\Qt6Widgets.dll deploy\
copy %QT%\bin\Qt6Sql.dll deploy\

REM ===== COPY COMPILER RUNTIME (RẤT QUAN TRỌNG) =====
copy C:\msys64\mingw64\bin\libgcc_s_seh-1.dll deploy\
copy C:\msys64\mingw64\bin\libstdc++-6.dll deploy\
copy C:\msys64\mingw64\bin\libwinpthread-1.dll deploy\

REM ===== PLATFORM =====
mkdir deploy\platforms
copy %QT%\plugins\platforms\qwindows.dll deploy\platforms\

REM ===== SQL (nếu dùng SQLite) =====
mkdir deploy\sqldrivers
copy %QT%\plugins\sqldrivers\qsqlite.dll deploy\sqldrivers\

echo ==== RUN TEST ====
deploy\QuanLyHoSoSinhVien.exe

echo ==== DONE ====
pause