#include <iostream>
using namespace std;

struct VW{ // composição/agregação de dados
    double massa;
    double altura;
    int idade;
    char sexo;
};

double imc(VW &x, int ano){
    double res = x.massa / (x.altura * x.altura);
    return res;
}

class ZY{
    public:
        double massa;
        double altura;
        int idade;
        char sexo;
        double imc(int ano){
            double res = massa / (altura * altura);
            return res;
        }
};

int main(){
    VW ex = {70.0, 1.75, 30, 'M'};
    double i = imc(ex, 2026);

    ZY ex2 = {70.0, 1.75, 30, 'M'};
    double j = ex2.imc(2026);

    cout << "IMC do VW: " << i << endl;
    cout << "IMC do ZY: " << j << endl;
    return 0;
}