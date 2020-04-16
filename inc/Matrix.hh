#pragma once

#include "Size.hh"
#include <iostream>
#include "Vector.hh"

template <typename T, int SIZE>
class Matrix
{
  /* macierz kwadratowa przedstawiona w postaci tablicy wektorow (kolumn)
   * SIZE wektorow SIZE-wymiarowych*/
  Vector<T, SIZE>  data[SIZE];

public:
/* przeciazenia nawiasow do indeksowania */
  const T &operator()(int row, int column) const;
  T &operator()(int row, int column);
/* do wyciagania kolumn macierzy */
  Vector<T, SIZE>  &operator[](int index);

/* przeciazenia operatorow "strumieniowych" */
  friend std::istream &operator>>(std::istream &stream, Matrix<T, SIZE> &matrix);
  friend std::ostream &operator<<(std::ostream &stream, const Matrix<T, SIZE>  &matrix);

/* obliczanie wyznacznika macierzy */
  double determinant() const;
/* mnozenie macierzy przez wektor */
  Vector<T, SIZE>  operator*(Vector<T, SIZE>  vec) const;
/* Hadamard */
  Matrix<T, SIZE>  hadamard(const Matrix<T, SIZE>  &arg) const;
};

