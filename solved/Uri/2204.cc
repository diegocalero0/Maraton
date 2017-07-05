#include<bits/stdc++.h>
using namespace std;

int main(){

	int t;
	string a, b;
	cin >> t;

	while(t--){
		cin >> a >> b;

		if(a == b)
			cout << a << endl;
		else
			cout << 1 << endl;
	}

	return 0;
}
