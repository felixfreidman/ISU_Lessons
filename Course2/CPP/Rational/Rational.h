#pragma once
#ifndef _RATIONAL_H
#define _RATIONAL_H
class Rational
{
public:
	long long int numer;
	long long int denom;
	void simplify();

	Rational();
	Rational(long long int n);
	Rational(long long int n, long long int d);

	friend std::istream& operator >> (std::istream& in, Rational& r);
	friend std::ostream& operator << (std::ostream& out, const Rational& r);

	bool operator == (const Rational& r) const;
	bool operator == (const long long int& n) const;
	bool operator == (const int& n) const;

	bool operator != (const Rational& r) const;
	bool operator != (const long long int& n) const;
	bool operator != (const int& n) const;

	bool operator < (const Rational& r) const;
	bool operator < (const long long int& n) const;
	bool operator < (const int& n) const;

	bool operator > (const Rational& r) const;
	bool operator > (const long long int& n) const;
	bool operator > (const int& n) const;

	bool operator <= (const Rational& r) const;
	bool operator <= (const long long int& n) const;
	bool operator <= (const int& n) const;

	bool operator >= (const Rational& r) const;
	bool operator >= (const long long int& n) const;
	bool operator >= (const int& n) const;

	operator long long int() const;
	operator int();
	operator double() const;

	Rational& operator += (const Rational& r);
	Rational& operator += (const long long int& n);
	Rational& operator += (const int& n);

	Rational operator + (const Rational& r) const;
	Rational operator + (const long long int& n) const;
	Rational operator + (const int& n) const;

	Rational operator -() const;

	Rational& operator -= (const Rational& r);
	Rational& operator -= (const long long int& n);
	Rational& operator -= (const int& n);

	Rational operator - (const Rational& r) const;
	Rational operator - (const long long int& n) const;
	Rational operator - (const int& n) const;

	Rational& operator ++();					// prefix inc
	Rational operator ++(int);					// postfix inc
	Rational& operator --();
	Rational operator --(int);

	Rational& operator *= (const Rational& r);
	Rational& operator *= (const long long int& n);
	Rational& operator *= (const int& n);

	Rational operator * (const Rational& r) const;
	Rational operator * (const long long int& n) const;
	Rational operator * (const int& n) const;
	
	Rational& operator /= (const Rational& r);
	Rational& operator /= (const long long int& n);
	Rational& operator /= (const int& n);

	Rational operator / (const Rational& r) const;
	Rational operator / (const long long int& n) const;
	Rational operator / (const int& n) const;

	Rational sq();
};
#endif