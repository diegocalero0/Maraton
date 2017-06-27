#include<bits/stdc++.h>
using namespace std;

int main(){

	long long n;
	cin >> n;

	for(long long i = 1; i <= n; i++){
		cout << i << " " << i * i << " " << i * i * i << endl;
	}

	return 0;
}