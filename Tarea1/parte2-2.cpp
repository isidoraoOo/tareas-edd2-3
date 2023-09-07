
//>, <
// g++ parte2.cpp -Wall -o parte2-compilado (compilar)
// .\parte2-compilado (ejecutar)

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <random> 
#define min 0
#define max 53

//#include "main.cpp" //para incluir los struct

using namespace std;

struct Naipe{

    int numero; //va del 0 al 13
    char palo; //pica, corazon, diamante, trebol
    char color; //rojo o negro

};
int n;
int rojas = 0;
int negras = 0;
Naipe* arr_n;

void leerBinario(){

  fstream file;
  file.open("baraja.dat", ios::binary | ios::in);
  file.read((char*)&n, sizeof(int));
  arr_n = new Naipe[n];
  file.read((char*)arr_n, sizeof(Naipe)*n);
  file.close();
}

int Barajar(){
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> dist(min, max); 
  return dist(gen); 
}


void TipoJugada(string juego, int jugadores){
    fstream file;
    int* pos = new int[n];
    string nombre = juego + to_string(jugadores) + ".txt";
    file.open(nombre, ios::app);


    for (int i = 0; i < n; i++){
        pos[i] = 0; // Inicializar todas las posiciones como no ocupadas (0)
    }

    if (juego == "P"){
        int cont = jugadores;
        for (int a = 0; a < cont; a++){ //cuenta los saltos de linea
            for (int i = 0; i < 5 ; i++){ //cuenta la cantidad de cartas
                int carta;
                do {
                    carta = Barajar(); // Genera una carta aleatoria
                } while (pos[carta] != 0); // Verifica que la carta no esté ocupada

                pos[carta] = 1; // Marca la carta como ocupada
                if (arr_n[carta].color == 'R'){
                    rojas++;
                } else {
                    negras++;
                }
                file << carta << " ";
            }
            file << "\n";
        }
    } else if (juego == "B"){
        int cont = jugadores;
        for (int a = 0; a < cont; a++){ //cuenta los saltos de linea
            for (int i = 0; i < 4 ; i++){ //cuenta la cantidad de cartas
                int carta;
                do {
                    carta = Barajar(); // Genera una carta aleatoria
                } while (pos[carta] != 0); // Verifica que la carta no esté ocupada

                pos[carta] = 1; // Marca la carta como ocupada
                if (arr_n[carta].color == 'R'){
                    rojas++;
                } else {
                    negras++;
                }
                file << carta << " ";
            }
            file << "\n";
        }
    } else if (juego == "C"){
        int cont = jugadores;
        for (int a = 0; a < cont; a++){ //cuenta los saltos de linea
            for (int i = 0; i < 15 ; i++){ //cuenta la cantidad de cartas
                int carta;
                do {
                    carta = Barajar(); // Genera una carta aleatoria
                } while (pos[carta] >= 2); // Verifica que la carta ya esté ocupada
                pos[carta]++; // Marca la carta como ocupada
                if (arr_n[carta].color == 'R'){
                    rojas++;
                } else {
                    negras++;
                }
                file << carta << " ";
            }
            file << "\n";
        }
    }
    file.close();
    delete[] pos; // Libera la memoria del arreglo pos
}





int main(){
    leerBinario();
    string juego;
    int jugadores;

    cout << "Ingrese Juego (P, C o B): "<<endl;
    cin >> juego;
    cout << "Ingrese cantidad de jugadores: "<<endl;
    cin >> jugadores;
    TipoJugada(juego, jugadores);

    cout << "Cantidad de cartas Rojas: " << rojas << endl;
    cout << "Cantida de carta Negras: " << negras << endl;
    delete [] arr_n;
    return 0;
}
