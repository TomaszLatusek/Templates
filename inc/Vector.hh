#pragma once

#include "Size.hh"
#include <iostream>

template <typename T, int SIZE>
class Vector
{
  /* wspolrzedne wektora */
  T coordinates[SIZE];

public:
/* przeciazenia operatorow dzialan na wektorach */
  Vector<T, SIZE> operator+(Vector<T, SIZE> vec2) const;
  Vector<T, SIZE> operator-(Vector<T, SIZE> vec2) const;
  T operator*(Vector<T, SIZE> vec2) const;
  Vector<T, SIZE> operator*(T arg);
  Vector<T, SIZE> operator/(T arg);
/* przeciazenia nawiasow do indeksowania */
  const T &operator[](int index) const;
  T &operator[](int index);
/* przeciazenia operatorow "strumieniowych" */
  friend std::istream &operator>>(std::istream &stream, Vector<T, SIZE> &vec);
  friend std::ostream &operator<<(std::ostream &stream, const Vector<T, SIZE> &vec);
/* dlugosc wektora */
  double length() const;
};

