#pragma once
#include <iostream>

struct Complex
{
    double re; /*! Pole repezentuje czesc rzeczywista. */
    double im; /*! Pole repezentuje czesc urojona. */
};

/*
 * Zapowiedzi definicji przeciazen operatorow
 */
Complex operator+(Complex arg1, Complex arg2);
Complex operator-(Complex arg1, Complex arg2);
Complex operator*(Complex arg1, Complex arg2);
Complex operator/(Complex arg1, Complex arg2);
Complex operator-=(Complex &arg1, Complex arg2);
Complex operator+=(Complex &arg1, Complex arg2);
std::ostream &operator<<(std::ostream &os,Complex c);
std::istream &operator>>(std::istream &os,Complex &c);
bool operator==(Complex arg1, Complex arg2);
double abs(Complex arg);
Complex operator*=(Complex &arg1, Complex arg2);
Complex operator*=(Complex &arg1, double arg2);

void ShowAlert(std::istream &is, int i);