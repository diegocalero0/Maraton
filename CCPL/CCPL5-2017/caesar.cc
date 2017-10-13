#include<bits/stdc++.h>
using namespace std;

int main(){

	string s;

	while(cin >> s){
		int cont = 26;
		for(int i = 0; i < 26; i++){
			for(int j = 0; j < s.length(); j++){
				if( ((s[j] - 97 + i) % 26) + 97 == 'i'){
					cont--;
					break;
				}
			}
		}
		if(cont <= 0)
			cout << "impossible" << endl;
		else
			cout << cont << endl;
	}

	return 0;
}
