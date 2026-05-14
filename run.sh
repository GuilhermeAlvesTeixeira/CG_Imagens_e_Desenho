#!/bin/bash

mkdir -p build
cd build || exit

if [ -f "./app" ]; then
    ./app
else
    echo "Executável não encontrado. Tentando compilar..."

    cd ..
    
    if [ -f "./build.sh" ]; then
        chmod +x build.sh
        ./build.sh
        
        cd build || exit
        if [ -f "./app" ]; then
            ./app
        fi
    else
        echo "build.sh não encontrado na raiz do projeto."
    fi
fi