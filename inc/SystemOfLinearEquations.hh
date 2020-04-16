#pragma once

#include <iostream>
#include "Vector.hh"
#include "Matrix.hh"
#include "Size.hh"

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class SystemOfLinearEquations
{
  Matrix matrix;
  Vector vector;
  Vector solution;
  Vector error;

public:
/* przeciazenia operatorow "strumieniowych" */
friend std::istream &operator>>(std::istream &stream, 
                          SystemOfLinearEquations &system);
friend std::ostream &operator<<(std::ostream &stream,
                         const SystemOfLinearEquations &system);  

Vector solve();
void showSolution() const;
void countErrorVector();
void showErrorVector() const;
};
