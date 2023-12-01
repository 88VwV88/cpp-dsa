#include<iostream>
#include<complex>
#include<cassert>

int main() {
    const std::complex a{ 1.0, 2.0 }, b{ a*a };
    assert(b.imag() == (2.0*a.imag()*a.real()));
}

