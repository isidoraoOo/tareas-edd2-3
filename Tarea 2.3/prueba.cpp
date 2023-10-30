#include <iostream>
#include "TDADeBlock.hpp"
using namespace std;

//>, <

int main() {
    
    tElem elems[10] = {1, 2, 3, 4, 6, 7, 8, 9, 10, 8};
    DeBlock List(elems, 10, 7);
    //List.length();
    //List.insert(0, 2);
    List.get_value(0);
    return 0;
}

/*
g++ DeBlock.cpp ListaDeListas.cpp lista.cpp prueba.cpp -Wall -o prueba
./prueba
g++ -g DeBlock.cpp ListaDeListas.cpp lista.cpp prueba.cpp -Wall -o depurado
*/
