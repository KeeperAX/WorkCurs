#include <iostream>
#include <string>
#include <fstream>


using namespace std;
int** matrixfirst;
int** matrixsecond;
int** matrixthird;

void addnumsmatrixfile() {
	ifstream inputFile;
	inputFile.open("LabWork4.txt");
}

void addnumsmatrix(int** matrix, int row, int col) {
	for (short i = 0; i < row; i++)
	{
		for (short j = 0; j < col; j++)
		{
			cin >> matrix[i][j];
		}
	}
}

int** create_matrix(string text) {
	int row, int col;
	cout << "Введите кол-во строк " << text << " матрицы: " << endl;
	cin >> row;
	cout << "Введите кол-во стобцов " << text << " матрицы: " << endl;
	cin >> col;

	int** matrix = new int* [row];
	for (short i = 0; i < row; i++) {
		matrix[i] = new int[col];
	}

	addnumsmatrix(matrix, row, col);
	system("cls");
	return matrix;
}

void create_matrixs() {
	matrixfirst = create_matrix("первой");
	matrixsecond = create_matrix("второй");
	matrixthird = create_matrix("третьей");
}

void delete_matrix(int** matrix)
{
	/*for (short i = 0; i < rowt; i++) {
		delete[] matrix[i];
	}

	delete[] matrix;*/
}

void clear_memory()
{
	delete_matrix(matrixfirst);
	delete_matrix(matrixsecond);
	delete_matrix(matrixthird);
}

int main()
{
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
		case 1: create_matrixs(); break;
		case 2: addnumsmatrixfile(); break;
		case 3: editmatrix(); break;
		case 4: viewmatrix(); break;
		case 5: 
		{
			clear_memory();
			system("exit"); break;
		}
		default: cout << "error\n";  break;
		}
	}

}

