#include<iostream>
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
rational_number number(string s_number){
	long long number_numerator=0,number_denominator=1;
	rational_number number_out;
	long long it=0;
	while(it<s_number.size() && s_number[it]!='/'){
		number_numerator*=10;
		number_numerator+=(long long)(s_number[it]-'0');
		it++;
	}
	if(it==s_number.size()){
		number_denominator=1;
	}
	else{
		number_denominator=0;
		it++;
		while(it<s_number.size()){
			number_numerator*=10;
			number_numerator+=(long long)(s_number[it]-'0');
			it++;
		}
	}
	number_out.set_value(number_numerator,number_denominator);
	return number_out;
}
rational_number count_calc(string s_count_calc){
	if(s_count_calc[0]=='{'){
		long long help_value=1;
		long long it=1;
		while(help_value){
			switch (s_count_calc[it]){
				case '{':
					help_value++;
					break;
				case '}':
					help_value--;
					break;
			}
			it++;
		}
		string s_help_1="",s_help_2="";
		char symbol=s_count_calc[it];
		for(long long i=1;i<it -1;i++){
			s_help_1+=s_count_calc[i];
		}
		for(long long i=it+2;i<s_count_calc.size() -1;i++){
			s_help_2+=s_count_calc[i];
		}
		switch (symbol){
			case '+':
				return count_calc(s_help_1)+count_calc(s_help_2);
			case '-':
				return count_calc(s_help_1)-count_calc(s_help_2);
			case '*':
				return count_calc(s_help_1)*count_calc(s_help_2);
			case '/':
				return count_calc(s_help_1)/count_calc(s_help_2);
		}
	}
	else{
		return number(s_count_calc);
	}
}
int main(){
	string s;
	cin >> s;
	rational_number out=count_calc(s);
	out.print();
	return 0;
}
