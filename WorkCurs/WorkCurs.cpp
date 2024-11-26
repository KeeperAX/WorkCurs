#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

void viewmatrix(int size, int** matrix, string num) {
    if (matrix == nullptr) {
        cout << "Матрица не инициализирована." << endl;
        return;
    }
    cout << "\t" << num << " матрица" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

bool multipmatrix(int** matrixA, int** matrixB, int** matrixC, int size1, int size2, int size3) {
    if (size2 != size3) {
        cout << "Матрицы не могут быть перемножены." << endl;
        return false;
    }

    int** matrixN = new int* [size1];
    for (int i = 0; i < size1; i++) {
        matrixN[i] = new int[size1];
        for (int j = 0; j < size1; j++) {
            matrixN[i][j] = 0;
        }
    }

    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size1; ++j) {
            for (int k = 0; k < size1; ++k) {
                matrixN[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    short ans = 0;
    for (short i = 0; i < size1; i++) {
        for (short j = 0; j < size1; j++) {
            if (matrixC[i][j] == matrixN[i][j]) {
                ans++;
            }
        }
    }
    for (int i = 0; i < size1; i++) {
        delete[] matrixN[i];
    }
    delete[] matrixN;

    if (ans == size1 * size1) {
        return true;
    }
    return false;
}

void sravnenie(int** matrixA, int** matrixB, int** matrixC, int size1, int size2, int size3) {
    short size;
    unsigned short arrsize = 0;
    int* arr = new int[size1 * size1];

    if (size1 <= size2 && size1 <= size3) {
        size = size1;
    }
    else if (size2 <= size1 && size2 <= size3) {
        size = size2;
    }
    else {
        size = size3;
    }

    for (short i = 0; i < size; i++) {
        for (short j = 0; j < size; j++) {
            if (matrixC[i][j] == (matrixA[i][j] + matrixB[i][j])) {
                arr[arrsize++] = matrixC[i][j];
            }
        }
    }
    if (arrsize == 0) {
        cout << "Нет элементов" << endl;
    }
    else {
        cout << "Элементы матрицы С: ";
        for (short i = 0; i < arrsize; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    delete[] arr;
}

void sortmatrix(int** matrixA, int** matrixB, int** matrixC, int size1, int size2, int size3) {
    unsigned short arrAsize = 0, arrBsize = 0;
    int* arrA = new int[size1 * size1];
    int* arrB = new int[size2 * size2];

    for (short i = 0; i < size1; i++) {
        for (short j = 0; j < size1; j++) {
            if (matrixA[i][j] == matrixC[i][j]) {
                arrA[arrAsize++] = matrixA[i][j];
            }
        }
    }

    for (short i = 0; i < size2; i++) {
        for (short j = 0; j < size2; j++) {
            if (matrixB[i][j] == matrixC[i][j]) {
                arrB[arrBsize++] = matrixB[i][j];
            }
        }
    }

    for (short i = 0; i < arrAsize - 1; i++) {
        for (short j = 0; j < arrAsize - i - 1; j++) {
            if (arrA[j] > arrA[j + 1]) {
                swap(arrA[j], arrA[j + 1]);
            }
        }
    }
    for (short i = 0; i < arrBsize - 1; i++) {
        for (short j = 0; j < arrBsize - i - 1; j++) {
            if (arrB[j] > arrB[j + 1]) {
                swap(arrB[j], arrB[j + 1]);
            }
        }
    }

    if (arrAsize == 0) {
        cout << "Элементов нет" << endl;
    }
    else {
        cout << "Элементы матрицы A в порядке возрастания: ";
        for (short i = 0; i < arrAsize; i++) {
            cout << arrA[i] << " ";
        }
        cout << endl;
    }
    if (arrBsize == 0) {
        cout << "Элементов нет" << endl;
    }
    else {
        cout << "Элементы матрицы B в порядке возрастания: ";
        for (short i = 0; i < arrBsize; i++) {
            cout << arrB[i] << " ";
        }
        cout << endl;
    }
    delete[] arrA;
    delete[] arrB;
}

void editmatrix(int size, int** matrix, string num) {
    cout << "Введите строку и столбец элемента:" << endl;
    int row, col;
    cin >> row >> col;
    row--; col--;
    if (row >= size || col >= size || row < 0 || col < 0) {
        cout << "Ошибка: неверные индексы." << endl;
        return;
    }
    cout << "Введите новый элемент: ";
    cin >> matrix[row][col];
}

short point = 0;

int** matrixfill(int& size, string num) {
    ifstream textmatrix("matrix.txt");
    if (!textmatrix.is_open()) {
        cout << "Ошибка открытия файла." << endl;
        return nullptr;
    }

    int sizematrix = 0;
    short temp;
    while (textmatrix >> temp) {
        sizematrix++;
    }
    textmatrix.clear();
    textmatrix.seekg(0);

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

    if (size <= 0) {
        cout << "Ошибка: размер матрицы должен быть положительным." << endl;
        return nullptr;
    }

    int** matrix = new int* [size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
    }

    system("cls");
    cout << "Заполните матрицу:" << endl;
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
        cout << "Меню:" << endl;
        cout << "[1] Консольный ввод данных" << endl;
        cout << "[2] Файловый ввод данных" << endl;
        cout << "[3] Редактировать матрицу" << endl;
        cout << "[4] Вывод матрицы" << endl;
        cout << "[5] Пункт 11: Вывести элементы матрицы A и B, которые встречаются в матрицы C, в порядке возрастания" << endl;
        cout << "[6] Пункт 14: Вывести на экран элементы матрицы С, которые равны сумме соответствующих элементов матрицы А и B" << endl;
        cout << "[7] Пункт 16: Определить является ли матрица С результатом перемножения матрицы A и B" << endl;
        cout << "[8] Выход из программы." << endl;
        cout << "Выберите действие: ";
        short choice;
        cin >> choice;
        switch (choice) {
        case 1:
            system("cls");
            point = 0;
            matrixfirst = matrixcons(size1, "A"); system("cls");
            matrixsecond = matrixcons(size2, "B"); system("cls");
            matrixthird = matrixcons(size3, "C"); system("cls");
            break;
        case 2:
            system("cls");
            point = 0;
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
            default: cout << "Ошибка: неверный выбор." << endl; break;
            }
            break;
        case 4:
            viewmatrix(size1, matrixfirst, "A");
            viewmatrix(size2, matrixsecond, "B");
            viewmatrix(size3, matrixthird, "C");
            system("pause");
            system("cls");
            break;
        case 5: sortmatrix(matrixfirst, matrixsecond, matrixthird, size1, size2, size3); system("pause"); system("cls"); break;
        case 6: sravnenie(matrixfirst, matrixsecond, matrixthird, size1, size2, size3); system("pause"); system("cls"); break;
        case 7:
            if (multipmatrix(matrixfirst, matrixsecond, matrixthird, size1, size2, size3) == true) {
                cout << "Матрица С является результатом перемножения матрицы A и B" << endl;
            }
            else {
                cout << "Матрица С НЕ является результатом перемножения матрицы A и B" << endl;
            }
            system("pause");
            system("cls");
            break;
        case 8:
            clear_memory(matrixfirst, size1);
            clear_memory(matrixsecond, size2);
            clear_memory(matrixthird, size3);
            return 0;
        default: cout << "Ошибка: неверный выбор." << endl; break;
        }
    }
}