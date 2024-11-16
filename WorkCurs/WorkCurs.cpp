#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

void viewmatrix(int size, int** matrix, string num) {
    cout << "\t" << num << " матрица" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void editmatrix(int size, int** matrix, string num) {
    cout << "Введите строку и столбец элемента:" << endl;
    int row, col;
    cin >> row >> col;
    row--; col--;
    while (true)
    {
        if (row >= size || col >= size || row < 0 || col < 0) {
            cout << "Ошибка: неверные индексы." << endl;
            cout << "Попробуйте снова." << endl; // Добавлено для ясности
            cin >> row >> col; // Добавлено для повторного ввода
            row--; col--;
        }
        else
        {
            break;
        }
    }
    cout << "Введите новый элемент: ";
    cin >> matrix[row][col];
}

short point = 0;

int** matrixfill(int& size, string num) {
    ifstream textmatrix("matrix.txt");
    if (!textmatrix.is_open()) {
        cout << "Ошибка открытия файла." << endl; // Добавлена точка
        return nullptr;
    }

    int sizematrix = 0;
    short temp;
    while (textmatrix >> temp) {
        sizematrix++;
    }
    textmatrix.clear(); // Сброс состояния потока
    textmatrix.seekg(0); // Перемещение в начало файла

    while (true) {
        cout << "Выберите размер матрицы: ";
        cin >> size;
        if (size * size + point > sizematrix) {
            cout << "Невозможный размер матрицы. Попробуйте снова: ";
        }
        else {
            break;
        }
    }

    int** matrix = new int* [size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
    }

    for (short a = 0; a < point; a++) {
        textmatrix >> temp;
    }

    for (short i = 0; i < size; i++) {
        for (short j = 0; j < size; j++) {
            textmatrix >> matrix[i][j];
        }
    }
    textmatrix.close();
    point += (size * size);
    return matrix;
}

int** matrixcons(int& size, string num) {
    cout << "Задайте размерность " << num << " матрицы: ";
    cin >> size;

    int** matrix = new int* [size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
    }

    system("cls");
    cout << "Заполните матрицу:" << endl; // Добавлена двоеточие
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> matrix[i][j];
        }
    }
    system("cls");

    return matrix;
}

void clear_memory(int** matrix, int size) {
    if (matrix != nullptr) {
        for (int i = 0; i < size; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    //system("chcp 65001");
    int** matrixfirst = nullptr;
    int** matrixsecond = nullptr;
    int** matrixthird = nullptr;
    int size1 = 0, size2 = 0, size3 = 0;

    while (true) {
        cout << "\tВыберите действие." << endl;
        cout << "[1] Консольный ввод данных." << endl;
        cout << "[2] Файловый ввод данных." << endl;
        cout << "[3] Редактировать матрицу." << endl;
        cout << "[4] Вывод матрицы." << endl;
        cout << "[5] Выход из программы." << endl;
        short choice;
        cin >> choice;
        switch (choice)
            switch (choice) {
            case 1:
                system("cls");
                clear_memory(matrixfirst, size1);
                clear_memory(matrixsecond, size2);
                clear_memory(matrixthird, size3);
                matrixfirst = matrixcons(size1, "A"); system("cls");
                matrixsecond = matrixcons(size2, "B"); system("cls");
                matrixthird = matrixcons(size3, "C"); system("cls");
                break;
            case 2:
                system("cls");
                point = 0;
                clear_memory(matrixfirst, size1);
                clear_memory(matrixsecond, size2);
                clear_memory(matrixthird, size3);
                matrixfirst = matrixfill(size1, "A"); system("cls");
                matrixsecond = matrixfill(size2, "B"); system("cls");
                matrixthird = matrixfill(size3, "C"); system("cls");
                break;
            case 3:
                cout << "Какую матрицу Вы хотите отредактировать?" << endl;
                short count; cin >> count;
                switch (count) {
                case 1: editmatrix(size1, matrixfirst, "A"); system("cls"); break;
                case 2: editmatrix(size2, matrixsecond, "B"); system("cls"); break;
                case 3: editmatrix(size3, matrixthird, "C"); system("cls"); break;
                default: cout << "Ошибка: неверный выбор." << endl; break; // Добавлена точка
                }
                break;
            case 4:
                viewmatrix(size1, matrixfirst, "A");
                viewmatrix(size2, matrixsecond, "B");
                viewmatrix(size3, matrixthird, "C");
                system("pause");
                system("cls");
                break;
            case 5:
                clear_memory(matrixfirst, size1);
                clear_memory(matrixsecond, size2);
                clear_memory(matrixthird, size3);
                return 0;
            default: cout << "Ошибка: неверный выбор." << endl; break; // Добавлена точка
            }
    }
}
