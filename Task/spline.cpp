
#include "spline.h"
#include "math.h"

void spline::build_spline(void){
    //задаем сплайн как N кубических полиномов в виде
    //spline[hi] = ai + bi*hi + ci*hi^2 + di*hi^3, где hi = si - s(i-1)
    double spline[N];
    spline[0] = h[0] = 0; //граничные условия
    spline[N-1] = h[N-1] ;
    for (int i = 1; i < N; i++) {
        h[i] = s[i] - s[i-1];
        spline[i] = s[i];
    }
    for (int i = 0; i < N; i++) {
        a[i] = spline[i];
    }
    //Метод прогонки для 3х диагональной матрицы
    //создание матрицы и задание прогоночных коэффициентов
    double alfa[N], beta[N]; //прогоночные коэффициенты
    alfa[1] = 0; beta[1] = s[N-1];
    double A[N], B[N], C[N], F[N];


    for (int i = 0; i < N-1; i++) {
        A[i] = h[i];
        B[i] = h[i-1];
        C[i] = 2 * ( h[i] + h[i+1]);
        F[i] = 3 * ((a[i+1]-a[i])/h[i+1] - (a[i]-a[i-1])/h[i]);
        if (i != 0) {
            alfa[i + 1] = -B[i] / (A[i] * alfa[i] + C[i]);
            beta[i + 1] = (F[i] - A[i] * beta[i]) / (A[i] * alfa[i] + C[i]);
        }
    }
    //нахождение коэффициентов при h^2
    for (int i = 0; i <= N-1; i++) {
        c[i] = alfa[i+1]*C[i+1]+beta[i+1];
    }
    //нахождение коэффициентов при h^3
    for (int i = 0; i < N-1; i++) {
        d[i] = (c[i+1]-c[i])/(3*h[i]);
    }
    d[N-1] = -c[N-1]/(3*h[N-1]);
    //нахождение коэффициентов при h
    for (int i = 1; i <= N-1; i++) {
        b[i] = (y[i]-y[i-1])/(h[i]) - (h[i]/3)*(c[i+1]+2*c[i]);
    }


}



double * spline::get_absciss() {
    build_spline();
    integral();
    return x;
}



double spline::derivative (int i){
    return (3 * d[i] * pow(h[i],2) + c[i] * h[i] + b[i]); // dy/ds
}

double spline::f(int i) {
    return sqrt(1 - pow(derivative(i),2));
}

void spline::integral(void){ //используем обобщенную формулу Симпсона для вычисления интеграла от sqrt(1+dy/ds^2) ds
    int sum = 0;
    for (int i = 2; i < 2*N; i+=2) { // x = ((b-a)/6*N) * (f(x0) +4* f(x1) + 2*f(x2)
        sum += f(i-2);
        sum += 4 * f(i-1);
        sum += f(i);
        x[i/2] = i/12/N;
    }
}

spline::spline() {}

