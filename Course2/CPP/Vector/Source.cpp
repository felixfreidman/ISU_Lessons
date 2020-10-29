#include "Array.h"
#include <iostream>

using namespace std;

int main()
{
	/* Случайные тесты, ибо необходимые тесты были проведены по ходу написания класса */

	Array <int> arr{ 1, 2, 3, 4, 5 };
	arr.insert(3, arr);
	arr.push_back(6);
	cout << "Array: " << arr;
	cout << "Size: " << arr.getSize() << endl;
	arr.pop_back();
	arr.set(0, arr.get(arr.getSize() - 1));
	arr[1] = arr[0] * 2;
	arr.remove(5);
	cout << "Array: " << arr;
	cout << "Size: " << arr.getSize() << endl;

	Array <double> d(5);
	cout << "\nEnter any 5 double numbers: ";
	cin >> d;
	Array <double> d2 = d;
	for (unsigned int i = 0; i < d.getSize(); i++)
		d2[i] /= 2;
	d.insert(d2);
	cout << d;
}
