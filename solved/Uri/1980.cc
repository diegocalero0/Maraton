#include<bits/stdc++.h>
using namespace std;

int main(){

	string s;
	while(cin >> s && s != "0"){
		long long n = s.length();
		long long res = 1;
		for(int i = 0; i < n; i++){
			res *= (n - i);
		}
		cout << res << endl;
	}
	return 0;
}