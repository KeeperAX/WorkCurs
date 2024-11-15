#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int** matrixfill(int& row, int& col, string num) {
    string textmatrix;
    ifstream nums("matrix.txt");
    if (nums.is_open())
    {
        getline(nums, textmatrix);
    }
    else {
        cout << "error";
        return false;
    }

    cout << "\tПри чтение матрицы из файла matrix.txt, должны соблюдаться условия.\n 1.Три матрицы должны быть разделины восклицательным знаком <!>.\n 2.В конце каждой строки дожна быть точка с запятой." << endl;
    int** matrix = new int* [row];
    for (int i = 0; i < row; i++) {
        matrix[i] = new int[col];
    }
    short num[1000];
    short count = 0, col = 1, row = 1;
    for (short i = 0; i < 1000; i++)
    {
        if (textmatrix[i] == " ")
        {
            col++;
            continue;
        }
        if (textmatrix[i] == ";")
        {
            row++;
            continue;
        }
        if (textmatrix[i] == "!")
        {
            break;
        }
        num[count++] = stoi(textmatrix);
    }
    short a = 0;
    for (short i = 0; i < row; i++)
    {
        for (short j = 0; j < col; j++)
        {
            matrix[i][j] = num[a++];
        }
    }
    return matrix;
}

int** matrixcons(int& row, int& col, string num) {
    cout << "Задайте размерность " << num << " матрицы: ";
    cin >> row >> col;

    int** matrix = new int* [row]; 
    for (int i = 0; i < row; i++) {
        matrix[i] = new int[col];
    }

    system("cls");
    cout << "Заполните матрицу" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> matrix[i][j];
        }
    }
    system("cls");

    return matrix; 
}

void clear_memory(int** matrix, int row) {
    for (int i = 0; i < row; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    setlocale(LC_ALL, "RU");
    int** matrixfirst = nullptr;
    int** matrixsecond = nullptr;
    int** matrixthrid = nullptr;
    int row1, col1, row2, col2, row3, col3;

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
            matrixfirst = matrixcons(row1, col1, "первой");
            matrixsecond = matrixcons(row2, col2, "второй");
            matrixthrid = matrixcons(row3, col3, "третьей");
            break;
        case 2: 
            matrixfirst = matrixfill(row1, col1, "первой");
            matrixsecond = matrixfill(row2, col2, "второй");
            matrixthrid = matrixfill(row3, col3, "третьей");
            
            
            break;
            //case 3: editmatrix(); break;
            //case 4: viewmatrix(); break;
        case 5:
            clear_memory(matrixfirst, row1);
            clear_memory(matrixsecond, row2);
            clear_memory(matrixthrid, row3);
            return 0;
        default:
            cout << "error\n";
            break;
        }
    }
}
