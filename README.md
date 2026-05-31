# Atividade 03 - Computação Gŕafica - Imagens e Desenho

Este projeto implementa um conjunto de algoritmos clássicos de rasterização 2D utilizando SDL2 como backend gráfico.

## Dependências

Ubuntu/Linux:
```bash
sudo apt install libsdl2-dev cmake g++
```

## Compilação

```bash
mkdir build
cd build
cmake ..
make
```

## Execução
```bash
./app
```

## Estrutura do projeto
```bash
include/
├── draw/
│ ├── circle.h
│ ├── ellipse.h
│ ├── line.h
│ └── rectangle.h
└── image.h

src/
├── draw/          <- Pasta Draw tem todas as primitivas
│ ├── circle.cpp
│ ├── ellipse.cpp
│ ├── line.cpp
│ └── rectangle.cpp
├── image.cpp      <- Aqui tem implementação do buffer de imagem
└── main.cpp

```

## Observações
O projeto utiliza SDL2 para renderização 2D via textura.Todos os algoritmos são implementados manualmente com o apoio do material de aulas.

## COMO USAR 
Nessa aplicação é possível alternar entre diferentes primitivas de desenho usando comandos do teclado. A `tecla 1` ativa o modo de `linhas horizontais e verticais` , enquanto as `teclas 2 e 3` alternam entre os algoritmos de `reta DDA` e `reta Bresenham`, respectivamente. A `tecla 4` ativa o desenho de `retângulos`. Para os círculos, a `tecla 5` seleciona o método `circulo angular` e a `tecla 6` o `circulo de Bresenham`. Já a `tecla 7` ativa o modulo de `elipse angular`, enquanto a `tecla 8` ativa o modo de `elipse de Bresenham`.

## MODOS

### VERTICAL_HORIZONTAL_LINE
<img width="500" height="400" alt="Vertical-Horizontal" src="https://github.com/user-attachments/assets/6b8de4ae-b5c8-4461-81c1-9adb5846d6d8" />

## DDA
<img width="500" height="400" alt="DDA" src="https://github.com/user-attachments/assets/d5d78089-f41b-457c-bf52-2b9b008b2927" />

## BRESENHAM_LINE

<img width="500" height="400" alt="Bresenham" src="https://github.com/user-attachments/assets/a9698db5-30b6-4c2a-a42f-38000fbe5170" />

## RECTANGLE
<img width="500" height="400" alt="Rectangle" src="https://github.com/user-attachments/assets/a25de586-ff2a-4d29-980d-c6d613dcf6f4" />

## CIRCLE_ANGULAR
<img width="500" height="400" alt="CircleAngular" src="https://github.com/user-attachments/assets/3c3ccd31-4041-4664-bf85-ed105dc2ff2f" />

## CIRCLE_BRESENHAM
<img width="500" height="400" alt="CircleBresenham" src="https://github.com/user-attachments/assets/96984b95-88ed-4e24-87ef-a8a11212fc09" />


## ELLIPSE_ANGULAR
<img width="500" height="400" alt="EllipseAngle" src="https://github.com/user-attachments/assets/188cd947-991c-416c-8a6b-e7e4c510256b" />

## ELLIPSE_BRESENHAM
<img width="500" height="400" alt="EllipseBresenham" src="https://github.com/user-attachments/assets/6d0cd14e-d47a-4b2e-b196-49d28ed9dc5d" />

## FLOODFILL_RECURSIVE;
<img width="500" height="400" alt="image" src="https://github.com/user-attachments/assets/ba0065ad-011d-4291-b0bf-3b2b3b81be09" />

## FLOODFILL_STACK
<img width="500" height="400" alt="image" src="https://github.com/user-attachments/assets/bf563f8c-8589-4cf2-b744-d3826786f7ab" />

## SCANLINE;
<img width="500" height="400" alt="image" src="https://github.com/user-attachments/assets/71970e42-d212-4efe-854f-5107f4cff51e" />

### ARTEFATO ENGRAÇADO
<img width="500" height="400" alt="Artifact" src="https://github.com/user-attachments/assets/fde2cea0-0097-4771-82a1-37e531e196cf" />
