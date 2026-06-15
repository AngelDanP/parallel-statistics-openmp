#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <omp.h>
#include "estadisticas.h"


using namespace std;



int main()
{

    const int N = 1000000;


    vector<double> datos(N);


    srand(123);


    for (int i = 0; i < N; i++)
    {
        datos[i] = (rand() % 100000) + 1;
    }



    int hilos = omp_get_max_threads();

    omp_set_num_threads(hilos);



    auto inicio =
        chrono::high_resolution_clock::now();



    double media =
        calcularMedia(datos);


    double varianza =
        calcularVarianza(datos, media);


    double desviacion =
        calcularDesviacion(varianza);



    double mediana =
        calcularMediana(datos);



    vector<double> modas =
        calcularModa(datos);



    double minimo =
        calcularMinimo(datos);


    double maximo =
        calcularMaximo(datos);



    double coef =
        calcularCoeficienteVariacion(
            desviacion,
            media
        );



    double armonica =
        calcularMediaArmonica(datos);



    double geometrica =
        calcularMediaGeometrica(datos);




    auto fin =
        chrono::high_resolution_clock::now();



    double tiempo =
        chrono::duration<double, milli>
        (fin - inicio).count();



    cout << "===== ESTADISTICA OPENMP =====\n\n";


    cout << "Datos: "
        << N << endl;


    cout << "Hilos usados: "
        << hilos << endl;


    cout << "Media: "
        << media << endl;


    cout << "Mediana: "
        << mediana << endl;



    cout << "Moda: ";

    for (double m : modas)
    {
        cout << m << " ";
    }

    cout << endl;



    cout << "Varianza: "
        << varianza << endl;


    cout << "Desviacion: "
        << desviacion << endl;


    cout << "Minimo: "
        << minimo << endl;


    cout << "Maximo: "
        << maximo << endl;


    cout << "Coeficiente variacion: "
        << coef << endl;


    cout << "Media armonica: "
        << armonica << endl;


    cout << "Media geometrica: "
        << geometrica << endl;


    cout << "Tiempo ejecucion: "
        << tiempo
        << " ms"
        << endl;


    return 0;
}