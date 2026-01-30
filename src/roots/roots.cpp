#include "roots.hpp"
#include <iostream>
bool bisection(std::function<double(double)> f,
               double a, double b,
               double *root) {
                if (f(a) * f(b) > 0) {
                    return false;
                }
                double c = (a + b) / 2;
                if (abs(f(c)) <= 1.0e-6){
                    *root = c;
                    return true;}
                else {
                    if (f(a) * f(c) > 0){
                        return bisection(f,c,b,root);}
                    else {
                        return bisection(f,a,c,root);}
                }
               }

//First check if F(a) and F(b) are opposite signs
//Then define the variable c based on given formula
//If f(c) = 0 then it is the root 
//If f(c) is not 0 then replace one of the endoints with the new midpoint c
            
bool regula_falsi(std::function<double(double)> f,
                  double a, double b,
                  double *root) {
    if (f(a) * f(b) > 0) {
        return false;}
    double c = a - ((f(a) * (b - a)) / (f(b) - f(a)));
    while ((std::abs(f(c)) > 1.0e-6)) {
        c = a - ((f(a) * (b - a)) / (f(b) - f(a)));
        if (f(a) * f(c) < 0) {
            b = c;}
        else {
            a = c;}
}
    *root = c;
    return true;
}   


//First check if F(a) and F(b) are opposite signs
//Then define the variable c
//If f(c) = 0 then it is the root 
//If f(c) is not 0 then replace one of the endoints with the new midpoint c
//we cannot use return fxn because in this case the function will exceed the stack data

                  
bool newton_raphson(std::function<double(double)> f,
                    std::function<double(double)> g,
                    double a, double b, double c,
                    double *root) {
                        double d = c - (f(c)/g(c));
                        if (abs(f(c)) <= 1.0e-6){
                            *root = c;
                            return true;}
                        else{
                            return newton_raphson(f,g,a,b,d,root);
                        }
                        }

//define the variable d which is the newton algorithm
//if f(c) = 0 then the root is found and if not the rerun the function with d instead of c



bool secant(std::function<double(double)> f,
            double a, double b, double c,
            double *root) {
                double d = c + 1;
                double e = d - ((f(d))*(d-c)/((f(d)-f(c))));
            while (abs(f(d)) > 1.0e-6){
                e = d - ((f(d))*(d-c)/((f(d)-f(c))));
                d = e;
            }
        *root = d;
        return true;
               
}

//define the variable d which is Xn and c is Xn-1
//define e which is the secant algorithm
//check if d is the root and if it is not the replace d with e and rerun the function 

