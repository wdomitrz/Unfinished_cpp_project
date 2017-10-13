#include<iostream>
#include<vector>
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
		if(denominator==1ll){
			cout << numerator <<'\n';
		}
		else{
			cout << numerator <<"/"<<denominator<<'\n';
		}
	}

};
rational_number count_calc(string s_count_calc){
	rational_number zero;
	zero.set_value(0ll,1ll);
	vector < pair< rational_number,char> > tab,tab2;

	for(int i=0;i<s_count_calc.size();i++){
		pair< rational_number,char> calc_help;
		if(s_count_calc[i]=='('){
			long long help_value=1;
			string s_help="";
			while(help_value){
				i++;
				if (s_count_calc[i]=='('){
					help_value++;
				}
				if (s_count_calc[i]==')'){
					help_value--;
					if(help_value==0)
						break;
				}
				s_help+=s_count_calc[i];
			}
			calc_help.first=count_calc(s_help);
			if(i+1==s_count_calc.size()){
				calc_help.second='|';
			}
			else{
				if( ( '0' <= s_count_calc[i+1] ) && ( s_count_calc[i+1] <= '9' ) ){
					calc_help.second='*';
				}
				else{
					calc_help.second=s_count_calc[i+1];
				}
			}
			tab.push_back(calc_help);
		}
		else{
			if(( '0' <= s_count_calc[i] ) && ( s_count_calc[i] <= '9' )){
				long long number_numerator=0,number_denominator=1;
				while( ('0' <= s_count_calc[i] ) && ( s_count_calc[i] <= '9') && (i<s_count_calc.size()) ){
					number_numerator*=10;
					number_numerator+= (s_count_calc[i]-'0');
					i++;
				}
				(calc_help.first).set_value(number_numerator,number_denominator);
				if(i==s_count_calc.size()){
					calc_help.second='|';
				}
				else{
					if(s_count_calc[i]=='('){
						calc_help.second='*';
						i--;
					}
					else{
						calc_help.second=s_count_calc[i];
					}
				}
				tab.push_back(calc_help);
			}
		}
	}

	for(long long i=0;i<tab.size();i++){
		long long j=i;
		while( ( tab[j].second == '*' ) || ( tab[j].second == '/') ){
			i++;
			switch (tab[j].second){
				case '*':
					tab[j].first=tab[j].first*tab[i].first;
					break;
				case '/':
					tab[j].first=tab[j].first/tab[i].first;
					break;
			}
			tab[j].second=tab[i].second;
		}
		tab2.push_back(tab[j]);
	}

	rational_number out;
	out.set_value(0ll,0ll);
	out=tab[0].first;


	for(long long i=1;i<tab2.size();i++){
		switch (tab2[i-1].second){
			case '+':
				out=out+tab2[i].first;
				break;
			case '-':
				out=out-tab2[i].first;
				break;
		}
	}
	return out;
}
int main(){
	string s;
	while(2){
		cin >> s;
		rational_number out=count_calc(s);
		out.print();
	}
	return 0;
}
