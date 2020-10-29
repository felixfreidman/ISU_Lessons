#include <iostream>
#include "Rational.h"

using namespace std;

// Example of input: 5/12
// "5 12" will be recieved as 5/1 and 12/1 !

int main() 
{
	Rational a, b, c;

	cout << "Enter arguments A, B, C:\n(ex.: 1/2 -2/3 1 will be recieved as x^2/2 - 2*x/3 + 1)\n" << endl;
	cin >> a >> b >> c;

	if (a == 0)
	{
		if (b == 0)
		{
			if (c == 0) cout << "x is any number!" << endl;
			else cout << "x belongs to empty set!" << endl;
		}
		else
		{
			Rational x;
			x = -c / b;
			cout << "x = " << x;
		}
	}
	else
	{
		Rational d = (b * b) - (a * c * 4);

		if (d > 0)
		{
			Rational x1, x2;
			d = d.sq();
			x1 = (d - b) / (a * 2);
			x2 = (-d - b) / (a * 2);
			cout << "x belongs to {" << x1 << ", " << x2 << "}" << endl;
		}
		else if (d == 0)
		{
			Rational x;
			x = (-b) / (a * 2);
			cout << "x = " << x;
		}
		else cout << "D < 0, can't find solution :(" << endl;
	}
}
