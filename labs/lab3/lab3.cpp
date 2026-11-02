#include <iostream>   // Подключение библиотеки ввода-вывода
#include <iomanip>    // Подключение манипуляторов форматирования (setw, fixed, setprecision)
#include <cmath>      // Подключение математических функций (exp, fabs)

using namespace std;

// Функция вычисления суммы ряда для заданного n слагаемых (арифметический цикл)
double calculateSN(double x, int n) {
    double sum = 1.0;    // Нулевой член при i = 0 равен 1 ((0^2 + 1) * (x/2)^0 / 0! = 1)
    double term_c = 1.0; // Рекуррентный множитель c_i = (x/2)^i / i!

    for (int i = 1; i <= n; i++) {
        term_c *= (x / (2.0 * i));            // Рекуррентный пересчет c_i
        double a_i = (i * i + 1.0) * term_c;  // Вычисление слагаемого ряда: a_i = (i^2 + 1) * c_i
        sum += a_i;
    }
    return sum;
}

// Функция вычисления суммы ряда с заданной точностью eps (итерационный цикл)
double calculateSE(double x, double eps) {
    double sum = 1.0;    // Начальное слагаемое a_0 = 1
    double term_c = 1.0;
    int i = 1;
    double a_i = 0.0;

    do {
        term_c *= (x / (2.0 * i));            // Рекуррентный шаг
        a_i = (i * i + 1.0) * term_c;         // Текущий член ряда
        sum += a_i;
        i++;
    } while (fabs(a_i) >= eps);               // Суммируем, пока слагаемое не станет меньше заданной точности

    return sum;
}

// Функция вычисления точного значения функции по формуле
double calculateY(double x) {
    return (x * x / 4.0 + x / 2.0 + 1.0) * exp(x / 2.0);
}

int main() {
    const double a = 0.1;        // Левая граница интервала
    const double b = 1.0;        // Правая граница интервала
    const int k = 10;            // Количество шагов
    const int n = 30;            // Количество слагаемых для SN
    const double eps = 0.0001;   // Точность ε = 10^-4
    const double step = (b - a) / k; // Шаг h = (1.0 - 0.1) / 10 = 0.09

    cout << "========================================================================\n";
    cout << "                          Вычисление функции                            \n";
    cout << "========================================================================\n";
    cout << setw(10) << "X" 
         << setw(16) << "SN" 
         << setw(16) << "SE" 
         << setw(16) << "Y" << "\n";
    cout << "------------------------------------------------------------------------\n";
    cout << fixed << setprecision(6);

    for (double x = a; x <= b + step / 2.0; x += step) {
        double sn = calculateSN(x, n);
        double se = calculateSE(x, eps);
        double y  = calculateY(x);

        cout << setw(10) << x
             << setw(16) << sn
             << setw(16) << se
             << setw(16) << y << "\n";
    }

    cout << "========================================================================\n";
    return 0;
}