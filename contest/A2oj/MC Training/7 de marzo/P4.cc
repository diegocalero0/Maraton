#include<bits/stdc++.h>
using namespace std;

int n;
int digit[11] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8, 8};

long long lastDigit(int n){
	if(n <= 10)
		return digit[n];
	
	if( (n / 10) % 2 != 0){
		return 4 * lastDigit(n / 5) * lastDigit(n % 10);
	}else{
		return 6 * lastDigit(n / 5) * lastDigit(n % 10);
	}

}

ofstream cou("output.o");
int main(){
	long long result;
	int k = 1;
	while(cin >> n){
		result = lastDigit(n);
		cout << "Instancia " << k++ << endl;
		cout << (result % 10) << endl;
		cout << endl;
	}

	return 0;
}
