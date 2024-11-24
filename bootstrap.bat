@echo off
cmake -B "build/release" -G "MinGW Makefiles"
@REM 会生成debug版本的makefile配置文件
@REM cmake -B "build/debug" -G "MinGW Makefiles" -Wno-dev
