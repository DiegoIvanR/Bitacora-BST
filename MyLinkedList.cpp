// Diego Ivan Rodriguez Nunez A01644772
// Luis Andres Casillas Casillas A01645008
// Ali Lopez Sarabia A01645060
// Act 2.3 - Act 2.3 - Actividad Integral estructura de datos lineales (Evidencia Competencia)
// 09/10/2024
// Programación de estructuras de datos y algoritmos fundamentales (Gpo 603)

#include "MyLinkedList.h"
#include <stdexcept>

bool operator<(string data1, string data2) {
    // Función auxiliar para extraer los números entre los puntos (.) de las IPs
    auto extractNum = [](string& data, int& pos) -> int {
        string str = "";
        while (pos < data.size() && data[pos] != '.' && data[pos] != ':') {
            str.push_back(data[pos]);  // Agrega el dígito a la cadena str
            pos++;  // Avanza al siguiente carácter
        }
        pos++;  // Salta el punto/colon para el siguiente segmento
        return atoi(str.c_str());  // Convierte la cadena en número entero
    };

    int x = 0;  // Índice para data1
    int y = 0;  // Índice para data2
    int times;
    if (data2.find(':') == std::string::npos) {
        times = 5;  // Si no hay puerto en data2, se comparan 5 segmentos
    } else {
        times = 4;  // Si hay puerto, se comparan 4 segmentos
    }
    for (int i = 0; i < times; i++) {
        int ip1 = extractNum(data1, x);  // Extrae el número de data1
        int ip2 = extractNum(data2, y);  // Extrae el número de data2
        
        if (ip1 < ip2) {
            return true;  // data1 es menor que data2
        } else if (ip1 > ip2) {
            return false;  // data1 es mayor que data2
        }
        // Si los números extraídos son iguales, continúa con la siguiente parte de la IP
    }
    return false;  // Si todos los segmentos son iguales, data1 no es menor que data2
}

MyLinkedList::MyLinkedList() {
    this->size = 0;
    this->head = this->tail = nullptr;
}

MyLinkedList::~MyLinkedList() {
    MyNodoLL* current = head;
    // Elimina todos los nodos de la lista para liberar memoria
    while (current != nullptr) {
        MyNodoLL* next = current->next;
        delete current;
        current = next;
    }
}

int MyLinkedList::length() {
    return this->size;
}

bool MyLinkedList::isEmpty() {
    return this->size == 0;
}

string MyLinkedList::first() {
    if (this->size > 0) {
        return this->head->data;
    } else {
        throw std::invalid_argument("No se puede regresar el primer elemento de una lista vacía");
    }
}

string MyLinkedList::last() {
    if (this->size > 0) {
        return this->tail->data;
    } else {
        throw std::invalid_argument("No se puede regresar el último elemento de una lista vacía");
    }
}

void MyLinkedList::insertFirst(string data) {
    MyNodoLL* nodo = new MyNodoLL(data, this->head);  // Crea un nuevo nodo al inicio
    if (this->tail == nullptr) {
        this->tail = nodo;  // Si la lista estaba vacía, el nuevo nodo es también el tail
    }
    this->head = nodo;
    this->size++;
}

void MyLinkedList::insertLast(string data) {
    MyNodoLL* nodo = new MyNodoLL(data, nullptr);  // Crea un nuevo nodo al final

    if (this->tail == nullptr) {
        this->head = nodo;  // Si la lista estaba vacía, el nuevo nodo es el head
    } else {
        this->tail->next = nodo;  // El último nodo apunta al nuevo nodo
    }
    this->tail = nodo;
    this->size++;
}

void MyLinkedList::removeFirst() {
    if (this->size > 0) {
        MyNodoLL* tmp = this->head;
        this->head = this->head->next;
        delete tmp;  // Libera la memoria del nodo eliminado
        this->size--;
        if (this->size == 0) {
            this->tail = nullptr;  // Si la lista queda vacía, tail también debe ser nullptr
        }
    } else {
        throw std::invalid_argument("No se puede borrar el primer elemento de una lista vacía");
    }
}

void MyLinkedList::insertAt(int pos, string data) {
    if (pos > 0 && pos <= this->size) {
        MyNodoLL* current = this->head;
        for (int i = 0; i < pos - 1; i++) {
            current = current->next;
        }
        MyNodoLL* nodo = new MyNodoLL(data, current->next);  // Inserta en la posición indicada
        current->next = nodo;
        this->size++;
    } else if (pos == 0) {
        insertFirst(data);  // Si la posición es 0, se inserta al inicio
    } else {
        throw std::invalid_argument("La posición a insertar está fuera de rango");
    }
}

