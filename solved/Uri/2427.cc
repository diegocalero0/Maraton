#include<bits/stdc++.h>
using namespace std;

long long sol(double n){
	if( n < 2.0)
		return 1;
	return sol(n * 0.5) * 4;
}

int main(){

	int n;
	cin >> n;
	cout << sol(n) << endl;

	return 0;
}