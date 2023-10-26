#include <iostream>
#include "TDAlistaDeListas.hpp"
using namespace std;

#define MAXSIZE 1000000;

//tListadeListas


tListadeListas::tListadeListas(){
    maxSize = MAXSIZE;
    listSize = 0;
    curr = 0;
    listArray = new tLista[maxSize];
}

tListadeListas::~tListadeListas(){
    delete[] listArray;
}

void tListadeListas::clear(){
    listSize = curr = 0;
}

int tListadeListas::insert(tLista lista){
    int i;
    if (listSize >= maxSize){
        return -1;
    }

    for (i = listSize; i > curr; i--){
        listArray[i] = listArray[i-1];
    }
    listArray[i] = lista;
    listSize++;
    return i;
}

int tListadeListas::Insert_block(int pos, tElem elem){
    int cont = 0;
    for (int i = 0; i < listArray->length(); i++){
        if (pos <= cont + listArray[i].length()){
            int a = pos - cont;
            listArray[i].moveToPos(a);
            listArray[i].insert(elem);
            return 1;
        }
        else {
            cont = cont + listArray[i].length();
            i++;
        }  
    }
    return 0;
}

int tListadeListas::append(tLista lista){
    if (listSize >= maxSize){
        return 0;
    }
    int i = listSize + 1;
    listArray[i] = lista;
    listSize++;
    return 1;
}

void tListadeListas::moveToStart(){
    curr = 0;
}

void tListadeListas::moveToEnd(){
    curr = listSize;
}

void tListadeListas::moveToPos(int pos){
    curr = pos;
}

void tListadeListas::next(){
    if (curr > listSize){
        curr++;
    }
}

void tListadeListas::prev(){
    if (curr != 0){
        curr--;
    }
}

int tListadeListas::Length(){
    return listSize;
}

int tListadeListas::Length_block(){
    int largo = 0;
    for (int i = 0; i < listSize; i++){
        largo += listArray[i].length();
    }
    return largo;
}

int tListadeListas::currPos(){
    return curr;
}

tLista tListadeListas::GetValue(){
    if (curr >= 0 && curr <= listSize){
        return listArray[curr];
    }
    else {
    	return tLista();
    }
}

tElem tListadeListas::GetValue_block(int pos){
    int cont = 0;
    tElem elem;
    for (int i = 0; i < listArray->length(); i++){
        if (pos <= cont + listArray[i].length()){
            listArray[i].moveToPos(pos - cont);
            listArray[i].moveToStart();
            elem = listArray[i].getValue();
            return elem;
        } else {
            cont = cont + listArray[i].length();
            i++;
        }
    }
    return -1;
}

/*tListadeListas tListadeListas::De_Block(tElem* elems, int n, int b){
    int i = 0;
    int a;
    tLista Lista;
    tListadeListas Listota;
    while (i < n){
        for (a = 0; a < b; a++){
            tElem valor = elems[a];
            Lista.append(valor);
            i++;
        }
        Lista.clear();
        Listota.append(Lista);
    }
    return Listota;
}*/
