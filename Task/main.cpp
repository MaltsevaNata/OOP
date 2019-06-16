#include <iostream>
#include "spline.h"

int main() {
    auto spl = new spline();
    std::cout <<"количество узлов N = "<< N << std::endl;
    double * x; //абсциссы узлов
    double s = 0.0; //дуговые координаты
    for (int counter = 0; counter < N; counter ++) {
        spl->s[counter] = s; //задание массива s дуговых координат
        spl->y[counter] = s*4; //задание ординат y
        s += 1.1;
    }
    x = spl->get_absciss(); //нахождение абсцисс узлов
    for (int counter = 0; counter < N; counter ++) {
        std::cout<<"x["<<counter<<"] = "<<x[counter]<<std::endl; //вывод на экран
    }

    return 0;
}

