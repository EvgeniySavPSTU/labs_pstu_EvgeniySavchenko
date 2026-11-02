#include <iostream>   // Потоковый ввод-вывод
#include <cstdlib>    // Генератор псевдослучайных чисел rand(), srand()
#include <ctime>      // Функция time() для инициализации генератора

using namespace std;

const int MAX_SIZE = 200; // Статический массив с запасом памяти под новые элементы

// Функция печати массива как кольца влево (против часовой стрелки: K, K-1, ..., K+1)
void printRingLeft(const int arr[], int n, int k) {
    if (n <= 0) return;
    cout << "Обход кольца влево от K = " << k << ": ";
    for (int count = 0; count < n; count++) {
        // Формула перехода влево с защитой от отрицательных индексов
        int idx = (k - count % n + n) % n;
        cout << arr[idx] << " ";
    }
    cout << "\n";
}

// Функция печати массива как кольца вправо (по часовой стрелке: K, K+1, ..., K-1)
void printRingRight(const int arr[], int n, int k) {
    if (n <= 0) return;
    cout << "Обход кольца вправо от K = " << k << ": ";
    for (int count = 0; count < n; count++) {
        // Формула перехода вправо по кольцу
        int idx = (k + count) % n;
        cout << arr[idx] << " ";
    }
    cout << "\n";
}

// Вспомогательная функция вывода элементов массива с их индексами
void printArray(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "[" << i << "]:" << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int arr[MAX_SIZE];
    int n, k;

    srand(static_cast<unsigned int>(time(NULL)));

    cout << "Введите размер массива N (до 100): ";
    cin >> n;
    if (n <= 0 || n > 100) n = 12;

    // 1. Формирование массива с помощью датчика случайных чисел
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 90 + 10; // Случайные числа от 10 до 99
    }

    cout << "\n1. Исходный массив:\n";
    printArray(arr, n);

    cout << "\nВведите индекс K (от 0 до " << n - 1 << "): ";
    cin >> k;
    if (k < 0 || k >= n) k = 0;

    // 2. Распечатка массива по кольцу влево от K-го элемента
    cout << "\n2. ";
    printRingLeft(arr, n, k);

    // 3. Добавление элемента 0 после каждого элемента с индексом, кратным 5 (0, 5, 10, ...)
    int temp[MAX_SIZE];
    int new_n = 0;

    for (int i = 0; i < n; i++) {
        temp[new_n++] = arr[i];
        if (i % 5 == 0) { // Проверка кратности исходного индекса 5
            temp[new_n++] = 0; // Вставка нуля после элемента
        }
    }

    // Обновляем основной массив и его длину
    n = new_n;
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }

    cout << "\n3. Массив после вставки нулей после элементов с индексами кратным 5:\n";
    printArray(arr, n);

    // 4. Распечатка массива по кольцу вправо от K-го элемента
    k = k % n; // Нормализация K под новую длину
    cout << "\n4. ";
    printRingRight(arr, n, k);

    return 0;
}