#include<iostream>
#include<algorithm>
using namespace std;
class rational_number{
	public:
	long long numerator, denominator;
	long long gcd(){
		long long numerator_gcd=numerator,denominator_gcd=denominator, gcd_help;
		while (denominator_gcd != 0)
		{
			gcd_help = numerator_gcd % denominator_gcd;
			numerator_gcd = denominator_gcd;
			denominator_gcd = gcd_help;
		}
		if(numerator_gcd<0)
			numerator_gcd*=-1ll;
		return numerator_gcd;
	}
	void simpler(){
		long long simpler_help = gcd();
		if(simpler_help!=0){
			numerator/=simpler_help;
			denominator/=simpler_help;
		}
		if(denominator<0){
			numerator*=-1ll;
			denominator*=-1ll;
		}
	}

	rational_number operator+(const rational_number& operator_input){
		rational_number operator_output;
		operator_output.numerator = numerator * operator_input.denominator + denominator * operator_input.numerator;
		operator_output.denominator = denominator * operator_input.denominator;
		operator_output.simpler();
		return operator_output;
	}
	rational_number operator-(const rational_number& operator_input){
		rational_number operator_output;
		operator_output.numerator = numerator * operator_input.denominator - denominator * operator_input.numerator;
		operator_output.denominator = denominator * operator_input.denominator;
		operator_output.simpler();
		return operator_output;
	}
	rational_number operator*(const rational_number& operator_input){
		rational_number operator_output;
		operator_output.numerator = numerator * operator_input.numerator;
		operator_output.denominator = denominator * operator_input.denominator;
		operator_output.simpler();
		return operator_output;
	}
	rational_number operator/(const rational_number& operator_input){
		rational_number operator_output;
		operator_output.numerator = numerator * operator_input.denominator;
		operator_output.denominator = denominator * operator_input.numerator;
		operator_output.simpler();
		return operator_output;
	}
	bool operator<(const rational_number& operator_input){
		return numerator * operator_input.denominator < denominator * operator_input.numerator;
	}
	bool operator==(const rational_number& operator_input){
		if(denominator == 0 || operator_input.denominator==0)
			return 0;
		if(denominator == operator_input.denominator && numerator == operator_input.numerator )
			return 1;
		return 0;
	}
	void set_value (long long value_of_numerator, long long value_of_denominator) {
		numerator=value_of_numerator;
		denominator=value_of_denominator;
		simpler();
	}
	void print(){
		cout << numerator<<"/"<<denominator;
	}

};
int main(){
	long long a,b;
	cin >> a >> b;
	rational_number c,d;
	c.set_value(a,b);
	c.print();

	while(2){
		char ch;
		cin >> ch;
		switch (ch){
			case '=':
				cin >> a >> b;
				c.set_value(a,b);
				break;
			case '+':
				cin >> a >> b;
				d.set_value(a,b);
				c=c+d;
				break;

			case '-':
				cin >> a >> b;
				d.set_value(a,b);
				c=c-d;
				break;
			case '*':
				cin >> a >> b;
				d.set_value(a,b);
				c=c*d;
				break;
			case '/':
				cin >> a >> b;
				d.set_value(a,b);
				c=c/d;
				break;
			case '<':
				cin >> a >> b;
				d.set_value(a,b);
				if(c<d)
					cout << "Yes\n";
				else
					cout <<"No\n";
				break;
			case 'e':
				cin >> a >> b;
				d.set_value(a,b);
				if(c==d)
					cout << "Yes\n";
				else
					cout <<"No\n";
				break;
		}
		c.print();
	}
	return 0;
}
