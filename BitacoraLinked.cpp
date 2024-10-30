// Diego Ivan Rodriguez Nunez A01644772
// Luis Andres Casillas Casillas A01645008
// Ali Lopez Sarabia A01645060
// Act 2.3 - Act 2.3 - Actividad Integral estructura de datos lineales (Evidencia Competencia)
// 09/10/2024
// Programación de estructuras de datos y algoritmos fundamentales (Gpo 603)

#include "BitacoraLinked.h"
#include <iostream>
#include <fstream>
#include <sstream> // Para std::istringstream   
#include <ctime> // Para std::tm, std::mktime

// este constructor inicializa las rutas de los archivos de entrada y salida, luego llama a fileToVector para cargar los datos
BitacoraLinked::BitacoraLinked(std::string inputFile, std::string outputFile){   
    this->inputFile = inputFile;                                                 
    this->outputFile = outputFile;

    fileToVector();
}

// esta función lee el archivo y almacena los datos en la LinkedList
void BitacoraLinked::fileToVector(){
    std::ifstream inFile(this->inputFile);
    if(!inFile){
        std::cerr<<"Error opening file"<<std::endl;
    }
    std::string line;
    while(std::getline(inFile, line)){
        this->BitacoraLinkedList.insertLast(line); // insterta cada línea en la LinkedList
    }
    inFile.close();

}

// este metodo recorre la lista enlazada y escribe cada uno de sus elementos en el archivo
void BitacoraLinked::listToFile(){
    std::ofstream outFile(this->outputFile); 
    if (!outFile) { 
        std::cerr << "Error creating file!" << std::endl;
    }
    outFile<<BitacoraLinkedList<<std::endl;
    outFile.close();
}

// metodo encargado de guardar en un archivo las líneas que corresponden al rango de IPs especificado
void BitacoraLinked::ipToFile(std::string ipInicio, std::string ipFin, std::string ArchivoBusqueda) {
   
    
    std::ofstream outFile(ArchivoBusqueda);
    if (!outFile) {
        std::cerr << "Error opening file: " << ArchivoBusqueda << std::endl;
        return;
    }
    // escribe las líneas que están dentro del rango de IPs en el archivo
    outFile << BitacoraLinkedList.getIPs(ipInicio, ipFin) << std::endl;
    outFile.close();
}

// llama a la funcion mergesort implementada en la linked list para que bitacora no tenga acceso a los nodos
void BitacoraLinked::mergesort(){
    BitacoraLinkedList.mergesort();
}