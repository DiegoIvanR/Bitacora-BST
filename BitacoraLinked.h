// Diego Ivan Rodriguez Nunez A01644772
// Luis Andres Casillas Casillas A01645008
// Ali Lopez Sarabia A01645060
// Act 2.3 - Act 2.3 - Actividad Integral estructura de datos lineales (Evidencia Competencia)
// 09/10/2024
// Programación de estructuras de datos y algoritmos fundamentales (Gpo 603)

#ifndef BITACORALINKED_H
#define BITACORALINKED_H
#include <vector>
#include <string>
#include <iomanip>
#include "MyLinkedList.h"
using namespace std;

// La clase BitacoraLinked maneja una bitácora almacenada en una lista enlazada (MyLinkedList)
// Ofrece métodos para leer los datos desde un archivo (fileToVector), 
// guardar los datos de la lista en un archivo (vectorToFile), buscar y extraer registros
// dentro de un rango de IPs (ipToFile), y ordenar la bitácora con MergeSort (mergesort)
// Toda la gestión de los datos se hace usando la clase MyLinkedList.



class BitacoraLinked{
    private:
    MyLinkedList BitacoraLinkedList;
    string inputFile;
    string outputFile;
    void fileToVector(); // O(n)
    
    public:
    BitacoraLinked(string inputFile, string outputFile);
    void vectorToFile(); // O(n)
    void ipToFile(string ipInicio, string ipFin, string ArchivoBusqueda); // O(n)
    void mergesort(); // O(nlog(n))
    
};


#endif