#include <iostream>
#include "TDAlista.hpp"
using namespace std;

class tListadeListas{
  private:
    unsigned int maxSize;
    unsigned int listSize;
    unsigned int curr;
    tLista* listArray;

  public:
    tListadeListas(); 
    ~tListadeListas(); 
    void clear(); 
    int insert(tLista lista); 
    int Insert_block(int pos, tElem elem);
    int append(tLista lista); ;
    void moveToStart(); 
    void moveToEnd(); 
    void moveToPos(int pos); 
    void next(); 
    void prev(); 
    int Length(); 
    int Length_block();
    int currPos(); 
    tLista GetValue(); 
    tElem GetValue_block(int pos);
    tListadeListas De_Block(tElem* elems, int n, int b);
};

