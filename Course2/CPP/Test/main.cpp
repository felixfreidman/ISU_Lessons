#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

class Number {
    private:
        int n;
        int numsys;
    public:
        Number() {
            n = 0;
            numsys = 1;
        }
        Number(int my_n, int my_numsys) {
            assert(my_numsys >= 0);
            n = my_n;
            numsys = my_numsys;
        }
        int getNum() { return n; }
        int getNumsys() { return numsys; }
        int toDecimal() {
            int num = this->n;
            int nsys = this->numsys;
            int decimal = 0;
            int cnt = 0;
            if (nsys == 10) {
                decimal = num;
            }
            else {
                while (num > 0) {
                    decimal += (num % 10)*pow(nsys, cnt);
                    num /= 10;
                    cnt++;
                }
            }
            return decimal;
        }
        int add(Number b) { return toDecimal() + b.toDecimal(); }
        int substract(Number b) { return toDecimal() - b.toDecimal(); }
        float div(Number b) { return float(toDecimal()) / b.toDecimal(); }
        int multiply(Number b) { return toDecimal() * b.toDecimal(); }
        int power(Number b) { return pow(toDecimal(), b.toDecimal()); }
};

int main(void) {

    Number a(1101001, 2);
    Number b(2, 10);

    cout << "Сложение:\t" << a.add(b) << endl;
    cout << "Вычитание:\t" << a.substract(b) << endl;
    cout << "Деление:\t\t" << a.div(b) << endl;
    cout << "Умножение:\t" << a.multiply(b) << endl;
    cout << "Возведение в степень:\t" << a.power(b) << endl;

    return 0;
}
