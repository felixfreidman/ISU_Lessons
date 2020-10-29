#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

bool is_prime(long long int n) {
	if (n <= 1) {
		return false;
	}
	if (n == 2) {
		return true;
	}

	for (long long int i = 2; i < sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}

int main() {
	const long long CUTTER = 1E9;
	long long buffer = 0;
	long long i = 0;

	ifstream in("e_2mil.txt", ios::in);
	char ch;

	while ((ch = in.get()) != EOF) {

		buffer %= CUTTER;
		buffer *= 10;
		buffer += (int)(ch - '0');
		i++;

		if (is_prime(buffer)) {
			if (buffer > (CUTTER / 10)) {
				cout << "RESULT FOUND: " << buffer << ", is number No. " << i << endl;
				break;
			}
		}
	}

	in.close();
}
