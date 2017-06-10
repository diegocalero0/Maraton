#include<bits/stdc++.h>
using namespace std;
unsigned long long n;
string toBin(){
	int divisor = 2;
	int resto;
	stringstream stream;
	while(n >= divisor){
   		resto = n % 2;
   		stream << resto;
   		n = n/divisor;
  	}
  	string s;
  	stream >> s;
  	return s;
}

int main(){

	while(cin >> n && n){

		string bin = toBin();
		unsigned long long res = 1;
		int pot = bin.length();
		for(int i = bin.length() - 1; i >= 0; i--){
			if(bin[i] == '1')
				res += ((long long)1 << pot);
			pot--;
		}
		cout << res << endl;
	}

}