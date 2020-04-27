#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>
#include "Vector.hh"
#include "Matrix.hh"
#define ERR 0.000000001

///////////////////////////////////////////////////////////////////
////////////* Szablon klasy dla ukladu rownan *////////////////////
///////////////////////////////////////////////////////////////////
template <typename T, int SIZE>
class SystemOfLinearEquations
{
  Matrix<T, SIZE> matrix;
  Vector<T, SIZE> vector;
  Vector<T, SIZE> solution;
  Vector<T, SIZE> error;

public:
  Vector<T, SIZE> solve();
  void showSolution() const;
  void countErrorVector();
  /* do pobierania danych prywatnych */
  Matrix<T, SIZE> getMatrix() const { return matrix; };
  Vector<T, SIZE> getVector() const { return vector; };
  Vector<T, SIZE> getSolution() const { return solution; };
  Vector<T, SIZE> getError() const { return error; };

  friend std::istream &operator>>(std::istream &stream,
                                  SystemOfLinearEquations<T, SIZE> &system)
  {
    stream >> system.matrix;
    stream >> system.vector;

    return stream;
  }
  friend std::ostream &operator<<(std::ostream &stream,
                                  SystemOfLinearEquations<T, SIZE> &system)
  {
    for (int i = 0; i < SIZE; i++)
    {
      std::cout << "|";
      for (int j = 0; j < SIZE; j++)
      {
        std::cout << std::setw(4) << system.getMatrix()(i, j) << " ";
      }
      std::cout << "||x" << i + 1 << "|";
      if (SIZE % 2 == 1)
      {
        if (i == SIZE / 2)
        {
          std::cout << " = "
                    << "|" << std::setw(4) << system.getVector()[i] << " |";
        }
        else
        {
          std::cout << "   "
                    << "|" << std::setw(4) << system.getVector()[i] << " |";
        }
      }
      else if ((i == SIZE / 2) || (i == SIZE / 2 - 1))
      {
        std::cout << " - "
                  << "|" << std::setw(4) << system.getVector()[i] << " |";
      }
      else
      {
        std::cout << "   "
                  << "|" << std::setw(4) << system.getVector()[i] << " |";
      }
      std::cout << std::endl;
    }

    return stream;
  }
};

///////////////////////////////////////////////////////////////////
////////////////////////* ciala metod *////////////////////////////
///////////////////////////////////////////////////////////////////

/* Realizuje rozwiazywanie ukladu rownan
 * Argumenty:
 *    w domysle uklad rownan
 * Uwaga:
 *    jezeli wyznacznik macierzy glownej jest rowny 0,
 *    program nie jest w stanie wyliczyc ukladu,
 *    bo bazuje na metodzie Cramera
 */
using std::abs;
template <typename T, int SIZE>
Vector<T, SIZE> SystemOfLinearEquations<T, SIZE>::solve()
{
  SystemOfLinearEquations<T, SIZE> copy = *this;
  Matrix<T, SIZE> temp;
  T mainDeterminant = copy.matrix.determinant();

  if (abs(mainDeterminant) < ERR)
  {
    std::cerr << "[!] Determinant = 0. Cannot solve the system." << std::endl;
  }

  for (int i = 0; i < SIZE; i++)
  {
    temp = copy.matrix;
    temp[i] = copy.vector;
    this->solution[i] = temp.determinant() / mainDeterminant;
  }
  return this->solution;
}

/* Wyswietla rozwiazania ukladu rownan */
template <typename T, int SIZE>
void SystemOfLinearEquations<T, SIZE>::showSolution() const
{
  for (int i = 0; i < SIZE; i++)
  {
    std::cout << "x" << i + 1 << " = " << this->solution[i] << std::endl;
  }
}

/* Realizuje obliczenie wektora bledu */
template <typename T, int SIZE>
void SystemOfLinearEquations<T, SIZE>::countErrorVector()
{
  this->error = this->matrix * this->solution - this->vector;
}

