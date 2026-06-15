# Parallel Statistics OpenMP

Statistical analysis program developed in **C++** using **OpenMP** for parallel computing.

This project calculates different statistical measures from a large dataset and applies parallel processing techniques to improve execution performance.

## Features

- Arithmetic mean
- Median
- Mode calculation
- Variance
- Standard deviation
- Minimum and maximum values
- Coefficient of variation
- Harmonic mean
- Geometric mean
- Execution time measurement
- Multi-thread processing with OpenMP

## Technologies

- C++
- OpenMP
- STL (Standard Template Library)

## Project Structure

```
parallel-statistics-openmp/

├── main.cpp
├── estadisticas.cpp
├── estadisticas.h
└── README.md
```

## Concepts Demonstrated

- Parallel programming with OpenMP
- C++ modular code organization
- Use of STL containers and algorithms
- Data processing optimization
- Performance measurement

## Compilation

Compile the project using:

```bash
g++ main.cpp estadisticas.cpp -fopenmp -o statistics
```

## Execution

Windows:

```bash
statistics.exe
```

Linux / macOS:

```bash
./statistics
```

## Example Output

```
===== ESTADISTICA OPENMP =====

Datos: 1000000
Hilos usados: 8

Media: 50021.45
Mediana: 50032
Moda: 12345

Varianza: 833421234.22
Desviacion: 28869.39

Tiempo ejecucion: 120.54 ms
```
<img width="336" height="253" alt="OMP" src="https://github.com/user-attachments/assets/739383fc-c731-4f82-9a7d-ad51e26b735c" />


## Español

Programa de análisis estadístico desarrollado en **C++** utilizando **OpenMP** para procesamiento paralelo.

El proyecto calcula diferentes medidas estadísticas sobre grandes cantidades de datos aplicando técnicas de paralelización para mejorar el rendimiento.

Incluye cálculo de media, mediana, moda, varianza, desviación estándar, valores mínimos y máximos, coeficiente de variación, media armónica y media geométrica.
