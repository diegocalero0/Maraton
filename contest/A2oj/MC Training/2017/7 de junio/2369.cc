#include<bits/stdc++.h>
using namespace std;

int main(){

	int n, res = 7;
	cin >> n;

	if(n <= 10){
		cout << res << endl;
		return 0;
	}

	if(n >= 30){
		res += 20;
	}else{
		res += (n - 10);
		cout << res << endl;
		return 0;
	}

	if(n >= 100){
		res += 140;
	}else{
		res += (n - 30) * 2;
		cout << res << endl;
		return 0;
	}

	if(n >= 101){
		res += (n - 100) * 5;
	}

	cout << res << endl;

	return 0;
}