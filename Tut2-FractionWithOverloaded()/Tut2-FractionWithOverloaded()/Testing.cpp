#include<iostream>
using namespace std;

class Fraction{
private:
	int num;
	int denom;
public:
	Fraction(int numerator = 1, int denominator = 1){
		num = numerator;
		denom = denominator;
	}

	~Fraction(){

	}

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

	void fractionReduction(Fraction Frac){
		num  /= gcd(Frac);
		denom /= gcd(Frac);
	}

	

	Fraction operator+(const Fraction Fracc) {
		Fraction Frac;
		Frac.num = num*Fracc.denom + Fracc.num*denom;
		Frac.denom = Fracc.denom * denom;
		Frac.fractionReduction(Frac);
		return Frac;
	}

	Fraction operator-(const Fraction Fracc) {
		Fraction Frac;
		Frac.num = num*Fracc.denom - Fracc.num*denom;
		Frac.denom = Fracc.denom * denom;
		Frac.fractionReduction(Frac);
		return Frac;
	}

	Fraction operator*(const Fraction Fracc) {
		Fraction Frac;
		Frac.num = num *Fracc.num;
		Frac.denom = Fracc.denom * denom;
		Frac.fractionReduction(Frac);
		return Frac;
	}

	Fraction operator/(const Fraction Fracc) {
		Fraction Frac;
		Frac.num = num * Fracc.denom;
		Frac.denom = Fracc.num * denom;
		Frac.fractionReduction(Frac);
		return Frac;
	}

	friend ostream &operator<<(ostream &output, Fraction &Fract){
		output << Fract.num << "/" << Fract.denom;
		return output;
	}

	friend istream &operator>>(istream &input, Fraction &Frac_3){
		input >> Frac_3.num >> Frac_3.denom;
		return input;
	}
};

int main(){
	Fraction Frac_1;
	Fraction Frac_2;
	cout << "Fractions\n" << endl;
	cin >> Frac_1;
	cin >> Frac_2;
	cout << "Add:\n" << endl;
	cout << "Simplified fraction\n" << Frac_1 + Frac_2 << "\n" << endl;
	cout << "Subtract:\n" << endl;
	cout << "Simplified fraction\n" << Frac_1 - Frac_2 << "\n" << endl;
	cout << "Multiply:\n" << endl;
	cout << "Simplified fraction\n" << Frac_1 * Frac_2 << "\n" << endl;
	cout << "Divide:\n" << endl;
	cout << "Simplified fraction\n" << Frac_1 / Frac_2 << "\n" << endl;
	system("pause");
	return 0;
}