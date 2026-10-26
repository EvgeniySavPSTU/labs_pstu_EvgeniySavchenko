#include <iostream> // Подключаем библиотеку для вывода текста на экран
#include <iomanip>

using namespace std;

int main() {
    

    // Задаем исходные данные по условию задачи (вариант 20)
    float a = 100.0;
    float b = 0.001;

    

    // Считаем числитель по частям, чтобы не запутаться
    float chisl_1 = (a - b) * (a - b) * (a - b) * (a - b); // первая часть числителя
    float chisl_2 = (a * a * a * a) - (4 * a * a * a * b);  // вторая часть числителя
    float chislitel_f = chisl_1 - chisl_2;                 // весь числитель целиком

    // Считаем знаменатель по частям
    float znam_1 = 6 * a * a * b * b;                       // первое слагаемое
    float znam_2 = 4 * a * b * b * b;                       // второе слагаемое
    float znam_3 = b * b * b * b;                           // третье слагаемое
    float znamenatel_f = znam_1 - znam_2 - znam_3;          // весь знаменатель целиком

    // Делим числитель на знаменатель
    float otvet_f = chislitel_f / znamenatel_f;
    cout<< fixed<< setprecision(15);
    cout << "float: " << otvet_f << endl;


    

    // Делаем то же самое, но с типом double для большей точности
    double a_d = 100.0;
    double b_d = 0.001;

    double chisl_1_d = (a_d - b_d) * (a_d - b_d) * (a_d - b_d) * (a_d - b_d);
    double chisl_2_d = (a_d * a_d * a_d * a_d) - (4 * a_d * a_d * a_d * b_d);
    double chislitel_d = chisl_1_d - chisl_2_d;

    double znam_1_d = 6 * a_d * a_d * b_d * b_d;
    double znam_2_d = 4 * a_d * b_d * b_d * b_d;
    double znam_3_d = b_d * b_d * b_d * b_d;
    double znamenatel_d = znam_1_d - znam_2_d - znam_3_d;

    double otvet_d = chislitel_d / znamenatel_d;
    cout << fixed << setprecision(15);
    cout << "double: " << otvet_d << endl;

    return 0; // Завершаем программу
}
