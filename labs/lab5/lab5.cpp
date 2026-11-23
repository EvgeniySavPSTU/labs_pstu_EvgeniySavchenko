#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

const int MAX_ROWS = 10; // Максимальное число строк матрицы
const int MAX_COLS = 10; // Максимальное число столбцов матрицы

// Заполнение матрицы вручную с клавиатуры
void inputMatrixManual(int mat[MAX_ROWS][MAX_COLS], int rows, int cols) {
    std::cout << "Введите элементы матрицы (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "mat[" << i << "][" << j << "] = ";
            std::cin >> mat[i][j];
        }
    }
}

// Заполнение матрицы случайными числами в диапазоне [minVal, maxVal]
void inputMatrixRandom(int mat[MAX_ROWS][MAX_COLS], int rows, int cols, int minVal, int maxVal) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            mat[i][j] = minVal + std::rand() % (maxVal - minVal + 1);
        }
    }
}

// Форматированный вывод матрицы на экран
void printMatrix(const int mat[MAX_ROWS][MAX_COLS], int rows, int cols) {
    std::cout << "Двумерный массив:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << std::setw(5) << mat[i][j]; // Выравнивание по ширине 5 символов
        }
        std::cout << "\n";
    }
}

// Подсчет количества вхождений значения value во всей матрице
int countOccurrences(const int mat[MAX_ROWS][MAX_COLS], int rows, int cols, int value) {
    int count = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (mat[i][j] == value) {
                ++count;
            }
        }
    }
    return count;
}

// Поиск минимального из неповторяющихся элементов.
// Результат записывается в minUnique; функция возвращает false, если все элементы повторяются.
bool findMinUnique(const int mat[MAX_ROWS][MAX_COLS], int rows, int cols, int& minUnique) {
    bool found = false;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Элемент неповторяющийся, если встречается ровно 1 раз
            if (countOccurrences(mat, rows, cols, mat[i][j]) == 1) {
                if (!found || mat[i][j] < minUnique) {
                    minUnique = mat[i][j];
                    found = true;
                }
            }
        }
    }
    return found;
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Инициализация генератора случайных чисел

    int rows, cols;
    std::cout << "Введите количество строк (1.." << MAX_ROWS << "): ";
    std::cin >> rows;
    std::cout << "Введите количество столбцов (1.." << MAX_COLS << "): ";
    std::cin >> cols;

    if (rows < 1 || rows > MAX_ROWS || cols < 1 || cols > MAX_COLS) {
        std::cout << "Ошибка: некорректные размеры матрицы.\n";
        return 1;
    }

    int matrix[MAX_ROWS][MAX_COLS];
    int choice;
    std::cout << "Выберите способ заполнения (1 - вручную, 2 - случайно): ";
    std::cin >> choice;

    if (choice == 1) {
        inputMatrixManual(matrix, rows, cols);
    } else {
        inputMatrixRandom(matrix, rows, cols, 1, 15);
    }

    printMatrix(matrix, rows, cols);

    int minVal = 0;
    if (findMinUnique(matrix, rows, cols, minVal)) {
        std::cout << "Минимальный из неповторяющихся элементов: " << minVal << "\n";
    } else {
        std::cout << "В массиве нет неповторяющихся элементов.\n";
    }

    return 0;
}
