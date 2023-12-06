# main-sdl-vscode
Projeto para programar game usando a biblioteca SDl2 usando como compilador o Visual Studio Code. 
O compilador usa o MinGW, porem so funciona se usar o MinGW do [Code::Blocks](https://www.codeblocks.org/downloads/).

## compilador
Na pasta principal do projeto possui um arquivo .bat chamado de compiler. Esse arquivo possui o comando para compilar o projeto.
``` g++ -obin/game main.cpp src/*cpp -Iinclude -Iinclude/game -Llib -lSDL2main -lSDL2 -lSDL2_image -Wno-narrowing ```
Onde ele ele define o local e nome  do executavel ```-obin/game```. o arquivo principal e outros ```main.cpp src/*.cpp```. O referencial para as bibliotecas SDL2 e para o desenvolvimento do jogo ``` -Iinclude -Iinclude/game```. aposs isso temos as flags do SDL2 para que ele funcione ```-lSDL2main -lSDL2 -lSDL2_image```. e por ultimo ```-Wno-narrowing``` para que não aparece alertas falando sobre um inconsistencia.

## Engine.h
Para saber mais sobre as funções que o projeto tem, pesso que leia esse [readme](https://github.com/PedroVitor-oss/main_SDL/blob/main/README.md).

