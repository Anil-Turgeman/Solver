#include <iostream>
#include <string>
#include <complex>
#include <cmath>
using namespace std;

namespace solver{
    class RealVariable{
        public:
            double a;
            double b;
            double c;

            RealVariable(): a(0), b(1), c(0){}
            RealVariable(int a, double b, double c): a(a), b(b), c(c){}

            friend RealVariable operator+(double y, const RealVariable& x);
            friend RealVariable operator+(const RealVariable& x, double y);
            friend RealVariable operator+(const RealVariable& x, const RealVariable& y);
            friend RealVariable operator-(const RealVariable& x, double y);
            friend RealVariable operator-(const RealVariable& x, const RealVariable& y);
            friend RealVariable operator-(double y, const RealVariable& x);
            friend RealVariable operator*(double y, const RealVariable& x);
            friend RealVariable operator*(const RealVariable& x, double y);
            friend RealVariable operator*(const RealVariable& x, const RealVariable& y);
            friend RealVariable operator/(const RealVariable& x, double y);
            friend RealVariable operator/(double y, const RealVariable& x);
            friend RealVariable operator/(const RealVariable& x, const RealVariable& y);
            friend RealVariable operator==(const RealVariable& x, double y); 
            friend RealVariable operator==(const RealVariable& x, const RealVariable& y);
            friend RealVariable operator==(double y, const RealVariable& x);
            friend RealVariable operator^(const RealVariable& x, int y);
        };

    double solve(const RealVariable& x);

    class ComplexVariable{
        public:
            complex<double> a;
            complex<double> b;
            complex<double> c;

            ComplexVariable(): a(0), b(1), c(0){}
            ComplexVariable(complex<double> a, complex<double> b, complex<double> c): a(a), b(b), c(c){}

            friend ComplexVariable operator+(double y, const ComplexVariable& x);
            friend ComplexVariable operator+(const ComplexVariable& x, double y);
            friend ComplexVariable operator+(const ComplexVariable& x, const ComplexVariable& y);
            friend ComplexVariable operator+(complex<double> y, const ComplexVariable& x);
            friend ComplexVariable operator+(const ComplexVariable& x, std::complex<double> y);
            friend ComplexVariable operator-(const ComplexVariable& x, double y);
            friend ComplexVariable operator-(const ComplexVariable& x, const ComplexVariable& y);
            friend ComplexVariable operator-(double y, const ComplexVariable& x);
            friend ComplexVariable operator*(double y, const ComplexVariable& x);
            friend ComplexVariable operator*(const ComplexVariable& x, double y);
            friend ComplexVariable operator*(const ComplexVariable& x, const ComplexVariable& y);
            friend ComplexVariable operator/(const ComplexVariable& x, double y);
            friend ComplexVariable operator/(double y, const ComplexVariable& x);
            friend ComplexVariable operator/(const ComplexVariable& x, const ComplexVariable& y);
            friend ComplexVariable operator==(const ComplexVariable& x, double y); 
            friend ComplexVariable operator==(const ComplexVariable& x, const ComplexVariable& y);
            friend ComplexVariable operator==(double y, const ComplexVariable& x);
            friend ComplexVariable operator==(const ComplexVariable& x, complex<double> y);
            friend ComplexVariable operator==(complex<double> y, const ComplexVariable& x);
            friend ComplexVariable operator^(const ComplexVariable& x, int y);

    };
        
        complex<double> solve(const ComplexVariable& x);

}