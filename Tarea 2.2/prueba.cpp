#include <iostream>
#include "TDADeBlock.hpp"
using namespace std;

//>, <

int main() {

    tElem elems[4] = {1, 2, 3, 4};
    DeBlock Listota(elems, 4, 3);
    Listota.insert(2, 3);
    Listota.get_value(5);
    return 0;
}
