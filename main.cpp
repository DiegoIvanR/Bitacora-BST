//g++ *.cpp -o salida.exe

// Diego Ivan Rodriguez Nunez A01644772
// Bernardo Santiago Marín A01638915
// Monserrat Morales Cáñez A01638959
// Act 2.3 - Act 2.3 - Actividad Integral estructura de datos lineales (Evidencia Competencia)

// Programación de estructuras de datos y algoritmos fundamentales (Gpo 603)

/*Este programa agarra un archivo de bitácora y mete sus registros en una lista enlazada. Luego, 
ordena esos registros usando las direcciones IP, comparando cada parte de la IP, y si son iguales, 
usa el puerto para desempatar. El programa te pide que ingreses dos IPs (una de inicio y otra de fin), 
y con eso busca los registros que están en ese rango. Los resultados de cada búsqueda se guardan en 
archivos de salida, y no te los muestra en pantalla. También te deja hacer varias búsquedas si quieres, 
preguntándote si quieres seguir buscando después de cada una.
*/

#include "BitacoraLinked.h"
#include "MyBST.h"
#include <iostream>
#include <limits>
#include <string>

int main(){
    MyBST bst;
    std::string inputFile = "bitacora.txt";
    std::string outputFile = "bitacoraOrdenadaIP-Eq3.txt";
    BitacoraLinked bitacora(inputFile, outputFile); // se instancia BitacoraLinked para cargar y ordenar los datos de la bitacora
    bitacora.mergesort();
    bitacora.listToFile();
    std::string ipInicio, ipFin;

    // Pedir al usuario que ingrese las IPs de inicio y fin
    // Comentar desde aquí para deshabilitar
     /*

    int count = 1; 
    char otraBusqueda;
    std::cout << " Quieres realizar una busqueda de IPs? (Y/N): "; // se quitan los acentos por futuros problemas como caracteres no reconocidos 
    std::cin >> otraBusqueda;

    while (otraBusqueda == 'Y') { // este while permite que el usuario realice varias busquedas, siempre y cuando lo desee tecleando Y
        std::cout << "Escribe la IP de inicio (formato ###.###.###.###): ";
        std::cin >> ipInicio;

        std::cout << "Introduce la IP de fin (formato ###.###.###.###): ";
        std::cin >> ipFin;
        std::string archivoBusq = "salida" + std::to_string(count) + "-Eq3.txt";
        bitacora.ipToFile(ipInicio, ipFin, archivoBusq);
        count++;

        std::cout << " Quieres realizar otra busqueda de IP? (Y/N): ";    // pregunta al usuario si quiere hacer otra búsqueda
        std::cin >> otraBusqueda;
    }

    // Fin búsqueda de IPs
     */ 

     // Buscar las IPs con más frecuencia en la Bitácora ordenada
    return 0;
}