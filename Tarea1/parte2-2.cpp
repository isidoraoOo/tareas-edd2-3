//>, <
// g++ parte2.cpp -Wall -o parte2-compilado (compilar)
// .\parte2-compilado (ejecutar)

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <random> 
//#include "main.cpp" //para incluir los struct

using namespace std;

struct Naipe{

    int numero; //va del 0 al 13
    char palo; //pica, corazon, diamante, trebol
    char color; //rojo o negro

};

void leerBinario(){

  //leer binario
  fstream file;
  file.open("baraja.dat", ios::binary | ios::in);
  int n;
  file.read((char*)&n, sizeof(int));

  Naipe* arr_n = new Naipe[n];
  file.read((char*)arr_n, sizeof(Naipe)*n);
  file.close();
}

Naipe* Barajar(Naipe* baraja, int n){
  
  //barajar
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> dist(0, 53);

  //guardar en el arreglo nuevo
  Naipe* barajado = new Naipe[n];
  for (int i = 0; i < n; i++ ){ //recorro el archivo baraja
    for (int j = 0; j < n; j++){ //guardo en barajado
      if (barajado[j] = NULL)
    }
  }
  

}

int main(){
  leerBinario();
  return 0;
}
