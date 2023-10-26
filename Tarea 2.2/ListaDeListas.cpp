#include <iostream>
#include "TDAlistaDeListas.hpp"
using namespace std;

#define MAXSIZE 1000000

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
    for (int i = 0; i < listSize; i++) {
        listArray[i].clear();
    }

    delete[] listArray;
    listArray = nullptr;
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
        if (pos < cont + listArray[i].length()){
            int a = pos - cont;
            listArray[i].moveToPos(a);
            listArray[i].insert(elem);
            return 1;
        }
        else {
            cont = cont + listArray[i].length();
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

tLista* tListadeListas::GetValue(){
    if (curr >= 0 && curr <= listSize){
        return &listArray[curr];
    }
    else {
    	return nullptr;
    }
}

tElem tListadeListas::GetValue_block(int pos){
    int cont = 0;
    tElem elem;
    for (int i = 0; i < listArray->length(); i++){
        if (pos < cont + listArray[i].length()){
            int a = pos - cont;
            listArray[i].moveToPos(a);
            elem = listArray[i].getValue();
            break;
        } else {
            cont = cont + listArray[i].length();
        }
    }
    if (pos < 0 || pos >= Length_block()){
        elem = -1;
    }
    return elem;
};
