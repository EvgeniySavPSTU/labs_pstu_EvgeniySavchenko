#include <iostream>
#include <cstring>
#include <cctype>

const int MAX_LEN = 256; // До 255 символов + нуль-терминатор '\0'

// Проверка, является ли слово длиной len идентификатором языка C/C++
bool isIdentifier(const char* word, int len) {
    if (len <= 0) {
        return false;
    }
    // Первый символ: только латинская буква или '_'
    unsigned char first = static_cast<unsigned char>(word[0]);
    if (!std::isalpha(first) && word[0] != '_') {
        return false;
    }
    // Остальные символы: буква, цифра или '_'
    for (int i = 1; i < len; ++i) {
        unsigned char ch = static_cast<unsigned char>(word[i]);
        if (!std::isalnum(ch) && word[i] != '_') {
            return false;
        }
    }
    return true;
}

// Формирование новой строки dst только из слов-идентификаторов строки src
void filterIdentifiers(const char* src, char* dst) {
    int i = 0;
    int dstPos = 0;
    bool hasPeriod = false;

    while (src[i] != '\0') {
        // Пропускаем лишние пробелы
        while (src[i] == ' ') {
            ++i;
        }
        if (src[i] == '\0') {
            break;
        }
        if (src[i] == '.') {
            hasPeriod = true;
            break;
        }

        // Выделяем очередное слово до пробела, точки или конца строки
        int start = i;
        while (src[i] != '\0' && src[i] != ' ' && src[i] != '.') {
            ++i;
        }
        int wordLen = i - start;

        // Если слово — идентификатор, копируем его в результат через пробел
        if (isIdentifier(src + start, wordLen)) {
            if (dstPos > 0) {
                dst[dstPos++] = ' ';
            }
            for (int k = 0; k < wordLen; ++k) {
                dst[dstPos++] = src[start + k];
            }
        }

        if (src[i] == '.') {
            hasPeriod = true;
            break;
        }
    }

    if (hasPeriod) {
        dst[dstPos++] = '.';
    }
    dst[dstPos] = '\0'; // Завершаем строку нуль-терминатором
}

int main() {
    char input[MAX_LEN];
    char result[MAX_LEN];

    std::cout << "Введите строку (до 255 символов, в конце точка):\n";
    std::cin.getline(input, MAX_LEN);

    filterIdentifiers(input, result);

    std::cout << "Исходная строка: " << input << "\n";
    std::cout << "Результат:       " << result << "\n";

    return 0;
}
