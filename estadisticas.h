#ifndef ESTADISTICAS_H
#define ESTADISTICAS_H
#include <vector>

double calcularMedia(const std::vector<double>& datos);

double calcularVarianza(
    const std::vector<double>& datos,
    double media
);

double calcularDesviacion(double varianza);

double calcularMediana(std::vector<double> datos);

std::vector<double> calcularModa(
    std::vector<double> datos
);

double calcularMinimo(
    const std::vector<double>& datos
);

double calcularMaximo(
    const std::vector<double>& datos
);

double calcularCoeficienteVariacion(
    double desviacion,
    double media
);

double calcularMediaArmonica(
    const std::vector<double>& datos
);

double calcularMediaGeometrica(
    const std::vector<double>& datos
);

#endif