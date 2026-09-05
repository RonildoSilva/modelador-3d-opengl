# Modelador 3D em OpenGL

> Editor de cenas 3D em C++/Qt/OpenGL: primitivas (cubo, toro, bule, árvore), carregamento de modelos OBJ e 3DS, luzes móveis, sombras, câmeras e salvamento de estado.

![status](https://img.shields.io/badge/status-concluído-success) ![cpp](https://img.shields.io/badge/C%2B%2B-11-blue) ![opengl](https://img.shields.io/badge/OpenGL-GLUT%20%2B%20Qt-green)

## Sobre
Trabalho 1 da disciplina de Computação Gráfica (UFC, 2018.1). O usuário adiciona objetos à cena, seleciona e transforma cada um (translação, rotação, escala), posiciona fontes de luz, alterna entre projeção perspectiva e ortogonal e entre câmera distante e câmera de jogo. A cena pode ser gravada e recarregada de arquivo texto (`state.txt`). A continuação com curvas está em [modelador-3d-curvas-opengl](https://github.com/RonildoSilva/modelador-3d-curvas-opengl).

## Stack
- C++11, OpenGL/GLU, freeglut, Qt 5 (`QGLWidget`, Qt Designer), qmake
- `bib/` (câmeras, vetor 3D, desenho, GUI) baseada no material da disciplina

## Estrutura de pastas
```text
main.cpp, mainwindow.*, oglwidget.*   janela Qt, widget OpenGL, teclado e mouse
bib/                                  Camera, CameraDistante, CameraJogo, Vetor3D, Desenha, GUI, Extra
entities/                             cube, torus, teapot, tree, luz, model
entities/models/                      objmodelloader, tdsmodelloader
data/3ds/                             modelos de exemplo
state*.txt                            cenas salvas
Modelador3D.pro                       projeto qmake
```

## Como executar
```bash
sudo apt-get install freeglut3-dev libsdl-image1.2-dev qt5-default
qmake Modelador3D.pro && make && ./Modelador3D
```

## Status
Concluído. Trabalho acadêmico; não recebe manutenção.

## Autor
Ronildo Silva · ronildo.comp@gmail.com
