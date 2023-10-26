#include <iostream>
#include "TDADeBlock.hpp"
#include "TDAlistaDeListas.hpp"
using namespace std;


DeBlock::DeBlock(tElem* elems, int n, int b){
    int a = n / b;
    if (n % b != 0){
        a += 1;
    }
    cant_elems = a;
    int i = 0;
    tLista Lista;
    while (i < n){
        for (int a = 0; a < b; a++){
            tElem valor = elems[i];
            Lista.append(valor);
            i++;
        }
        Lista.clear();
        L.append(Lista);
    }
}

void DeBlock::clear(){
    L.clear();
}

DeBlock::~DeBlock(){
    cant_elems = 0;
}


int DeBlock::insert(int pos, tElem elem){
    int a = L.Insert_block(pos, elem);
    return a;
}

tElem DeBlock::get_value(int pos){
    tElem elem;
    elem = L.GetValue_block(pos);
    return elem;
}

int DeBlock::length(){
    return L.Length_block();
}

