#include <iostream>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>

// использование длинной арифметики
// Генерация числа Е
using namespace std;

typedef unsigned long long int ull;

void print(int k, ull* e, ull R) {
	ofstream out;
	out.open("output.txt");

	out << to_string(e[0]);
	for (int i = 1; i < k; i++) {

		string tmp = to_string(e[i]);
		if (tmp.size() < R) {
			for (int i = tmp.size(); i < R; i++) {
				out << "0";
			}
		}

		out << tmp;
	}

	out << "\n";
	out.close();
}

void SetData(int k, ull* arr, short n) {
	for (int i = 1; i < k; i++) {
		arr[i] = 0;
	}
	arr[0] = n;
}

bool isZero(int k, ull* uk) {
	for (int i = 0; i < k; i++) {
		if (uk[i] != 0) {
			return false;
		}
	}
	return true;
}

void Div(int k, ull* uk, int i, ull b) {

	ull res = 0, tmp;

	int j = 0;
	while (uk[j] == 0) {
		j++;
	}

	for (j; j < k; j++) {
		tmp = uk[j] + res * b;
		uk[j] = tmp / i;
		res = tmp - uk[j] * i;
	} 
	
}

void Add(int k, ull* e, ull* uk, ull b) {

	ull res = 0;

	int i = k - 1;
	while (uk[i] == 0) {
		i--;
	}

	for (i; i >= 0; i--) {
		e[i] += uk[i] + res;
		if (e[i] > b) {
			e[i] -= b;
			res = 1;
		}
		else {
			res = 0;
		}
	}

}

int main() 
{
	setlocale(LC_ALL, "Russian");
	
	// INPUT DATA
	ull R = 8;
	ull n = 1E+6;
	// END OF INPUT

	unsigned int start_timer1 = clock();

	ull b = pow(10, R);	
	int k = n / R;			// n / log10(b+1)

	ull* e = new ull[k];
	ull* uk = new ull[k];

	SetData(k, e, 1);
	SetData(k, uk, 1);
	int i = 1;

	unsigned int end_timer1 = clock();

	cout << "Подготовка к вычислениям завершена!" << endl;
	cout << "Затрачено " << ((end_timer1 - start_timer1) / 1000) << " секунд на подготовку." << endl;
	cout << "Заданные параметры: считать приблизительно до " << n << " знаков после запятой;" << endl;
	cout << "Один разряд \"содержит в себе\" " << R << " десятичных.\n" << endl;

	unsigned int start_timer2 = clock();
	while (!isZero(k, uk)) {
		Div(k, uk, i, b);
		Add(k, e, uk, b);
		i++;
	}
	unsigned int end_timer2 = clock();

	cout << "Вычисления завершены." << endl;
	unsigned int tmp = (end_timer2 - start_timer2) / 1000;
	cout << "Затрачено " << (tmp / 60) << " минут " << (tmp % 60) << " секунд на подсчёты." << endl;
	cout << "Полученный результат будет выведен в файл output.txt, ожидайте...\n" << endl;

	unsigned int start_timer3 = clock();
	print(k, e, R);
	unsigned int end_timer3 = clock();
	cout << "Вывод завершён." << endl;
	cout << "Затрачено " << ((end_timer3 - start_timer3) / 1000) << " секунд на вывод." << endl;

}
