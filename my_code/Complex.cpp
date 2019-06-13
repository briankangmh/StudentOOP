#include <iostream>
#include <istream>
#include <iomanip>
#include "Complex.h"

using namespace std;

ostream& operator<< (ostream& os, const Complex& c) {
    /*
     * Outputting a `Complex` instance, while illustrating some of the
     * capabilities of I/O streams: `setprecision` gives us a fixed
     * number of decimal places, while `showpos` turns on the plus
     * sign for positive numbers.
     * */
    os << setprecision(3) << "Real: " << c.real << " Imag: " << showpos << c.imag << noshowpos;
    return os;
}

Complex::Complex(double real, double imag) : real(real), imag(imag){}

/*
 * Read a `Complex` number from an input stream.
 * */
istream& operator>> (istream& is, Complex& c) {
    is >> c.real >> c.imag;
    return is;
}


Complex::operator bool() const {
    if (real != 0 || imag != 0){
        return true;
    }
    return false;
}

Complex& Complex::operator++() {
    real++;
    return *this;
}

Complex Complex::operator++(int dummy) {
//    double prevreal = real;
//    double previmag = imag;
    Complex old(real, imag);
    real++;
    return old;
}

Complex Complex::operator--(int dummy) {
    //    double prevreal = real;
    //    double previmag = imag;
    Complex old(real, imag);
    real--;
    return old;
}

Complex& Complex::operator--() {
    real--;
    return *this;
}

Complex operator+(const Complex& c1, const Complex& c2){
    double newreal = c1.get_real() + c2.get_real();
    double newimag = c1.get_imag() + c2.get_imag();
    Complex newcomplex(newreal, newimag);
    return newcomplex;
}

Complex operator-(const Complex& c1, const Complex& c2){
    double newreal = c1.get_real() - c2.get_real();
    double newimag = c1.get_imag() - c2.get_imag();
    Complex newcomplex(newreal, newimag);
    return newcomplex;
}

Complex Complex::operator -=(const Complex& rhs){
    real -= rhs.get_real();
    imag -= rhs.get_imag();
    return *this;
}

double Complex::get_real() const {
    return real;
}
//
double Complex::get_imag() const {
    return imag;
}
//
Complex Complex::operator*(const int i) {
    return Complex(i * real, i * imag);
}

bool operator == (const Complex& c1, const Complex& c2){
    if (c1.get_imag() == c2.get_imag()){
        if (c1.get_real() == c2.get_real()){
            return true;
        }
    }
    return false;
}
bool operator != (const Complex& c1, const Complex& c2){
    if (c1.get_imag() - c2.get_imag() < 0.0001){
        if (c1.get_real() - c2.get_real() < 0.0001){
            return false;
        }
    }
    return true;
}
