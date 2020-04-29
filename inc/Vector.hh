#pragma once

#include <iostream>

///////////////////////////////////////////////////////////////////
///////////////* Szablon klasy dla wektora *///////////////////////
///////////////////////////////////////////////////////////////////
template <typename T, int SIZE>
class Vector
{
/* wspolrzedne wektora */
  T coordinates[SIZE];

public:
/* przeciazenia nawiasow do indeksowania */
  const T &operator[](int index) const;
  T &operator[](int index);
/* przeciazenia operatorow dzialan na wektorach */
  Vector<T, SIZE> operator+(Vector<T, SIZE> vec2) const;
  Vector<T, SIZE> operator-(Vector<T, SIZE> vec2) const;
  T operator*(Vector<T, SIZE> vec2) const;
  Vector<T, SIZE> operator*(T arg);
  Vector<T, SIZE> operator/(T arg);
/* dlugosc wektora */
  double length() const;
};



///////////////////////////////////////////////////////////////////
////////////////////////* ciala metod *////////////////////////////
///////////////////////////////////////////////////////////////////

/* Operator indeksowania wektora.
 * Argument:
 *      index - nr indeksu - 1.
 * Zwraca:
 *      wartosc danego indeksu wektora
 * 
 * Wersja const
 */
template <typename T, int SIZE>
const T &Vector<T, SIZE>::operator[](int index) const
{
  if (index < 0 || index >= SIZE)
  {
    std::cerr << "Warning! Vector index out of range" << std::endl;
  }
  return coordinates[index];
}
/* Wersja nie-const
 */
template <typename T, int SIZE>
T &Vector<T, SIZE>::operator[](int index)
{
  return const_cast<T &>(const_cast<const Vector<T, SIZE> *>(this)->operator[](index));
}



/* Realizuje dodawanie wektorow.
 * Argumenty:
 *    niejawny wskaznik na klase Vector - pierwszy skladnik dodawania,
 *    vec2 - drugi skladnik dodawania.
 * Zwraca:
 *    result - suma argumentow.
 */
template <typename T, int SIZE>
Vector<T, SIZE> Vector<T, SIZE>::operator+(Vector<T, SIZE> vec2) const
{
  for (int i = 0; i < SIZE; i++)
  {
    vec2[i] += coordinates[i];
  }

  return vec2;
}



/* Realizuje odejmowanie wektorow.
 * Argumenty:
 *    niejawny wskaznik na klase Vector - pierwszy skladnik odejmowania,
 *    vec2 - drugi skladnik odejmowania.
 * Zwraca:
 *    result - roznica argumentow.
 */
template <typename T, int SIZE> 
Vector<T, SIZE> Vector<T, SIZE>::operator-(Vector<T, SIZE> vec2) const
{
  for (int i = 0; i < SIZE; i++)
  {
    vec2[i] -= coordinates[i];
    vec2[i] *= -1;
  }

  return vec2;
}



/* Realizuje mnozenie skalarne wektorow.
 * Argumenty:
 *    niejawny wskaznik na klase Vector - pierwszy skladnik mnozenia,
 *    vec2 - drugi skladnik mnozenia.
 * Zwraca:
 *    result - iloczyn skalarny wektorow.
 */
template <typename T, int SIZE>
T Vector<T, SIZE>::operator*(Vector<T, SIZE> vec2) const
{
  T result = 0;

  for (int i = 0; i < SIZE; i++)
  {
    result += coordinates[i] * vec2[i];
  }

  return result;
}



/* Realizuje mnozenie wektora przez liczbe.
 * Argumenty:
 *    niejawny wskaznik na klase Vector - pierwszy skladnik mnozenia,
 *    arg - drugi skladnik mnozenia.
 * Zwraca:
 *    result - wektor przemnozony przez wartosc arg.
 */
template <typename T, int SIZE>
Vector<T, SIZE> Vector<T, SIZE>::operator*(T arg)
{
  Vector<T, SIZE> result;

  for (int i = 0; i < SIZE; i++)
  {
    result[i] = coordinates[i] * arg;
  }

  return result;
}



/* Realizuje dzielenie wektora przez liczbe.
 * Argumenty:
 *    niejawny wskaznik na klase Vector - pierwszy skladnik dzielenia,
 *    arg - drugi skladnik dzielenia.
 * Zwraca:
 *    result - wektor podzielony przez wartosc arg.
 * Uwaga:
 *    w przypadku arg=0 zwraca wejsciowy wektor
 */
template <typename T, int SIZE>
Vector<T, SIZE> Vector<T, SIZE>::operator/(T arg)
{
  Vector<T, SIZE> result;

  if (arg == 0.0)
  {
    std::cerr << "[!] Cannot divide by zero." << std::endl;
    arg = 1;
  }

  for (int i = 0; i < SIZE; i++)
  {
    result[i] = coordinates[i] / arg;
  }

  return result;
}



///////////////////////////////////////////////////////////////////
///////////* przeciazenia operatorow "strumieniowych" *////////////
///////////////////////////////////////////////////////////////////

/* Realizuje wczytywanie wartosci wspolrzednych wektora
 * ze standardowego wejscia.
 * Argumenty:
 *    stream - input stream,
 *    vec - wektor.
 * Uwaga:
 *    wartosci wspolrzednych wektora (vec.coordinates[])
 *    moga byc tylko liczbami
 */
template <typename T, int SIZE>
std::istream &operator>>(std::istream &stream, Vector<T, SIZE> &vec)
{
  for (int i = 0; i < SIZE; i++)
  {
    stream >> vec[i];
    if (stream.fail())
    {
      stream.clear();
      stream.ignore(32767, '\n');
      std::cerr << "[!] Vector error." << std::endl;
      return stream;
    }
  }

  return stream;
}



/* Realizuje wyswietlnie wspolrzednych wektora na ekranie.
 * Argumenty:
 *    stream - output stream,
 *    vec - wektor.
 * Uwaga:
 *    wartosci wspolrzednych wektora (vec.coordinates[])
 *    moga byc tylko liczbami
 */
template <typename T, int SIZE>
std::ostream &operator<<(std::ostream &stream, const Vector<T, SIZE> &vec)
{
  std::cout << "(";
  for (int i = 0; i < SIZE; i++)
  {
    stream << vec[i];
    if (i < SIZE - 1)
    {
      std::cout << ", ";
    }
  }
  stream << ")" << std::endl;

  return stream;
}