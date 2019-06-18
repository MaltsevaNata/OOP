#include <iostream>
#include <clocale>
#include "spline.h"

using namespace std;

int main() {
    setlocale(LC_CTYPE, "rus");
    auto spl = new spline();
    cout <<"количество узлов N = "<< N << endl;
    double * x; //абсциссы узлов

    double s[N] = {0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9}; //дуговая координата
    double y[N] = {0, 1.013, 1.552, 1.364, 0.539, -0.539, -1.364, -1.552, -1.013, 0}; //ордината

    /*double s = 0.0; //дуговые координаты
    for (int counter = 0; counter < N; counter ++) {
        spl->s[counter] = s; //задание массива s дуговых координат
        spl->y[counter] = s/4; //задание ординат y
        s += 1.1;
    }*/

    for (int counter = 0; counter < N; counter ++) {
        spl->y[counter] = y[counter]; //ордината
        spl->s[counter] = s[counter]; //дуговая координата
    }

    x = spl->get_absciss(); //нахождение абсцисс узлов
    for (int counter = 0; counter < N; counter ++) {
        cout<<"x["<<counter<<"] = "<<x[counter]<< endl; //вывод на экран
    }
    cout<< endl; //вывод на экран
    for (int counter = 0; counter < N; counter ++) {
        cout<<"y["<<counter<<"] = "<<spl->y[counter]<< endl; //вывод на экран
    }
    return 0;
}

