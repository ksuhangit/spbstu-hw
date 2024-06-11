#include <iostream>

void multiplyMatrix(int** matrix1, int** matrix2, int** result, int rows1, int cols1, int rows2, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int rows1, cols1, rows2, cols2;

    std::cout << "Введите количество строк и столбцов для первой матрицы: ";
    std::cin >> rows1 >> cols1;

    int** matrix1 = new int* [rows1];
    for (int i = 0; i < rows1; i++) {
        matrix1[i] = new int[cols1];
        for (int j = 0; j < cols1; j++) {
            std::cout << "Введите элемент матрицы [" << i << "][" << j << "]: ";
            std::cin >> matrix1[i][j];
        }
    }

    std::cout << "Введите количество строк и столбцов для второй матрицы: ";
    std::cin >> rows2 >> cols2;

    int** matrix2 = new int* [rows2];
    for (int i = 0; i < rows2; i++) {
        matrix2[i] = new int[cols2];
        for (int j = 0; j < cols2; j++) {
            std::cout << "Введите элемент матрицы [" << i << "][" << j << "]: ";
            std::cin >> matrix2[i][j];
        }
    }

    if (cols1 != rows2) {
        std::cout << "Нельзя перемножать матрицы, столбцы первой матрицы должны быть равны строкам второй матрицы." << std::endl;
        return 1;
    }

    int** result = new int* [rows1];
    for (int i = 0; i < rows1; i++) {
        result[i] = new int[cols2];
    }

    multiplyMatrix(matrix1, matrix2, result, rows1, cols1, rows2, cols2);

    std::cout << "Результирующая матрица:" << std::endl;
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < rows1; i++) {
        delete[] matrix1[i];
    }
    delete[] matrix1;

    for (int i = 0; i < rows2; i++) {
        delete[] matrix2[i];
    }
    delete[] matrix2;

    for (int i = 0; i < rows1; i++) {
        delete[] result[i];
    }
    delete[] result;

    return 0;
}
