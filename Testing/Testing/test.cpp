#include<iostream>
using namespace std;
class Fraction{
private:
	int num;
	int denom;
public:
	int gcd(Fraction Frac){
		int temp;
		while (Frac.num != 0)
		{
			temp = Frac.num;
			Frac.num = Frac.denom % Frac.num;
			Frac.denom = temp;
		}
		return Frac.denom;
	}

	void fractionReduction(Fraction Fract){
		num /= gcd(Fract);
		denom /= gcd(Fract);
	}

	void add(Fraction Fracc){
		num = Fracc.denom*num + Fracc.num*denom;
		denom = Fracc.denom * denom;
	}

	void subtract(Fraction Fracc){
		num = Fracc.denom*num - Fracc.num*denom;
		denom = Fracc.denom * denom;
	}

	void multiply(Fraction Fracc){
		num = Fracc.num * num;
		denom = Fracc.denom * denom;
	}

	void divide(Fraction Fracc){
		num = Fracc.denom * num;
		denom = Fracc.num * denom;
	}
	void setNumDenom(int numerator, int denominator){
		num = numerator;
		denom = denominator;
	}
	void getNumDenom(int &numerator, int &denominator)
	{
		numerator = num;
		denominator = denom;
	}

	void print(){
		int remainder;
		int IntegerPart;
		float quotient;
		quotient = num / denom;
		IntegerPart = (int)quotient;
		remainder = num % denom;
		if (remainder == 0)
		{
			cout << IntegerPart << endl;
		}
		else if (IntegerPart == 0){

			cout << num << "/" << denom << endl;
		}
		
		else
		{
			cout << IntegerPart << " " << remainder << "/" << denom << endl;
		}
	}
};

int main(){
	Fraction Frac_1;
	Fraction Frac_2;
	int numer;
	int denomin;
	int numer1;
	int denomin1;
	cout << "Fractions\n" << endl;
	cin >> numer;
	cin >> denomin;
	cin >> numer1;
	cin >> denomin1;
	Frac_1.setNumDenom(numer, denomin);
	Frac_1.getNumDenom(numer, denomin);
	Frac_2.setNumDenom(numer1, denomin1);
	Frac_2.getNumDenom(numer1, denomin1);
	Frac_1.add(Frac_2);
	cout << "The greatest common divisor is:\n" << Frac_1.gcd(Frac_1) << endl;
	Frac_1.fractionReduction(Frac_1);
	Frac_1.print();
	Frac_1.subtract(Frac_2);
	cout << "The greatest common divisor is:\n" << Frac_1.gcd(Frac_1) << endl;
	Frac_1.fractionReduction(Frac_1);
	Frac_1.print();
	Frac_1.multiply(Frac_2);
	cout << "The greatest common divisor is:\n" << Frac_1.gcd(Frac_1) << endl;
	Frac_1.fractionReduction(Frac_1);
	Frac_1.print();
	Frac_1.divide(Frac_2);
	cout << "The greatest common divisor is:\n" << Frac_1.gcd(Frac_1) << endl;
	Frac_1.fractionReduction(Frac_1);
	Frac_1.print();
	system("pause");
	return 0;
}