void MyLinkedList::removeLast() {
    if (this->size > 1) {
        MyNodoLL* tmp = this->head;
        for (int i = 0; i < size - 2; i++) {
            tmp = tmp->next;
        }
        MyNodoLL* newTail = tmp;
        tmp = tmp->next;
        delete tmp;  // Elimina el último nodo
        newTail->next = nullptr;
        this->tail = newTail;
        this->size--;
    } else if (this->size == 1) {
        delete this->head;  // Si solo hay un nodo, se elimina y la lista queda vacía
        this->head = this->tail = nullptr;
        this->size--;
    } else {
        throw std::invalid_argument("No se puede eliminar el último valor de una lista vacía");
    }
}

void MyLinkedList::removeAt(int pos) {
    if (pos == 0) {
        removeFirst();  // Si es la posición 0, se elimina el primer nodo
    } else if (pos > 0 && pos < this->size) {
        MyNodoLL* tmp = this->head;
        for (int i = 0; i < pos - 1; i++) {
            tmp = tmp->next;
        }
        MyNodoLL* beforeNode = tmp;
        tmp = tmp->next;
        beforeNode->next = tmp->next;
        delete tmp;  // Elimina el nodo en la posición especificada
        this->size--;
    } else {
        throw std::invalid_argument("La posición está fuera de rango");
    }
}

string MyLinkedList::getAt(int pos) {
    if (pos >= 0 && pos < this->size) {
        MyNodoLL* nodo = this->head;
        for (int i = 0; i < pos; i++) {
            nodo = nodo->next;
        }
        return nodo->data;
    } else {
        throw std::invalid_argument("No se puede acceder al valor, fuera de rango");
    }
}

ostream& operator<<(ostream& os, const MyLinkedList& ll) {
    MyNodoLL* current = ll.head;
    // Recorre la lista enlazada y envía los datos al flujo de salida
    while (current != nullptr) {
        os << current->data;
        if (current->next != nullptr) {
            os << "\n";  // Agrega un salto de línea entre elementos
        }
        current = current->next;
    }
    return os;
}

void MyLinkedList::mezcla(MyNodoLL* head, MyNodoLL* middle, int leftSize, int rightSize) {
    int totalSize = leftSize + rightSize;
    MyNodoLL* current = head;
    string* datosTmp = new string[totalSize];  // Arreglo temporal para almacenar los datos mezclados

    int i = 0, j = 0, k = 0;

    // Comparación y mezcla de las dos mitades
    while (i < leftSize && j < rightSize) {
        if (extractIPandPort(head->data) < extractIPandPort(middle->data)) {
            datosTmp[k++] = head->data;
            head = head->next;
            i++;
        } else {
            datosTmp[k++] = middle->data;
            middle = middle->next;
            j++;
        }
    }

    // Si quedan elementos en la mitad izquierda
    while (i < leftSize) {
        datosTmp[k++] = head->data;
        head = head->next;
        i++;
    }

    // Si quedan elementos en la mitad derecha
    while (j < rightSize) {
        datosTmp[k++] = middle->data;
        middle = middle->next;
        j++;
    }

    // Se copian los elementos mezclados a la lista enlazada
    for (int m = 0; m < totalSize; m++) {
        current->data = datosTmp[m];
        current = current->next;
    }
    delete[] datosTmp;
}

void MyLinkedList::mergesort(MyNodoLL* head, int size) {
    if (size > 1) {
        int middleIndex = size / 2;
        MyNodoLL* middle = head;
        // Encuentra el nodo en la mitad de la lista
        for (int i = 0; i < middleIndex; i++) {
            middle = middle->next;
        }

        int leftSize = middleIndex;
        int rightSize = size - middleIndex;

        // Llama recursivamente a mergesort en cada mitad
        mergesort(head, leftSize);
        mergesort(middle, rightSize);

        // Mezcla las dos mitades
        mezcla(head, middle, leftSize, rightSize);
    }
}

void MyLinkedList::mergesort() {
    mergesort(this->head, this->size);  // Llama a mergesort sobre la lista completa
}

string MyLinkedList::extractIPandPort(const string& data) {
    stringstream ss(data);
    string line;

    getline(ss, line, ' '); // Mes 
    getline(ss, line, ' '); // Día
    getline(ss, line, ' '); // Hora
    getline(ss, line, ' '); // Ip

    return line;  // Retorna la Ip limpia
}

string MyLinkedList::extractIP(const string& data) {
    int start = 15;
    int end = data.find(":", start);

    if (end == string::npos) {
        end = data.find(" ", start);
    }

    string ip = data.substr(start, end - start);

    if (!ip.empty() && ip[0] == ' ') {
        ip.erase(0, 1);
    }

    return ip;
}

string MyLinkedList::getIPs(string ipInicio, string ipFin) {
    MyNodoLL* current = this->head;  // Comienza desde el primer nodo
    string ip;
    string str = "";
    // Recorre la lista enlazada y obtiene las IPs dentro del rango
    while (current != nullptr) {
        ip = extractIP(current->data);
        if ((ipInicio < ip && ip < ipFin) || ip == ipInicio || ip == ipFin) {
            str.append(current->data + "\n");
        }
        current = current->next;
    }
    return str;  // Retorna las IPs encontradas en el rango
}