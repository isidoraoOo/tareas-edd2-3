//>, <
// g++ parte2.cpp -Wall -o parte2-compilado (compilar)
// .\parte2-compilado (ejecutar)

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include "mainPT1.cpp"

/*#define minimo 1
#define maximo 52"*/

using namespace std;

int tilin(){
    fstream file;
    file.open("baraja.dat", ios::in | ios::binary);

    if (!file) {
        cout << "No se pudo abrir el archivo." << endl;
        return 1;
    }    

    int n;
    file.read((char*)&n, sizeof(int));
    Naipe* cartas = new Naipe[n];
    file.read((char*)cartas, sizeof(Naipe) * n);
    for(int i = 0; i < n; i++){
        cout<<"La carta " <<i<< "Es de color: "<< cartas[i].color <<endl;
    }
    delete[] cartas;
    file.close();
    return 0;
};
