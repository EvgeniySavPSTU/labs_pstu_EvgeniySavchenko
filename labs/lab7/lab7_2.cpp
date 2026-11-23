#include <iostream>
#include <cstdarg>

// Проверка возможности построения треугольника со сторонами x, y, z
bool isTriangle(int x, int y, int z) {
    return (x > 0 && y > 0 && z > 0) &&
           (x + y > z) && (x + z > y) && (y + z > x);
}

// Функция с переменным числом параметров:
// count — количество переданных далее целочисленных длин сторон
int triangle(int count, ...) {
    if (count < 3) {
        return 0;
    }

    va_list args;
    va_start(args, count); // Инициализация списка переменных аргументов

    int a = va_arg(args, int); // Первая сторона
    int b = va_arg(args, int); // Вторая сторона
    int validTriples = 0;

    // Скользящим окном берем каждую следующую сторону c и проверяем тройку (a, b, c)
    for (int i = 2; i < count; ++i) {
        int c = va_arg(args, int);
        if (isTriangle(a, b, c)) {
            ++validTriples;
        }
        a = b; // Сдвигаем окно на один элемент вправо
        b = c;
    }

    va_end(args); // Освобождение списка аргументов
    return validTriples;
}

int main() {
    // Три вызова с количеством числовых параметров 3, 9 и 11
    int res1 = triangle(3, 3, 4, 5);
    int res2 = triangle(9, 1, 2, 10, 3, 4, 5, 6, 7, 8);
    int res3 = triangle(11, 5, 5, 5, 1, 1, 10, 4, 6, 8, 2, 3);

    std::cout << "Вызов 1 (3 параметра: 3, 4, 5): "
              << res1 << " треугольник(а/ов)\n";
    std::cout << "Вызов 2 (9 параметров: 1, 2, 10, 3, 4, 5, 6, 7, 8): "
              << res2 << " треугольник(а/ов)\n";
    std::cout << "Вызов 3 (11 параметров: 5, 5, 5, 1, 1, 10, 4, 6, 8, 2, 3): "
              << res3 << " треугольник(а/ов)\n";

    return 0;
}
