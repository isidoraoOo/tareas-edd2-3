#include <iostream>
#include "TDADeBlock.hpp"
#include "TDAlistaDeListas.hpp"
using namespace std;
//>, <

DeBlock::DeBlock(tElem* elems, int n, int b) {
    int cant_listas = n / b;
    if (n % b != 0) {
        cant_listas += 1;
    }
    cant_elems = n;

    int i = 0;
    int e = 0;
    while (e < cant_listas) {
        tLista Lista;
        for (int j = 0; j < b && i <= n; j++){
            tElem valor = elems[i];
            Lista.append(valor);
            i++;
            if (i > n){
                break;
            }
        }
        L.append(Lista);
        e++;
    }
}

void DeBlock::print(){
    L.print();
}

void DeBlock::clear(){
    L.clear();
}

DeBlock::~DeBlock(){
    cant_elems = 0;
}


int DeBlock::insert(int pos, tElem elem){
    int a = L.Insert_block(pos, elem);
    cant_elems++;
    cout<<a<<endl;
    return a;
}

tElem DeBlock::get_value(int pos){
    tElem elem;
    elem = L.GetValue_block(pos);
    cout<<elem<<endl;
    return elem;
}

int DeBlock::length(){
    cout<<cant_elems<<endl;
    return cant_elems;
}

