#include <iostream>
#include "TDAlistaDeListas.cpp"
using namespace std;

class DeBlock{
  private:
    int cant_elems;
    tListadeListas L;
  public: 
    DeBlock(tElem* elems, int n, int b); //listo
    ~DeBlock();
    int insert(int pos, tElem elem); // listo
    tElem erase(int pos);
    tElem get_value(int pos); //listo
    int length(); //listo
    void clear(); //listo
};