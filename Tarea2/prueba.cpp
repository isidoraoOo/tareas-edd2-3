#include <iostream>
#include "TDADeBlock.hpp"
using namespace std;

//>, <

int main() {

    tElem elems[4] = {'a', 'b', 'c', 'd'};
    DeBlock Listota(elems, 4, 3);
    Listota.insert(2, 'e');
    return 0;
}
