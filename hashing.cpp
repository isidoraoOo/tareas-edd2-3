
//funciones hash
// <

#include <iostream>
#include "hash2.hpp"
using namespace std;


Hash::Hash(){
    for (int i = 0; i < M; i++){
        HT[i].estado == VACIA;
    }
}

void Hash::clear(){
    int a = 0;
    while (a < M){
        HT[a].estado == VACIA;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                HT[a].info[i][j] = "_";
                
            }
        }
    }
}

Hash::~Hash(){
    clear();
}

int Hash::p(tipoClave k, int i){
    if (i == 0){
        return 0;
    }
    return 7*i*i + 11*i + 13;
}

int Hash::h(tipoClave k) {
    int posicion = VACIA;
    for(int i = 0; i < M; i++) {
        if(HT[i].clave == k) {
            posicion = i;
            break;
        }
    }
}

int Hash::hashInsert(ranura HT[], tipoClave k, tipoInfo I){
    int inicio, i;
    int pos = inicio = h(k);
    for (i = 1; HT[pos].estado != VACIA && HT[pos].clave != k; i++){
        pos = (inicio + p(k, i)) % M;
    }
    if (HT[pos].clave == k){
        return 0;
    } else {
        HT[pos].clave = k;
        for (int a = 0; a < 3; a++){
            for (int e = 0; e <3; e++){
                HT[pos].info[a][e] == I[a][e];
            }
        }
        
        return 1;
    }
}