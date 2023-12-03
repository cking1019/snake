@echo off

cd %~dp0

@rem windres -i ico.rc -o ico-out.o # 将ico.rc目录下的资源文件转为二进制

IF "%1"=="dynamic" (
	g++ src/*.cpp -shared -fPIC -olibsnake.dll -leasyx -lole32 -lgdi32
    g++ -L. -lsnake main.cpp -osnake2 && snake2
)

IF "%1"=="run" (
	g++ -obuild/snake src/*.cpp -Iinclude -Iinclude/easyx -Llib -leasyx -lole32 -lgdi32
    cd build
    snake
    cd ..
)

IF "%1"=="static" (
	g++ -obuild/snake -static src/*.cpp -Iheader -Iheader/easyx static/favicon.o -Iheader -Llib -leasyx -lole32 -lgdi32
)


IF "%1"=="git" (
    git add .
    git commit -m '#'
    git push origin master
)

IF "%1"=="clean" (
    git rm -r --cached .
)
