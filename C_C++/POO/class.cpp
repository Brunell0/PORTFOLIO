#include <iostream>
using namespace std;

class Date{
    public:
        int day;
        int month;
        int year;
};

int main(){
    Date d1;
    d1.day = 15;
    d1.month = 8;
    d1.year = 2024;

    cout << "Data: " << d1.day << "/" << d1.month << "/" << d1.year << endl;

    return 0;
}
