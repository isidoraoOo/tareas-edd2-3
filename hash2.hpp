//tabla hash tic tac toe

#include <iostream>
using namespace std;
#define VACIA -1
#define M 10000

typedef int tipoClave;
typedef string tipoInfo[3][3];

struct ranura{
  tipoClave clave;
  tipoInfo info;
  int estado;
};

ranura HT[M];

class Hash{
    private:
        void clear();
    public:
        Hash();
        ~Hash();
        int hashInsert(ranura HT[], tipoClave k, tipoInfo I);
        tipoInfo* hashDelete(ranura HT[], tipoClave k);
        tipoInfo* hashSearch(ranura HT[], tipoClave k);
        int h(tipoClave k);
        int p(tipoClave k, int i);
};