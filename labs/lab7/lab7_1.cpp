#include <iostream>
#include <cctype>

// Перегруженная функция 1: количество четных элементов в массиве целых чисел
int countTask(const int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 == 0) { // Проверка четности остатком от деления на 2
            ++count;
        }
    }
    return count;
}

// Перегруженная функция 2: количество слов в строке, начинающихся на 'a'/'A'
int countTask(const char* str) {
    int count = 0;
    bool inWord = false; // Флаг: находимся ли мы сейчас внутри слова

    for (int i = 0; str[i] != '\0'; ++i) {
        unsigned char ch = static_cast<unsigned char>(str[i]);
        if (std::isspace(ch) || ch == '.' || ch == ',') {
            inWord = false; // Разделитель завершает текущее слово
        } else {
            if (!inWord) {  // Первый символ нового слова
                inWord = true;
                if (ch == 'a' || ch == 'A') {
                    ++count;
                }
            }
        }
    }
    return count;
}

int main() {
    const int MAX_ARR_SIZE = 50;
    int n;
    std::cout << "Введите размер массива целых чисел (до " << MAX_ARR_SIZE << "): ";
    std::cin >> n;
    if (n < 1 || n > MAX_ARR_SIZE) {
        std::cout << "Некорректный размер массива.\n";
        return 1;
    }

    int arr[MAX_ARR_SIZE];
    std::cout << "Введите " << n << " целых чисел: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    // Очистка буфера ввода от '\n' перед чтением строки через getline
    std::cin.ignore(1000, '\n');

    const int MAX_STR_LEN = 256;
    char text[MAX_STR_LEN];
    std::cout << "Введите строку: ";
    std::cin.getline(text, MAX_STR_LEN);

    int evenCount = countTask(arr, n); // Вызов версии для массива
    int wordCount = countTask(text);   // Вызов версии для строки

    std::cout << "Количество четных элементов в массиве: " << evenCount << "\n";
    std::cout << "Количество слов, начинающихся на букву 'a': " << wordCount << "\n";

    return 0;
}
