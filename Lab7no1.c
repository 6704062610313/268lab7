#include<stdio.h>

double functionM(void);
int functionN(int n, double x);
double functionO(double, int, double, int);
double functionP(int a, int n, int b, int c);

int main(){
    int a = 0, b = 0, c = 0, d = 0, e = 0;
    double r = 0.0, s = 0.0, t = 0.0, u = 0.0, v = 0.0;

    // Function calling (a-k)
    
    printf("%lf\n", functionM());  // Works without issues
    a = functionM();               // Works, but double will be cast to int (decimal part truncated)
    printf("a = functionM() = %d\n", a);

    b = functionN(a, b);           // Works, but since 'b' is an int, decimal results may be truncated
    printf("b = functionN(a, b); = %d\n", b);

    r = functionO(r, a, s, b);     // Works without issues
    printf("r = functionO(r, a, s, b); = %lf\n", r);

    // s = functionP(a, b, c, d, e); // ERROR: Too many arguments compared to the function prototype
    printf("s = functionP(a, b, c, d, e); = %lf\n", s);

    u = functionM();               // Works without issues
    printf("u = functionM(); = %lf\n", u);

    c = d + functionN(r, s);       // Works, but returns an int; argument types differ from parameters (implicit casting)
    printf("c = d + functionN(r, s); = %d\n", c);

    t = s * functionO(r, a, r, a); // Works without issues
    printf("t = s * functionO(r, a, r, a); = %lf\n", t);

    a = v + functionP(r, s, t, t); // Works, but parameters are int; decimals in r, s, t will be truncated
    printf("a = v + functionP(r, s, t, t); = %d\n", a);

    // Works, but arguments s, t, r are doubles being passed to int parameters (casting occurs)
    printf("functionP(functionN(a, a), s, t, t + r); = %lf\n", functionP(functionN(a, a), s, t, t + r));

    v = functionP(functionN(a, a), s, t, t + r);
    printf("v = functionP(functionN(a, a), s, t, t + r); = %lf\n", v); // Works, but double arguments will be cast to int
}

double functionM(void){
    double ans = 1+1;
    return ans; 
}

int functionN(int n, double x){
    return n+x;
}

double functionO(double a, int b, double c, int d){
    return a+b+c+d;
}

double functionP(int a, int n, int b, int c){
    return a*n*b*c;
}
