// Diego Ivan Rodriguez Nunez A01644772
// Este programa contiene una estructura de datos
// BST implementada en una clase llamada MyBST

#include "MyBST.h"

// Constructor default para el BST
MyBST::MyBST(){
    this->size = 0;
    this->root = nullptr;
}

// O(1) - regresa el numero de nodos en el arbol
int MyBST::length(){
    return this->size; //size contiene el numero de nodos actual
}

// O(n) - regresa la altura maxima del arbol
int MyBST::height(MyNodeBST* node) {
    if (node == nullptr) { // caso base
        return 0;
    }
    int leftHeight = height(node->left);   // de manera recursiva calcula la altura del arbol izquierdo
    int rightHeight = height(node->right); // de manera recursiva calcula la altura del arbol derecho
    return max(leftHeight, rightHeight) + 1; // altura maxima de entre los dos hijos, mas el actual
}

// O(n) - funcion de preparacion para regresar la altura del BST.
int MyBST::height(){
    return height(this->root); // comienza con la raiz
}

// O(1) - checa si esta vacio (true / false)
bool MyBST::isEmpty(){
    return this->size == 0;
}

// O(logn)[si está balanceado] - busca recursivamente el dato, retorna si lo encuentra o no
bool MyBST::search(int data, MyNodeBST *current){
    if(current == nullptr){ // caso base: no se encuentra en la hoja
        return false;
    }
    if(current->data == data){ // caso base: si se encuentra en la hoja actual
        return true;
    } else{
        current = data < current->data ? current->left : current->right; //operador ternario para buscar en el hijo derecho o izquierdo
    }
    return search(data, current); // busca reursivamente
}

// O(logn)[arbol balanceado] - Funcion de preparacion para busqueda recursiva
bool MyBST::search(int data){
    return search(data, this->root); // comienza a buscar en la raiz
}

//O(logn)[arbol balanceado] - true si lo inserto o no
bool MyBST::insert(int data){
    MyNodeBST* current = this->root; // comienza con la raiz
    if(current == nullptr){
        this->root = new MyNodeBST(data); // si no hay raiz (nullptr), insertar en la raiz
        this->size++;
        return true; // insercion exitosa
    }
    while(true){ // recorre iterativamente hasta llegar a la hoja donde se deberia insertar
        // si ya existe, retornar falso
        if (current->data == data){ 
            MyNodeBST* node = new MyNodeBST(data);
            node->right = current->right;
            current->right = node;
            return true;
        }  
        // si el padre no tiene a la hoja del dato, insertar el dato
        else if (current->left == nullptr && data < current->data){
            MyNodeBST* leaf = new MyNodeBST(data);
            current->left = leaf;
            this->size++;
            return true;
        } 
        // si el padre no tiene a la hoja del dato, insertar el dato
        else if (current->right == nullptr && data > current->data){
            MyNodeBST* leaf = new MyNodeBST(data);
            current->right = leaf;
            this->size++;
            return true;
        } else{
            // de no haber llegado a una capa antes de las hojas o encontrar el dato, seguir buscando
            current = data < current->data ? current->left : current->right; //operador ternario
        }
    }
}

// O(n) - imprime los datos del arbol (actual-izquierda-derecha)
void MyBST::preorder(MyNodeBST* current){
    if (current == nullptr){ // caso base, se llego al final de la rama
        return;
    }
    else{
        cout<<current->data<<","; // imprimir el actual
        preorder(current->left); // recorrer rama izquierda
        preorder(current->right); // recorrer rama derecha
    }
}

// O(n) - funcion de preparacion para imprimr el arbol recursivamente
void MyBST::preorder(){
    preorder(this->root);
    cout<<endl;
}

// O(n) - imprime los datos del arbol(izquierda-actual-derecha)
void MyBST::inorder(MyNodeBST* current){
    if(current == nullptr){ // caso base, se llego al final de la rama
        return;
    } else{
        inorder(current->right); // recorrer la rama izquierda
        cout<<current->data<<","; // imprimir el actual
        inorder(current->left); // recorrer la rama derecha
    }
}

// O(n) - funcion de preparacion para imprimr el arbol recursivamente
void MyBST::inorder(){
    inorder(this->root);
    cout<<endl;
}

// O(n) - imprime los datos del (izquierda-derecha-actual)
void MyBST::postorder(MyNodeBST* current){
    if(current == nullptr){ // caso base, se llego al final de la rama
        return;
    } else{
        postorder(current->left); // recorrer la rama izquierda
        postorder(current->right); // recorrer la rama derecha
        cout<<current->data<<","; // imprimir el actual
    }
}

// O(n) - funcion de preparacion para imprimr el arbol recursivamente
void MyBST::postorder(){
    postorder(this->root);
    cout<<endl;
}

// O(logn)[arbol balanceado] - imprime los ancestros del valor pasado separados por comas y sin dejar espacios entre ellos.
void MyBST::ancestors(int data){
    MyNodeBST* current = this->root; // comienza en la raiz
    string anc = ""; // string para almacenar los datos de los ancestros
    while(current!=nullptr){ // si se llega al final, terminar y no imprimir nada
        if (current->data == data){ // si el dato se encuentra, imprimir los ancestros
            cout<<anc + to_string(current->data) + ","<<endl;
            break;
        }
        else{ // agregar el valor actual (posible ancestro) y buscar iterativamente el dato
            anc = anc + to_string(current->data) + ",";
            current = data < current->data ? current->left : current->right; //operador ternario
        }
    }
}

