#include "estadisticas.h"
#include <algorithm>
#include <cmath>
#include <omp.h>


double calcularMedia(const std::vector<double>& datos)
{
    double suma = 0;

#pragma omp parallel for reduction(+:suma)
    for (int i = 0; i < datos.size(); i++)
    {
        suma += datos[i];
    }

    return suma / datos.size();
}



double calcularVarianza(
    const std::vector<double>& datos,
    double media
)
{
    double suma = 0;

#pragma omp parallel for reduction(+:suma)
    for (int i = 0; i < datos.size(); i++)
    {
        suma += (datos[i] - media) *
            (datos[i] - media);
    }

    return suma / datos.size();
}



double calcularDesviacion(double varianza)
{
    return sqrt(varianza);
}



double calcularMediana(std::vector<double> datos)
{
    sort(datos.begin(), datos.end());

    int n = datos.size();

    if (n % 2 == 0)
    {
        return (datos[n / 2 - 1] + datos[n / 2]) / 2.0;
    }
    else
    {
        return datos[n / 2];
    }
}



std::vector<double> calcularModa(
    std::vector<double> datos
)
{
    sort(datos.begin(), datos.end());

    std::vector<double> modas;

    int maxFrecuencia = 0;
    int frecuencia = 1;


    for (int i = 1; i < datos.size(); i++)
    {
        if (datos[i] == datos[i - 1])
        {
            frecuencia++;
        }
        else
        {
            if (frecuencia > maxFrecuencia)
            {
                maxFrecuencia = frecuencia;
                modas.clear();
                modas.push_back(datos[i - 1]);
            }
            else if (frecuencia == maxFrecuencia)
            {
                modas.push_back(datos[i - 1]);
            }

            frecuencia = 1;
        }
    }


    if (frecuencia > maxFrecuencia)
    {
        modas.clear();
        modas.push_back(datos.back());
    }
    else if (frecuencia == maxFrecuencia)
    {
        modas.push_back(datos.back());
    }


    return modas;
}



double calcularMinimo(
    const std::vector<double>& datos
)
{
    return *min_element(datos.begin(), datos.end());
}



double calcularMaximo(
    const std::vector<double>& datos
)
{
    return *max_element(datos.begin(), datos.end());
}



double calcularCoeficienteVariacion(
    double desviacion,
    double media
)
{
    return desviacion / media;
}



double calcularMediaArmonica(
    const std::vector<double>& datos
)
{
    double suma = 0;


#pragma omp parallel for reduction(+:suma)
    for (int i = 0; i < datos.size(); i++)
    {
        suma += 1.0 / datos[i];
    }


    return datos.size() / suma;
}



double calcularMediaGeometrica(
    const std::vector<double>& datos
)
{
    double suma = 0;


#pragma omp parallel for reduction(+:suma)
    for (int i = 0; i < datos.size(); i++)
    {
        suma += log(datos[i]);
    }


    return exp(suma / datos.size());
}