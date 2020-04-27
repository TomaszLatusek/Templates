#include "Complex.hh"
#include <iostream>
#include <cmath>

using namespace std;

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    arg1 - pierwszy skladnik dodawania,
 *    arg2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
Complex operator+(Complex arg1, Complex arg2)
{
    Complex result;

    result.re = arg1.re + arg2.re;
    result.im = arg1.im + arg2.im;
    return result;
}

/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    arg1 - pierwszy skladnik odejmowania,
 *    arg2 - drugi skladnik odejmowania.
 * Zwraca:
 *    roznice dwoch skladnikow przekazanych jako parametry.
 */
Complex operator-(Complex arg1, Complex arg2)
{
    Complex result;

    result.re = arg1.re - arg2.re;
    result.im = arg1.im - arg2.im;
    return result;
}

/*!
 * Realizuje mnozenie dwoch liczb zespolonych.
 * Argumenty:
 *    arg1 - pierwszy skladnik mnozenia,
 *    arg2 - drugi skladnik mnozenia.
 * Zwraca:
 *    iloczyn dwoch skladnikow przekazanych jako parametry.
 */
Complex operator*(Complex arg1, Complex arg2)
{
    Complex result;

    result.re = (arg1.re * arg2.re) - (arg1.im * arg2.im);
    result.im = (arg1.im * arg2.re) + (arg1.re * arg2.im);
    return result;
}

/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * Argumenty:
 *    arg1 - pierwszy skladnik dzielenia,
 *    arg2 - drugi skladnik dzielenia.
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */
Complex operator/(Complex arg1, Complex arg2)
{
    Complex result;

    result.re = ((arg1.re * arg2.re) + (arg1.im * arg2.im)) / ((arg2.re * arg2.re) + (arg2.im * arg2.im));
    result.im = ((arg1.im * arg2.re) - (arg1.re * arg2.im)) / ((arg2.re * arg2.re) + (arg2.im * arg2.im));
    return result;
}

/*
 * Realizuje porownanie liczb zespolonych.
 * Argumenty:
 *    arg1 - liczba pierwsza,
 *    ar2 - liczba druga.
 * Zwraca:
 *    prawda, jezeli liczby sa sobie rowne
 *    falsz, jezeli nie sa sobie rowne.
 * Uwaga:
 *    wynik nalezy wprowaadzic z dokladnoscia do 5 cyfr
 *    po przecinku
 */
bool operator==(Complex arg1, Complex arg2)
{
    double limit = 0.00001;

    if (abs(arg1.re - arg2.re) <= limit && abs(arg1.im - arg2.im) <= limit)
    {
        return true;
    }
    else
        return false;
}


/*
 * Realizuje pomniejszenie arg1 o arg2.
 * Argumenty:
 *    arg1 - liczba pierwsza,
 *    ar2 - liczba druga.
 * Zwraca:
 *    nowa wartosc arg1
 */
Complex operator-=(Complex &arg1, Complex arg2)
{
    arg1.re -= arg2.re;
    arg1.im -= arg2.im;

    return arg1;
}



/*
 * Realizuje powiekszenie arg1 o arg2.
 * Argumenty:
 *    arg1 - liczba pierwsza,
 *    ar2 - liczba druga.
 * Zwraca:
 *    nowa wartosc arg1
 */
Complex operator+=(Complex &arg1, Complex arg2)
{
    arg1.re += arg2.re;
    arg1.im += arg2.im;

    return arg1;
}



/*!Display
 * Realizuje wyswietlnie liczby zespolonej na ekranie.
 * Argumenty:
 *    os - output stream,
 *    c - liczba zesppolona.
 * Zwraca:
 *    wyswietla liczbe c na ekranie.
 */
ostream &operator<<(ostream &os, Complex c)
{
    os << "(" << c.re << showpos << c.im << noshowpos << "i)";
    return os;
}

/*!
 * Realizuje wczytywanie liczby zespolonej.
 * Argumenty:
 *    is - intput stream,
 *    c - liczba zesppolona.
 * Zwraca:
 *    wczytuje z klawiatury liczbe c.
 */
istream &operator>>(istream &is, Complex &c)
{
    int i = 0;
    char ch;

    while (i <= 3) /* 3 proby poprwnego wpisania liczby */
    {

        is >> ch;
        if (ch != '(')
        {
            ShowAlert(is, i);
            i++;
            continue;
        }

        is >> c.re;
        if (is.fail())
        {
            is.clear();
            ShowAlert(is, i);
            i++;
            continue;
        }

        is >> ch;
        if (ch != '+' && ch != '-')
        {
            ShowAlert(is, i);
            i++;
            continue;
        }

        is >> c.im;
        if (is.fail())
        {
            is.clear();
            ShowAlert(is, i);
            i++;
            continue;
        }
        else if (ch == '-')
        {
            c.im *= -1;
        }

        is >> ch;
        if (ch != 'i')
        {
            ShowAlert(is, i);
            i++;
            continue;
        }

        is >> ch;
        if (ch != ')')
        {
            ShowAlert(is, i);
            i++;
            continue;
        }
        else
            return is;
    }

    return is;
}

/* Sluzy do skrocenia
przeciazenia >> */
void ShowAlert(istream &is, int i)
{
    is.ignore(32767, '\n');
    if (i < 3)
    {
        cout << endl
             << "[!] Complex number error." << endl;
        cout << "    Try again: ";
    }
}

/*!
 * Realizuje liczenie modulu liczby zespolonej.
 * Argumenty:
 *    arg - liczba zespolona
 * Zwraca:
 *    modul arg
 */
double abs(Complex arg)
{
    return sqrt(arg.re*arg.re + arg.im*arg.im);
}

/*!
 * Realizuje pomnozenie liczby zespolonej przez 
 * inna liczbe zespolona
 * Argumenty:
 *    arg1 - liczba, ktora powiekszamy,
 *    arg2 - liczba, przez ktora mnozymy.
 * Zwraca:
 *    powiekszona liczba arg1.
 */
Complex operator*=(Complex &arg1, Complex arg2)
{   
    arg1 = arg1 * arg2;
    return arg1;
}

/*!
 * Realizuje pomnozenie liczby zespolonej przez 
 * doubla
 * Argumenty:
 *    arg1 - liczba, ktora powiekszamy,
 *    arg2 - liczba, przez ktora mnozymy.
 * Zwraca:
 *    powiekszona liczba arg1.
 */
Complex operator*=(Complex &arg1, double arg2)
{
    arg1.re *= arg2;
    arg1.im *= arg2;

    return arg1;
}
