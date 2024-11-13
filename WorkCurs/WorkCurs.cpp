#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int matrixcons(int** matrix, string num) {
	int row, col;
	cout << "Задайте размерность " << num << " матрицы: ";
	cin >> row >> col;
	for (short i = 0; i < row; i++) {
		matrix[i] = new int[col];
	}

	system("cls");
	cout << "Заполните матрицу" << endl;
	for (short i = 0; i < row; i++)
	{
		for (short j = 0; j < col; j++)
		{
			cin >> matrix[i][j];
		}
	}
	system("cls");

	return **matrix;
}

void clear_memory(int** matrix) {
	short row = sizeof(*matrix) / sizeof(matrix[0]);
	for (short i = 0; i < row; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

int main()
{
	int** marixfirst = nullptr;
	int** marixsecond = nullptr;
	int** marixthrid = nullptr;
	setlocale(LC_ALL, "RU");
	while (true)
	{
		cout << "\tВыберите действие." << endl;
		cout << "[1] Консольный ввод данных." << endl;
		cout << "[2] Файловый ввод данных." << endl;
		cout << "[3] Редактировать матрицу." << endl;
		cout << "[4] Вывод матрицы." << endl;
		cout << "[5] Выход из программы." << endl;
		short choice; cin >> choice;
		switch (choice)
		{
		case 1: system("cls");
				matrixcons(marixfirst, "первой");
				matrixcons(marixsecond, "второй");
				matrixcons(marixthrid,	"третьей");	
				break;
		//case 2: addnumsmatrixfile(); break;
		//case 3: editmatrix(); break;
		//case 4: viewmatrix(); break;
		case 5: 
		{
			clear_memory(marixfirst);
			clear_memory(marixsecond);
			clear_memory(marixthrid);
			return 0;
			break;
		}
		default: cout << "error\n";  break;
		}
	}

}

