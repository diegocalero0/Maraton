#include<bits/stdc++.h>
using namespace std;

int main(){

	int n, curr;

	cin >> n;

	while(n--){
		cin >> curr;
		cout << (curr * (curr + 1) / 2 + 1) << endl;
	}

	return 0;
}