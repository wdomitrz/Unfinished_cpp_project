#include<iostream>
#include<algorithm>
#include<vector>
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
vector < pair < rational_number, rational_number > > tab;
vector < rational_number > con;
rational_number count_const(long long wh){
	rational_number out;
      out=tab[wh].second;
      for(int i=0;i<tab.size();i++){
		if(i!=wh){
			out=out/(tab[wh].first-tab[i].first);
		}
      }
      return out;
}
rational_number calculate_for(long long wh, long long how){
	rational_number out;
      out=con[wh];
      for(int i=0;i<n;i++){
            // Tu skoñczy³em <------------------------------------------------------
      }
      return out;
}
rational_number calculate(long long how){
      rational_number out;
      out.set_value(0,1);
      for(long long i=0;i<tab.size();i++){
            out=out+calculate_for(i,how);
      }
	return out;
}
int main(){
	cerr <<"Liczba punktow: ";
	long long n;
	long long x,y;
	pair < rational_number, rational_number > wsp;
	cin >> n;
	for(long long i=0;i<n;i++){
		cerr << "Wspolrzedne "<<(i+1)<<".  punktu (na razie tylko ca³kowite):\n";
		cin >> x >> y;
		(wsp.first).set_value(x,1);
		(wsp.second).set_value(y,1);
		tab.push_back(wsp);
	}
	for(long long i=0;i<n;i++){
		con.push_back( count_const(i) );
	}
	bool czy=1;
	if(czy){
		for(int i=n-1;i>0;i--){
			cout <<"";
			calculate(i).print();
			if(i==1)
				cout <<"*x"<<" + ";
			else
				cout <<"*x^"<<i<<" + ";
		}
		cout << "";
		calculate(0).print();
		cout<<"" <<'\n';
	}
	return 0;
}
