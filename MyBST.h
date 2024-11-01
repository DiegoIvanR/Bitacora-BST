// Diego Ivan Rodriguez Nunez A01644772
// Este programa contiene una estructura de datos
// BST implementada en una clase llamada MyBST

#ifndef MYBST_H
#define MYBST_H
#include <iostream>
#include <string>
using namespace std;

struct MyNodeBST{
    int count; // Contador de IPs
    string ip; // La dirección IP
    MyNodeBST *left, // Apuntadores a los nodos hijos
              *right;
    MyNodeBST(int count, string ip){ // Constructor para un nodo con un dato
        this->count=count;
        this->ip = ip;
        this->left=this->right=nullptr;
    }
    MyNodeBST(){ // Constructor default (para poder crear un array de nodos)
        this->count = 0;
        this->left=this->right=nullptr;
        this->ip = "";
    }
};
 

class MyBST{
    private:
        int size; // Numero de nodos en el arbol
        MyNodeBST* root; // Nodo raiz
        bool search(int count,MyNodeBST* current); // O(logn)[si está balanceado] - busca recursivamente el dato, retorna si lo encuentra o no
        void preorder(MyNodeBST* current); // O(n) - imprime los datos del arbol (actual-izquierda-derecha)
        void inorder(MyNodeBST* current, int &count, int maxNodes); // O(n) - imprime los datos del arbol(izquierda-actual-derecha), definiendo un límite de nodos a recorrer
        void postorder(MyNodeBST* current); // O(n) - imprime los datos del (izquierda-derecha-actual)
        
        int height(MyNodeBST* current); // O(n) - regresa la altura maxima del arbol
        MyNodeBST* remove(MyNodeBST* current, int count); // O(logn)[si está balanceado] - borra el nodo del dato especificado
        MyNodeBST* replace(MyNodeBST* current); // O(n), donde n es la longitud de la rama de mayores del menor - reemplaza el dato por el mayor de los menores si es un nodo con ambos hijos
        //En caso de hacer alguno de los métodos recursivos y necesiten
        //otro método que haga la recursión deben de colocarlo como privado
        //sólo la función de preparación sería pública
    public:
        MyBST(); // O(1) - Constructor
        int length(); // O(1) - regresa el numero de nodos en el arbol
        bool isEmpty(); // O(1) - checa si esta vacio (true / false)
        bool search(int count); // O(logn)[arbol balanceado] - Funcion de preparacion para busqueda recursiva
        bool insert(string ip, int count); // O(logn)[arbol balanceado] - true si lo inserto o no
        bool remove(int count);// O(logn)[arbol balanceado] - si el valor estaba en el árbol lo borra
                              //y regresa true, caso contrario sólo regresa false
        //Estudiar borrado en BST
        //Estudiar AVL
        void preorder(); // O(n) - funcion de preparacion para imprimr el arbol recursivamente
        void inorder(int maxNodes); // O(n) - funcion de preparacion para imprimr el arbol recursivamente, definiendo un límite de nodos.
        void postorder(); // O(n) - funcion de preparacion para imprimr el arbol recursivamente
        void level(); // O(n) - imprime el arbol a lo BFS (por niveles) de manera iterativo
        void visit(int type);//Type: 1->preorder,2->inorder.3->postorder,4->level
                                        //Imprime el recorrido separado por comas sin espacio entre los elementos.
        int height();// O(n) - funcion de preparacino para regresar la altura del BST.
        void ancestors(int count);// O(logn)[arbol balanceado] - imprime los ancestros del valor pasado separados por comas y sin dejar espacios entre ellos.
                                 //el orden de impresión debe ser de la raíz hacía abajo.
                                //Si valor no se localiza en el árbol no imprime nada
        int whatLevelAmI(int count);// O(logn) [arbol balanceado] - regresa el nivel en que se encuentra el valor
                                   //dentro del árbol. Si el valor no está en árbol regresa -1
};
#endif