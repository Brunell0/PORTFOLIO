#include <iostream>
using namespace std;

struct MK{
    int a, b, c;
};

void f(MK x){
    cout << x.a << " " << x.b << " " << x.c << endl;
}

void g(MK *y){
    cout << y->a << " " << y->b << " " << y->c << endl;
}

void h(MK &z){
    cout << z.a << " " << z.b << " " << z.c << endl;
}

int main(){
    MK m1 = {1, 2, 3};
    f(m1);
    g(&m1);
    h(m1);
    
    return 0;
}