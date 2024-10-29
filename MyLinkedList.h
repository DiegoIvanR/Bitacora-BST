// Diego Ivan Rodriguez Nunez A01644772
// Luis Andres Casillas Casillas A01645008
// Ali Lopez Sarabia A01645060
// Act 2.3 - Act 2.3 - Actividad Integral estructura de datos lineales (Evidencia Competencia)
// 09/10/2024
// Programación de estructuras de datos y algoritmos fundamentales (Gpo 603)

#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H
#include <iostream>
using namespace std;

struct MyNodoLL {
    string data;
    MyNodoLL* next;

    MyNodoLL(string data, MyNodoLL* next) {
        this->data = data;
        this->next = next;
    }
    MyNodoLL(string data): MyNodoLL(data, nullptr) {}
};

class MyLinkedList {
    public:
        int size;  // Tamaño de la lista (número de nodos)
        MyNodoLL *head,  // Puntero al primer nodo de la lista (cabeza)
                 *tail;  // Puntero al último nodo de la lista (cola)
        MyLinkedList(); // O(1)
        ~MyLinkedList(); // O(n)
        int length(); // O(1)
        bool isEmpty(); // O(1)
        string first(); // O(1)
        string last(); // O(1)
        void insertFirst(string data); // O(1)
        void insertLast(string data); // O(1)
        void insertAt(int pos, string data);// O(n)
        void removeLast(); // O(n)
        void removeFirst(); // O(1)
        void removeAt(int pos); // O(n) 
        string getAt(int pos); // O(n)
        friend ostream& operator<<(ostream& os, const MyLinkedList& ll); // O(n)
        

        //funciones agregadas
        void mezcla(MyNodoLL* head, MyNodoLL* middle, int leftSize, int rightSize); // O(n)
        void mergesort(MyNodoLL* head, int size); // O(nlog(n))
        void mergesort(); // O(nlog(n)) es la "combinacion" de las funciones de arriba
        string extractIPandPort(const string& data); // O(n), donde n es el tamaño de la ip y el puerto
        string extractIP(const string& data); // O(n), donde n es el tamaño de la ip
        string getIPs(string ipInicio, string ipFin); // O(n)
        friend bool operator<(string data1, string data2); // O(n), donde n es el tamaño de la ip mas larga
};

#endif
