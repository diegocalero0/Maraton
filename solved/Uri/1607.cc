#include<bits/stdc++.h>
using namespace std;

int main(){

	int t;
	cin >> t;

	string a, b;
	while(t--){
		cin >> a >> b;
		int cont = 0;
		for(int i = 0; i < a.length(); i++){
			if(a[i] < b[i]){
				cont += (b[i] - a[i]);
			}else if(a[i] > b[i]){
				cont += ('z' - a[i]) + (b[i] - 'a') + 1;
			}
		}
		cout << cont << endl;
	}

	return 0;
}