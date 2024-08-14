#include <bits/stdc++.h>
using namespace std;

class Complex {
    float real,imag;

    public : 
        Complex(): real(0),imag(0) {}

        complex(float r,float i): real(r),imag(i) {}

        void display(){
            cout<<real<<"+"<<imag<<"i"<<endl;
        }

        Complex add(const Complex &c){
            return Complex(real + c.real, imag + c.imag);
        }

        Complex add(float r){
            return Complex(real + r,imag);
        }

        Complex operator +(Complex &c){
            return Complex(real+c.real,imag.c.imag);
        }

        Complex operator + (float r){
            return Complex(real + r,imag);
        }

        Complex operator + (float r, const Complex &c){
            return Complex(c.real + r,c.imag);
        }
}
int main(){
    Complex c1(3.5, 2.5), c2(1.5, 4.5);
    c1.display();
    c2.display();

    Complex c3 = c1.add(c2);
    Complex c4 = c1.add(4.0);
    c3.display();
    c4.display();

    Complex c5 = c1 + c2;
    Complex c6 = c1 + 2.0;
    Complex c7 = 2.0 + c1;
    c5.display();
    c6.display();
    c7.display();
     return 0;
}