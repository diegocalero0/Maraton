#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main(){

	ull a, b, c;

	cin >> a;

	if(a <= 2){
		cout << -1 << endl;
		return 0;
	}

	if(a % 2){
		b = ((a * a) - 1) / 2;
		c = b + 1;
	}else{
		b = (((a * a) / 2) - 2) / 2;
		c = b + 2;
	}


	cout << b << " " << c << endl;
	return 0;
}
