/*Aclaracion a falta de acentos de algunas palabras:
Por cosas de interpretacion de los caracteres especiales de algunos compiladores, estos no se pueden llegar a mostrar
esto incluye a los acentos. Aquellos simbolos de interrogacion que pueden llegar a salir son "enies"
*/

/*
Autor: David Angulo
Fecha de elaboracion: 12 de Abril del 2025
*/
#include <cstdlib>
#include <chrono>
#include <iostream>
#include <ctime>
#include <fstream>
#include <algorithm>

#define NUM_PRUEBAS 1000 // Número de pruebas a realizar para cada tamaño de polinomio
#define MIN_TAMANO 10    // Tamaño mínimo del polinomio (grado mínimo)
#define MAX_TAMANO 1000  // Tamaño máximo del polinomio (grado máximo)
#define INCREMENTO 10    // Incremento en el tamaño del polinomio entre iteraciones

using namespace std;

// Prototipos de las funciones para evaluar polinomios
double long TerminoATermino(double long *coef, int tam, double long x);
double long ReglaDeHorner(double long *coef, int tam, double long x);

// Función para ejecutar un algoritmo de evaluación y registrar los resultados en un archivo CSV
void EjecutarYRegistrar(double long (*algoritmo)(double long*, int, double long), const string& nombreArchivo, const string& nombreAlgoritmo);

int main() {
    srand(time(nullptr)); // Inicialización de la semilla para la generación de números aleatorios
    
    // Ejecutar y registrar los resultados para ambos algoritmos
    EjecutarYRegistrar(TerminoATermino, "1_TerminoATermino_Evaluacion.csv", "Termino a Termino");
    EjecutarYRegistrar(ReglaDeHorner, "2_ReglaDeHorner_Evaluacion.csv", "Regla de Horner");
    
    cout << "Ejecucion completa. Verifique los archivos CSV generados." << endl;
    system("pause"); // Pausa para que el usuario pueda ver el mensaje antes de que el programa termine
    return 0;
}

/* Esta función se encarga de la creación de los archivos CSV, las iteraciones y la impresión de los arreglos/tiempos.
   Es el núcleo del programa, ya que coordina la ejecución de los algoritmos y el registro de los resultados. */
void EjecutarYRegistrar(double long (*algoritmo)(double long*, int, double long), const string& nombreArchivo, const string& nombreAlgoritmo) {
    ofstream archivo(nombreArchivo); // Creación del archivo CSV para registrar los resultados
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo " << nombreArchivo << endl;
        return;
    }

    // Escribir encabezados en el archivo CSV
    archivo << "Evaluacion";
    for (int tamano = MIN_TAMANO; tamano <= MAX_TAMANO; tamano += INCREMENTO) {
        archivo << ",Grado" << tamano;
    }
    archivo << endl;

    // Realizar las pruebas para cada tamaño de polinomio
    for (int i = 1; i <= NUM_PRUEBAS; ++i) {
        archivo << i; // Número de prueba
        for (int k = MIN_TAMANO; k <= MAX_TAMANO; k += INCREMENTO) {
            // Crear un arreglo de coeficientes aleatorios para el polinomio
            double long* s = new double long[k+1];
            for (int j = 0; j < k; ++j) {
                s[j] = -10 + rand() % 20; // Coeficientes aleatorios entre -10 y 10
            }

            double long x = -10 + rand() % 20; // Valor aleatorio de x para evaluar el polinomio
            
            cout << "Ejecutando " << nombreAlgoritmo << " con grado " << k << endl;

            // Medir el tiempo de ejecución del algoritmo
            auto inicio = chrono::high_resolution_clock::now();
            double long polyval = algoritmo(s, k, x);
            auto fin = chrono::high_resolution_clock::now();
            chrono::duration<double, nano> duracion = fin - inicio;

            // Imprimir el arreglo y el tiempo tomado en la primera iteración para el tamaño mínimo
            if (i == 1 && k == MIN_TAMANO) {
                cout << "\nChequeo de funcionamiento del algoritmo " << nombreAlgoritmo << endl;
                cout << "Arreglo ordenado: [";
                for (int p = 0; p < k; p++) {
                    cout << s[p] << (p < k - 1 ? ", " : "");
                }
                cout << "]" << endl;
            }

            cout << "Tiempo tomado: " << duracion.count() << "ns" << endl;
            archivo << "," << duracion.count(); // Registrar el tiempo en el archivo CSV
            
            delete[] s; // Liberar memoria del arreglo dinámico
        }
        archivo << endl; // Nueva línea en el archivo CSV para la siguiente prueba
    }
    archivo.close(); // Cerrar el archivo CSV
}

/* Algoritmo de evaluación de polinomios término a término.
   Calcula el valor del polinomio evaluando cada término individualmente. */
double long TerminoATermino(double long *coef, int tam, double long x){
    double long polyval = coef[0];
    for(int i = 0; i < tam; i++){
        double long term = coef[i];
        for(int j = 0; j < i; j++){
            term *= x; // Multiplicar por x tantas veces como el grado del término
        }
        polyval += term; // Sumar el término al resultado
    }
    return polyval;
}

/* Algoritmo de evaluación de polinomios usando la Regla de Horner.
   Es más eficiente que el método término a término, ya que reduce el número de multiplicaciones. */
double long ReglaDeHorner(double long *coef, int tam, double long x){
    double long polyval = coef[0];
    for(int i = 1; i < tam; i++){
        polyval = polyval * x + coef[i]; // Evaluación eficiente usando Horner
    }
    return polyval;
}