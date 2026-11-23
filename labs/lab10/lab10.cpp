#include <iostream>
#include <cstring>
#include <cctype>

const int MAX_LINE_LEN = 256;

// Выделение динамического массива строк и ввод их с клавиатуры
char** createStringArray(int n) {
    char** arr = new char*[n];
    char buffer[MAX_LINE_LEN];

    for (int i = 0; i < n; ++i) {
        std::cout << "Строка [" << i << "]: ";
        std::cin.getline(buffer, MAX_LINE_LEN);
        std::size_t len = std::strlen(buffer);
        arr[i] = new char[len + 1];
        std::strcpy(arr[i], buffer);
    }
    return arr;
}

// Печать динамического массива строк
void printStringArray(const char* const* arr, int n, const char* title) {
    std::cout << title << "\n";
    if (n == 0) {
        std::cout << "  (массив пуст)\n";
        return;
    }
    for (int i = 0; i < n; ++i) {
        std::cout << "  [" << i << "] \"" << arr[i] << "\"\n";
    }
}

// Проверка, начинается и заканчивается ли строка на одну и ту же букву (без учета регистра)
bool startsAndEndsSameLetter(const char* str) {
    std::size_t len = std::strlen(str);
    if (len == 0) {
        return false;
    }
    unsigned char first = static_cast<unsigned char>(str[0]);
    unsigned char last = static_cast<unsigned char>(str[len - 1]);

    if (!std::isalpha(first) || !std::isalpha(last)) {
        return false;
    }
    return std::tolower(first) == std::tolower(last);
}

// Формирование нового динамического массива без строк,
// начинающихся и заканчивающихся на одну и ту же букву
char** removeMatchingStrings(const char* const* arr, int n, int& newN) {
    newN = 0;
    for (int i = 0; i < n; ++i) {
        if (!startsAndEndsSameLetter(arr[i])) {
            ++newN;
        }
    }

    if (newN == 0) {
        return nullptr;
    }

    char** result = new char*[newN];
    int idx = 0;
    for (int i = 0; i < n; ++i) {
        if (!startsAndEndsSameLetter(arr[i])) {
            std::size_t len = std::strlen(arr[i]);
            result[idx] = new char[len + 1];
            std::strcpy(result[idx], arr[i]);
            ++idx;
        }
    }
    return result;
}

// Освобождение памяти динамического массива строк
void freeStringArray(char** arr, int n) {
    if (arr == nullptr) {
        return;
    }
    for (int i = 0; i < n; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}

int main() {
    int n;
    std::cout << "Введите количество строк в массиве: ";
    std::cin >> n;

    if (n < 1) {
        std::cout << "Ошибка: количество строк должно быть положительным.\n";
        return 1;
    }

    std::cin.ignore(1000, '\n');

    char** strings = createStringArray(n);
    printStringArray(strings, n, "\nИсходный массив строк:");

    int newN = 0;
    char** filtered = removeMatchingStrings(strings, n, newN);
    printStringArray(filtered, newN, "\nРезультирующий массив строк:");

    freeStringArray(strings, n);
    freeStringArray(filtered, newN);

    return 0;
}
