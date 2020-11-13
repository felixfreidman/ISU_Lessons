#include <iostream>
class Converter{
private:
//Вектор содержит исходное число
	vector<int> a;
//Исходная система счисления
	int iriginal;
public:
//Конструктор, содержит 2 параметра: строка исходного числа, исходная система счисления
	Converter(string str, int original){
		this->iriginal = original;
		//Заносит числа исходного числа в вектор
		for ( int i=0; i < str.length(); i++ ){
			this->a.push_back(charToInt(str[i]));
		}
	}
	//Переводит символ в число, вместо некорректных символов возвращает -1
	int charToInt(char c){
		if ( c >= '0' && c <= '9' && (c - '0') < this->iriginal ){
			return c - '0';
		}else{
			if ( c >= 'A' && c <= 'Z' && (c - 'A') < this->iriginal ){
				return c - 'A' + 10;
			}else {
				return -1;
			}
		}
	}
	//Переводит число в символ
	char intToChar(int c){
		if ( c >= 0 && c <= 9 ){
			return c + '0';
		}else{
			return c + 'A' - 10;
		}
	}
	//Получает следующую цифру числа в новой системе счисления
	int nextNumber(int final){
		int temp = 0;
		for ( int i = 0; i<this->a.size(); i++){
			temp = temp*this->iriginal + this->a[i];
			a[i] = temp / final;
			temp = temp % final;
		}
		return temp;
	}
	//Возвращает true - если массив состоит из одних нулей и false в противном случае
	bool zero(){
		for ( int i=0; i<this->a.size(); i++ ){
			if ( a[i] != 0 ){
				return false;
			}
		}
		return true;
	}
	//Конвертирует исходное число в заданную систему счисления
	string convertTo(int final){
		vector<int> b;
		int size = 0;
		do {
			b.push_back(this->nextNumber(final));
			size++;
		}while( !this->zero() );

		string sTemp="";
		for (int i=b.size()-1; i>=0; i--){
			sTemp += intToChar(b[i]);
		}
	return sTemp;
	}
};
using namespace std;

int main(void) {
}