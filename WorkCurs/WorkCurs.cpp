#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void viewmatrix(int& size, int** matrix, string num){
    cout << "\t" << num << " матрица" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << " ";
        }
    }
    cout << endl;
}

int** editmatrix(int& size, int** matrix, string num) {
    cout << "Введите страку и столбец элемента" << endl;
    int row, col; cin >> row >> col;
    if (row >= size || col >= size || row < 0 || col < 0) {
        cout << "erorr" << endl;
    }
    else {
        cout << "Введите новый элемент: ";
        cin >> matrix[row][col];
    }
}

int** matrixfill(int& size, string num) {
    short textsize = 0;
    char* textmatrix = new char[textsize];
    ifstream nums("matrix.txt");
    if (!nums.is_open()) {
        cout << "error";
        return nullptr;
    }

    while (textsize < 1000 && nums >> textmatrix[textsize]) {
        textsize++;
    }

    cout << "Введите размерность " << num << "матрицы" << endl;
    cin >> size;

    int** matrix = new int*[size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
    }

    for (int i = 0; i < size * size && i < textsize; i++) {
        matrix[i / size][i % size] = stoi(&textmatrix[i]);
    }

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
    cout << "Заполните матрицу" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> matrix[i][j];
        }
    }
    system("cls");

    return matrix;
}

void clear_memory(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int** matrixfirst = nullptr;
    int** matrixsecond = nullptr;
    int** matrixthrid = nullptr;
    int size1, size2, size3;

    while (true) {
        cout << "\tВыберите действие." << endl;
        cout << "[1] Консольный ввод данных." << endl;
        cout << "[2] Файловый ввод данных." << endl;
        cout << "[3] Редактировать матрицу." << endl;
        cout << "[4] Вывод матрицы." << endl;
        cout << "[5] Выход из программы." << endl;
        short choice; cin >> choice;
        switch (choice) {
        case 1:
            system("cls");
            matrixfirst = matrixcons(size1, "первой"); system("cls");
            matrixsecond = matrixcons(size2, "второй"); system("cls");
            matrixthrid = matrixcons(size3, "третьей"); system("cls");
            break;
        case 2: 
            matrixfirst = matrixfill(size1,"первой"); system("cls");
            matrixsecond = matrixfill(size1, "второй"); system("cls");
            matrixthrid = matrixfill(size3, "третьей"); system("cls");
            break;
        case 3:
            cout << "Какую матрицу Вы хотите отредактировать?" << endl;\
            short count = 0; cin >> count;
            switch (count) {
                case 1: matrixfirst = matrixfill(size1, matrixfirst, "Первая"); system("cls"); break;
                case 2: matrixsecond = matrixfill(size2, matrixsecond, "Вторая"); system("cls"); break;
                case 3:  matrixthrid = matrixfill(size3, matrixthrid, "Третья"); system("cls"); break;
                default: cout << "error"; break;
            }
            break;
        case 4:
            viewmatrix(size1, matrixfirst, "Первая");
            viewmatrix(size2, matrixsecond, "Вторая");
            viewmatrix(size3, matrixthrid, "Третья");
            system("pause");
            system("cls");
            break;
        case 5:
            clear_memory(matrixfirst, size1);
            clear_memory(matrixsecond, size2);
            clear_memory(matrixthrid, size3);
            return 0;
        default:
            cout << "error\n";
            break;
        }
    }
}