// O(logn) [arbol balanceado] - regresa el nivel en que se encuentra el valor
int MyBST::whatLevelAmI(int data){
    MyNodeBST* current = this->root; // comienza en la raiz
    int tmpLevel = 0; // contador temporal de nivel
    while(current!=nullptr){
        if (current->data == data){ // si se encuentra el dato
            return tmpLevel;        // regresar el nivel actual
            break;
        }
        else{ // si aun no se encuentra el dato, buscar iterativamente y aumentar el nivel
            tmpLevel++;
            current = data < current->data ? current->left : current->right; //operador ternario
        }
    }
    return -1; // no se encontro el dato
}

// O(n) - imprime el arbol a lo BFS (por niveles) de manera iterativa
void MyBST::level() {
    if (this->size == 0) { // si no hay ningun dato, terminar
        return;
    }

    MyNodeBST* current;
    MyNodeBST** array = new MyNodeBST*[this->size]; // array para ir almacenando a los hijos que se visitaran
    array[0] = this->root; // agregar la raiz como primer elemento
    int index = 0; // index para saber donde insertar el siguiente hijo

    for (int i = 0; i < this->size; i++) {
        current = array[i];
        cout << current->data << ","; // imprime el nodo actual

        // de tener un hijo izquierdo, lo agrega al array para imprimirlo despues
        if (current->left != nullptr) {
            index++;
            array[index] = current->left;
        }

        // de tener un hijo derecho, lo agrega al array para imprimirlo despues
        if (current->right != nullptr) {
            index++;
            array[index] = current->right;
        }
    }

    cout << endl;
    delete[] array; // libera la memoria
}

// Inspirado en el libro Estructuras de datos y algoritmos fundamentales por Salinas, G. González, L. de la Cueva, V.
// O(logn)[si está balanceado] - borra el nodo del dato especificado
MyNodeBST* MyBST::remove(MyNodeBST* current, int data){
    if(current == nullptr){  // caso base, no se modifica nada
        return nullptr;
    } else if (data<current->data){ // busca el dato a eliminar a la izquierda
        // cuando se elimina un nodo, esta linea nos ayuda a asignar el nuevo hijo, sino, se mantiene igual
        current->left = remove(current->left, data);
    } else if (data>current->data){ // busca el dato a eleminar a la derecha
        // cuando se elimina un nodo, esta linea nos ayuda a asignar el nuevo hijo, sino, se mantiene igual
        current->right = remove(current->right, data);
    } else { // si se encuentra el dato a eliminar
        MyNodeBST* tmp = current;
        if(tmp->left == nullptr){
            // de no tener un hijo a la izquierda podemos asignarle al padre los hijos de la derecha, current ahora apunta a ese nodo (y si no tiene hijos a la derecha, se vuelve nullptr)
            current = tmp->right;
        } else if(tmp->right == nullptr){
            // de no tener un hijo a la derecha podemos asignarle al padre los hijos de la izquierda, current ahora apunta a ese nodo
            current = tmp->left;
        } else{
            // de tener ambos hijos, debe reemplazar el nodo con el mayor de los menores
            tmp = replace(tmp);
        }
        delete tmp; // borra el nodo
    }    
    return current; // regresa el nodo al cual el padre del eliminado debe de apuntar ahora (puede ser nullptr)
}

// O(n), donde n es la longitud de la rama de mayores del menor - reemplaza el dato por el mayor de los menores si es un nodo con ambos hijos
MyNodeBST* MyBST::replace(MyNodeBST* deleteNode){
    MyNodeBST *mostRight, // crea dos apuntadores a nodos, uno para saber cual es el mayor de los menores
              *parentRight; // el otro para saber cual es su "padre"
    parentRight = deleteNode; // inicialmente apunta al nodo actual, puede ser el caso que solo tenga un menor
    mostRight = deleteNode->left; // comenzamos buscando en la rama de los menores
    while (mostRight->right != nullptr){ // busca el ultimo de la rama de los menores del menor, el  mayor de los menores
        parentRight = mostRight; // actualiza los apuntadores
        mostRight = mostRight->right;
    }
    deleteNode->data = mostRight->data; // reemplazamos el dato del nodo a eliminar con el nodo del mayor de los menores
    if(parentRight == deleteNode){ // si el nodo a eliminar solo tenia un hijo a la izquierda, y de ese ninguno a la derecha
        parentRight->left = mostRight->left; // apuntar a los nodos de la izquierda, pues no hay nodos a la derecha de ese
    } else{
        parentRight->right = mostRight->left; // sino, como ya no hay elementos a la derecha del mayor,
        // pero pueden haber mas nodos a la izquierda del mayor, el "padre" apunta ahora a esos nodos de la izquierda (puede ser nullptr)
    }
    return mostRight; // regresa a donde tiene que apuntar el padre del nombre a eliminar, es decir, el menor de los mayores en su nueva pos.
}

// O(logn)[arbol balanceado] - si el valor estaba en el árbol lo borra y regresa true, de lo contrario regresa false
// como search y remove recursivo tienen la misma complejidad,
// y search se realiza antes de remove recursivo, no adentro de,
// la complejidad de bool remove se queda con el mayor de ambos
// y, al ser la misma, queda O(logn)
bool MyBST::remove(int data){
    if(!search(data)){ // busca el dato
        return false; // si no esta, no lo puede borrar
    }
    
    this->size--; // reduce la cuenta de nodos que hay
    remove(this->root, data); // remover el nodo de forma iterativa
    return true; // si el dato si se encontraba, siempre lo elimina
}

// Type: 1->preorder,2->inorder.3->postorder,4->level
// Imprime el recorrido separado por comas sin espacio entre los elementos.
void MyBST::visit(int type){
    switch(type) { // input del usuario
        case 1:
            preorder(); // recorre el arbol en preorden
            break;
        case 2:
            inorder(); // recorre el arbol en inorden
            break;
        case 3:
            postorder(); // recorre el arbol en postorden
            break;
        case 4:
            level(); // recorre el arbol por niveles
            break;
    }
}
