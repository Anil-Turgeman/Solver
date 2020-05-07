#include "solver.hpp"
#include <complex>
using namespace solver;

double solver::solve(const RealVariable& x){
   if (x.a != 0){
        if((x.b*x.b -4*x.a*x.c) > 0)
            return ((-x.b + sqrt(x.b * x.b -4*x.a*x.c)) / (2*x.a));   
        else
            throw invalid_argument("The delta is negative number");
    }else{
        if(x.b != 0)
            return (-x.c / x.b); 
        else
            throw invalid_argument("b is zero");  
    }
}

RealVariable solver::operator+(const RealVariable& x, const RealVariable& y){
    return RealVariable(x.a+y.a, x.b+y.b, x.c+y.c);
    
}

RealVariable solver::operator+(const RealVariable& x,double y){
    return  RealVariable(x.a, x.b, x.c+y);
   
}

RealVariable solver::operator+(double y,const RealVariable& x){
    return  RealVariable(x.a, x.b, x.c+y);    
}

RealVariable solver::operator-(const RealVariable& x, double y){
  return RealVariable(x.a, x.b, x.c-y);
}

RealVariable solver::operator-(double x, const RealVariable& y){
   return RealVariable(-y.a, -y.b, x-y.c);
}

RealVariable solver::operator-(const RealVariable& x, const RealVariable& y){
  return  RealVariable(x.a-y.a, x.b-y.b, x.c-y.c);
}

RealVariable solver::operator*(double x,const RealVariable& y){
    return RealVariable(x*y.a, x*y.b, y.c);
}

RealVariable solver::operator*(const RealVariable& x,const RealVariable& y){
    return RealVariable(x.a+y.a, x.b*y.b, x.c*y.c);
}

RealVariable solver::operator*(const RealVariable& y,double x){
    return RealVariable(y.a, x*y.b, y.c);
}

RealVariable solver::operator/(const RealVariable& x,double y){
  if(y!=0){
    return RealVariable(x.a, x.b/y, x.c);
  }else{
    throw invalid_argument("can't divide zero");
  }
}

RealVariable solver::operator/(const RealVariable& x,const RealVariable& y){
    return RealVariable(x.a/y.a, x.b/y.b, x.c/y.c);
}

RealVariable solver::operator/(double x,const RealVariable& y){
    if(y.b!=0){
        return RealVariable(y.a, x/y.b, y.c);
    }else{
        throw invalid_argument("you try to divide by zero");
    }
}

RealVariable solver::operator==(const RealVariable& x, const RealVariable& y) {
   return RealVariable(x.a-y.a, x.b-y.b, x.c-y.c);
}

RealVariable solver::operator==(double x, const RealVariable& y) {
    return RealVariable(-y.a, -y.b, x-y.c);
}

RealVariable solver::operator==(const RealVariable& x, double y) {
    return RealVariable(x.a, x.b, x.c-y);        
}
        
RealVariable solver::operator^(const RealVariable &x, int pow){
    if(pow == 0){
        return RealVariable(0 ,0 ,1); 
    }
    else if(pow == 1){
        return RealVariable(0 ,1 ,0);
    }
    else if(pow == 2){
        return RealVariable(1 ,0 ,0);
    }

    throw invalid_argument("the power y must be 0 <= y <= 2");
} 

///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////ComplexVariable/////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////

std::complex<double> solver::solve(const ComplexVariable& x){
   if (x.a != 0.0){
        return ((-x.b + sqrt(x.b*x.b -4.0*x.a*x.c)) / (2.0*x.a));   
    }else{
        if (x.b != 0.0)
             return (-(x.c) / x.b); 
        else
            throw invalid_argument("b is zero");  
    }
}

ComplexVariable solver::operator+(const ComplexVariable& x, const ComplexVariable& y){
    return ComplexVariable(x.a+y.a, x.b+y.b, x.c+y.c);
}

ComplexVariable solver::operator+(const ComplexVariable& x,double y){
    return ComplexVariable(x.a, x.b, x.c+y);
}

ComplexVariable solver::operator+(double y, const ComplexVariable& x){
    return ComplexVariable(x.a, x.b, x.c+y);    
}

ComplexVariable solver::operator+(std::complex<double> y, const ComplexVariable& x){
    return ComplexVariable(x.a, x.b, x.c+y);
}

ComplexVariable solver::operator+(const ComplexVariable& x, std::complex<double> y){
    return ComplexVariable(x.a , x.b , x.c+y);
}

ComplexVariable solver::operator-(const ComplexVariable& x, double y){
    return ComplexVariable(x.a, x.b, x.c-y);
}

ComplexVariable solver::operator-(double x, const ComplexVariable& y){
   return ComplexVariable(-y.a, -y.b, x-y.c);
}

ComplexVariable solver::operator-(const ComplexVariable& x,const ComplexVariable& y){
    return ComplexVariable(x.a-y.a, x.b-y.b, x.c-y.c);
}

ComplexVariable solver::operator*(double x, const ComplexVariable& y){
   return ComplexVariable(x*y.a, x*y.b, y.c);
}

ComplexVariable solver::operator*(const ComplexVariable& x, const ComplexVariable& y){
    return ComplexVariable(x.a+y.a, x.b*y.b, x.c*y.c);
}

ComplexVariable solver::operator*(const ComplexVariable& y, double x){
   return ComplexVariable(y.a, x*y.b, y.c);
}

ComplexVariable solver::operator/(const ComplexVariable& x,double y){
    if(y!=0){
        return  ComplexVariable(x.a, x.b/y, x.c);
    }else{
        throw invalid_argument("you try to divide by zero");
    }
}

ComplexVariable solver::operator/(const ComplexVariable& x, const ComplexVariable& y){
    return ComplexVariable(x.a/y.a, x.b/y.b, x.c/y.c);
}

ComplexVariable solver::operator/(double x,const ComplexVariable& y){
    if(y.b!=0.0){
        return ComplexVariable(y.a, x/y.b, y.c);
    }else{
        throw invalid_argument("you try to divide by zero");
    }
}

ComplexVariable solver::operator==(const ComplexVariable& x, const ComplexVariable& y) {
    return ComplexVariable(x.a-y.a, x.b-y.b, x.c-y.c);
}

ComplexVariable solver::operator==(double x, const ComplexVariable& y) {
    return ComplexVariable(-y.a, -y.b, x-y.c);
}

ComplexVariable solver::operator==(const ComplexVariable& x, double y) {
    return ComplexVariable(x.a, x.b, x.c-y);
}

ComplexVariable solver::operator==(const ComplexVariable& x, std::complex<double> y){
    return ComplexVariable(x.a, x.b, x.c-y);
}

ComplexVariable solver::operator==(std::complex<double> y, const ComplexVariable& x){
      return ComplexVariable(-x.a, -x.b, y-x.c);   
}

ComplexVariable solver::operator^(const ComplexVariable& x, int y){
    if(y==0){
        return ComplexVariable(0, 0, 1);
    }else if(y==1){
        return ComplexVariable(0, 1, 0);
    }else if(y==2){
        return ComplexVariable(1, 0, 0);
    }

    throw invalid_argument("the power y must be 0 <= y <= 2");
}