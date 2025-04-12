# Análisis comparativo de eficiencia: Evaluación de polinomios.

## Descripción
Este proyecto evalúa la eficiencia de dos métodos para calcular el valor de un polinomio: el método estándar término a término y el método de Horner. A través de experimentos prácticos y análisis teórico, se compara el desempeño de ambos enfoques en términos de tiempos de ejecución y número de operaciones realizadas.

## Autor
David Armando Angulo Gil

## Requisitos del Sistema
Las específicaciones del sistema con las que se hicieron pruebas fueron las siguientes:
- **Procesador: Intel Core i7-1185G7**
- **Memoria RAM: 16GB**
- **Tarjeta Gráfica: Intel Iris XE Graphics**
- **Sistema Operativo: Windows 11 Pro**
- **Compilador:** g++

## Instrucciones de Compilación y Ejecución
1. Compilar el código utilizando el siguiente comando en la terminal:
   ```bash
   g++ -o evaluacionPolinomios evaluacionPolinomios.cpp
2. Ejecutar el programa con el siguiente comando:
   ```bash
   ./evaluacionPolinomios

# Descripción de los Algoritmos

## Método Estándar
El método estándar evalúa un polinomio sumando término a término. Para cada término, calcula el valor de:
$$a_i \cdot x^i$$
donde $$a_i$$ es el coeficiente del término y $$x^i$$ es la potencia correspondiente.

## Método de Horner
El método de Horner es una técnica más eficiente que reescribe el polinomio en una forma factorizada, reduciendo el número de multiplicaciones necesarias:
$$P(x) = ((a_n x + a_{n-1}) x + a_{n-2}) \dots x + a_0$$

## Resultados Experimentales y Gráfica Comparativa
1. Gráfica del método estándar
![imagen](https://github.com/user-attachments/assets/6bc2026a-c7f6-4736-944d-60345a245531)

2. Gráfica del método de Horner
![imagen](https://github.com/user-attachments/assets/06123d95-7a0f-490a-8704-0b65affd7c5b)

3. Comparación gráfica entre ambos métodos
![imagen](https://github.com/user-attachments/assets/bc344e4f-75d1-46bb-8ba0-71e31111e0bd)



## Análisis de Resultados
- **Rendimiento**: El método de Horner muestra tiempos de ejecución significativamente más bajos en comparación con el método estándar.
- **Complejidad**: La complejidad teórica del método estándar es $$O(n^2)$$ mientras que la de Horner es $$O(n)$$, lo que explica la diferencia observada.
- **Escalabilidad**: A medida que aumenta el grado del polinomio, la ventaja del método de Horner se vuelve más evidente debido a su menor número de operaciones.

## Conclusiones
El método de Horner es más eficiente para evaluar polinomios, especialmente cuando el grado del polinomio es alto. Su estructura optimizada reduce el tiempo de ejecución y el costo computacional en comparación con el enfoque estándar término a término.
