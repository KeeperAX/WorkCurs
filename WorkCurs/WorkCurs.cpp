#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int** matrixfill(int& size, string num) {
    char textmatrix[1000];
    ifstream nums("matrix.txt");
    if (!nums.is_open()) {
        cout << "error";
        return nullptr;
    }

    int count = 0;
    while (count < 1000 && nums >> textmatrix[count]) {
        count++;
    }

    cout << "Введите размерность " << num << "матрицы" << endl;
    cin >> size;

    int** matrix = new int*[size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
    }

    for (int i = 0; i < size * size && i < count; i++) {
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
            matrixfirst = matrixcons(size1, "первой");
            matrixsecond = matrixcons(size2, "второй");
            matrixthrid = matrixcons(size3, "третьей");
            break;
        case 2: 
            matrixfirst = matrixfill(size1,"первой");
            matrixsecond = matrixfill(size1, "второй");
            matrixthrid = matrixfill(size3, "третьей");
            
            
            break;
            //case 3: editmatrix(); break;
            //case 4: viewmatrix(); break;
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
