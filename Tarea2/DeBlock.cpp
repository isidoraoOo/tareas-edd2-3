#include <iostream>
#include "TDADeBlock.hpp"
#include "TDAlistaDeListas.hpp"
using namespace std;

DeBlock::DeBlock(){
    cant_elems = 0;
}

DeBlock::DeBlock(tElem* elems, int n, int b){
    L.De_Block(elems,n,b);
    int a = n / b;
    if (n % b != 0){
        a += 1;
    }
    cant_elems = a;
}

void DeBlock::clear(){
    L.clear();
}

DeBlock::~DeBlock() {
    L.clear();
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

