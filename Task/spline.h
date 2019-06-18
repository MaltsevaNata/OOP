#include <iostream>
#include <math.h>
const unsigned int N = 10; //количество равноотстоящийх узлов


class spline {
private:
    double dy[2*N]; // dy/ds
    double x[N]; //абсциссы узлов
    double h[N]; //массив отрезков si - s(i-1)
    double a[N]; // свободные члены сплайнов
    double b[N]; //коэффициенты при h
    double c[N]; //коэффициенты при h^2
    double d[N]; //коэффициенты при h^3
    double f(int i); //функция для вычисления интеграла по формуле Симпсона
    double derivative (int i); //dy/ds
    void integral();
    void build_spline();
public:
    spline(); //конструктор
    double s[N]; //дуговая координата
    double y[N]; //ордината
    double * get_absciss();
};

