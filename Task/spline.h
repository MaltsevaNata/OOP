#include <iostream>
#include "math.h"
#define N 10 //количество равноотстоящийх узлов


class spline {
private:
    double dy[N]; // dy/ds
    double x[N]; //абсциссы узлов
    double h[N]; //массив отрезков si - s(i-1)
    double a[N]; // свободные члены сплайнов
    double b[N]; //коэффициенты при h
    double c[N]; //коэффициенты при h^2
    double d[N]; //коэффициенты при h^3
    double f(int i); //функция для вычисления интеграла по формуле Симпсона
    double derivative (int i);
    void integral(void);
    void build_spline(void);
public:
    spline();
   // ~spline();
    double y[N]; //функция, которую задает пользователь
    double s[N]; //дуговая координата
    double * get_absciss(void);
};

