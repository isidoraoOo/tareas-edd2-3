
//>, <

#include <iostream>

using namespace std;

typedef int tElemLista;

struct tNodo{
    tElemLista info;
    tNodo* next;
};

class tLista {  
    private:
        tNodo* head;    
        tNodo* tail;    
        tNodo* curr; //apunta al nodo anterior del actual    
        unsigned int listSize;    
        unsigned int pos; // posicion actual en la lista
    public:
        tLista();
        ~tLista();
        void clear();
        int insert(tElemLista item);
        int append(tElemLista item);
        tElemLista erase ();
        void moveToStart();
        void moveToEnd();
        void Next();
        void Prev();
        int lenght();
        int currPos();
        void moveToPos(unsigned int posicion);
        tElemLista getValue();
        int find(tElemLista info);
        void print();
};

