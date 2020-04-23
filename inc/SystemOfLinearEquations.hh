#pragma once

#include <iostream>
#include <iomanip>
#include "Vector.hh"
#include "Matrix.hh"

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
  Matrix<T, SIZE> getMatrix() const{return matrix;};
  Vector<T, SIZE> getVector() const{return vector;};
  Vector<T, SIZE> getSolution() const{return solution;};
  Vector<T, SIZE> getError() const{return error;};
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
template <typename T, int SIZE>
Vector<T, SIZE> SystemOfLinearEquations<T, SIZE>::solve()
{
  SystemOfLinearEquations<T, SIZE> copy = *this;
  Matrix<T, SIZE> temp;
  T mainDeterminant = copy.matrix.determinant();

  if (mainDeterminant == 0)
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


///////////////////////////////////////////////////////////////////
///////////* przeciazenia operatorow "strumieniowych" *////////////
///////////////////////////////////////////////////////////////////

/* Realizuje wczytywanie macierzy i wektora wyrazow wolnych
 * ze standardowego wejscia.
 * Argumenty:
 *    stream - input stream,
 *    system - uklad rownan.
 * Uwaga:
 *    na wejscie nalezy podac postac transponowana macierzy
 *    z wektorem wyrazow wolnych 
 */
template <typename T, int SIZE>
std::istream &operator>>(std::istream &stream,
                         SystemOfLinearEquations<T, SIZE> &system)
{
  // Matrix<T, SIZE> m;
  // Vector<T, SIZE> v;

  stream >> system.getMatrix();
  stream >> system.getVector();

  return stream;
}

/* Realizuje wyswietlnie ukladu rownan na ekranie.
 * Argumenty:
 *    stream - output stream,
 *    system - uklad rownan.
 * Uwaga:
 *    -wyswietla macierz oryginalna, nie transponowana 
 *     jak ta podana na wejsiu,
 *    -zeby macierz zostala wyswietlona ladnie i prosto
 *     jej wyrazy powinny skladac sie z nie wiecej niz 4 znakow.
 *      
 * 
 * (kod dosc brzydki ale pierwszy raz bawie sie z formatowaniem
 * outputu, prosze o wyrozumialosc)
 */
template <typename T, int SIZE>
std::ostream &operator<<(std::ostream &stream,
                         const SystemOfLinearEquations<T, SIZE> &system)
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
