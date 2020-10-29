#include <cstdlib>
#include <iostream>
#include <string>
#include "Rational.h"

using namespace std;

Rational::Rational()
{
	numer = 0;
	denom = 1;
}

Rational::Rational(long long int n)
{
	numer = n;
	denom = 1;
}

Rational::Rational(long long int n, long long int  d)
{
	numer = n;
	denom = d;
}

istream& operator >> (istream& in, Rational& r)
{
	string s;
	in >> s;
	int tmp = s.find("/");
	if (tmp != string::npos)
	{
		r.numer = stoll(s.substr(0, tmp));
		r.denom = stoll(s.substr(tmp + 1));
	}
	else
	{
		r.numer = stoll(s);
		r.denom = 1;
	}
	
	return in;
}

ostream& operator << (ostream& out, const Rational& r)
{
	out << r.numer << "/" << r.denom;
	return out;
}

/* void Rational::simplify()
{
	if (denom < 0)
	{
		numer = -numer;
		denom = -denom;
	}
	for (int i = 2; i <= abs(denom) && i <= abs(numer); i++)
		if (numer % i == 0 && denom % i == 0)
		{
			numer /= i;
			denom /= i;
			i--;
		}
} */

long long int gcd(long long int x, long long int y)
{
	if (y == 0) return x;
	return gcd(y, x % y);
}

void Rational::simplify()
{
	long long int tmp = gcd(numer, denom);
	numer /= tmp;
	denom /= tmp;

	if (denom < 0)
	{
		numer = -numer;
		denom = -denom;
	}
}

bool Rational::operator == (const Rational& r) const
{
	return (numer == r.numer) && (denom == r.denom);
}

bool Rational::operator == (const long long int& n) const
{
	return (numer / denom == n) && (numer % denom == 0);
}

bool Rational::operator == (const int& n) const
{
	return (numer / denom == n) && (numer % denom == 0);
}

bool Rational::operator != (const Rational& r) const
{
	return !(*this == r);
}

bool Rational::operator != (const long long int& n) const
{
	return !(*this == n);
}

bool Rational::operator != (const int& n) const
{
	return !(*this == n);
}

bool Rational::operator < (const Rational& r) const
{
	return (numer * r.denom) < (denom * r.numer);
}

bool Rational::operator < (const long long int& n) const
{
	return (numer / denom) < n;
}

bool Rational::operator < (const int& n) const
{
	return (numer / denom) < n;
}

bool Rational::operator > (const Rational& r) const
{
	return (numer * r.denom) > (denom * r.numer);
}

bool Rational::operator > (const long long int& n) const
{
	return (numer / denom) > n || ((numer / denom) == n && (numer % denom) > 0);
}

bool Rational::operator > (const int& n) const
{
	return (numer / denom) > n || ((numer / denom) == n && (numer % denom) > 0);
}

bool Rational::operator <= (const Rational& r) const
{
	return (*this < r) || (*this == r);
}

bool Rational::operator <= (const long long int& n) const
{
	return (*this < n) || (*this == n);
}

bool Rational::operator <= (const int& n) const
{
	return (*this < n) || (*this == n);
}

bool Rational::operator >= (const Rational& r) const
{
	return (*this > r) || (*this == r);
}

bool Rational::operator >= (const long long int& n) const
{
	return (*this > n) || (*this == n);
}

bool Rational::operator >= (const int& n) const
{
	return (*this > n) || (*this == n);
}

Rational::operator long long int() const
{
	return numer / denom;
}

Rational::operator int()
{
	return numer / denom;
}

Rational::operator double() const
{
	return ((double)numer) / denom;
}

Rational& Rational::operator += (const Rational& r)
{
	numer = (numer * r.denom + denom * r.numer);
	denom *= r.denom;
	simplify();
	return *this;
}

Rational& Rational::operator += (const long long int& n)
{
	numer += n * denom;
	return *this;
}

Rational& Rational::operator += (const int& n)
{
	numer += n * denom;
	return *this;
}

Rational Rational::operator + (const Rational& r) const
{
	Rational res(*this);
	return res += r;
}

Rational Rational::operator + (const long long int& n) const
{
	Rational res(*this);
	return res += n;
}

Rational Rational::operator + (const int& n) const
{
	Rational res(*this);
	return res += n;
}

Rational Rational::operator -() const
{
	Rational r(-numer, denom);
	return r;
}

Rational& Rational::operator -= (const Rational& r)
{
	return (*this += (-r));
}

Rational& Rational::operator -= (const long long int& n)
{
	return (*this += (-n));
}

Rational& Rational::operator -= (const int& n)
{
	return (*this += (-n));
}

Rational Rational::operator - (const Rational& r) const
{
	Rational res(*this);
	return res -= r;
}

Rational Rational::operator - (const long long int& n) const
{
	Rational res(*this);
	return res -= n;
}

Rational Rational::operator - (const int& n) const
{
	Rational res(*this);
	return res -= n;
}

Rational& Rational::operator ++()
{
	numer += denom;
	return *this;
}

Rational Rational::operator ++(int)
{
	Rational r(*this);
	numer += denom;
	return r;
}

Rational& Rational::operator --()
{
	numer -= denom;
	return *this;
}

Rational Rational::operator --(int)
{
	Rational r(*this);
	numer -= denom;
	return r;
}

Rational& Rational::operator *= (const Rational& r)
{
	numer *= r.numer;
	denom *= r.denom;
	simplify();
	return *this;
}

Rational& Rational::operator *= (const long long int& n)
{
	numer *= n;
	simplify();
	return *this;
}

Rational& Rational::operator *= (const int& n)
{
	numer *= n;
	simplify();
	return *this;
}

Rational Rational::operator * (const Rational& r) const
{
	Rational res(*this);
	return res *= r;
}

Rational Rational::operator * (const long long int& n) const
{
	Rational res(*this);
	return res *= n;
}

Rational Rational::operator * (const int& n) const
{
	Rational res(*this);
	return res *= n;
}

Rational& Rational::operator /= (const Rational& r)
{
	numer *= r.denom;
	denom *= r.numer;
	simplify();
	return *this;
}

Rational& Rational::operator /= (const long long int& n)
{
	denom *= n;
	simplify();
	return *this;
}

Rational& Rational::operator /= (const int& n)
{
	denom *= n;
	simplify();
	return *this;
}

Rational Rational::operator / (const Rational& r) const
{
	Rational res(*this);
	return res /= r;
}

Rational Rational::operator / (const long long int& n) const
{
	Rational res(*this);
	return res /= n;
}

Rational Rational::operator / (const int& n) const
{
	Rational res(*this);
	return res /= n;
}

Rational Rational::sq()
{
	//I hope no one will try to find square root of negative number. Please.
	Rational r(*this);
	if (r > 0)
	{
		r.simplify();
		double numer = sqrt(r.numer) * 1E+8;
		double denom = sqrt(r.denom) * 1E+8;

		string s = to_string(numer);
		int val = s.size();
		if (s.size() > 9) s = s.substr(0, 9);
		int n = stoi(s);

		s = to_string(denom);
		val -= s.size();
		if (s.size() > 9) s = s.substr(0, 9);
		int d = stoi(s);

		r = Rational(n, d);
		if (val > 0)
		{
			for (int i = 0; i < val; i++)
			{
				r.numer *= 10;
			}
		}
		else if (val < 0)
		{
			val = -val;
			for (int i = 0; i < val; i++)
			{
				r.denom *= 10;
			}
		}
		
		r.simplify();
		return r;
	}
	else if (r == 0) 
	{
		r.denom = 1;
		return r;
	}

}
