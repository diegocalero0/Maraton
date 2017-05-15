#include<bits/stdc++.h>
using namespace std;

int main(){

	string s;
	int res1, res2, c1,c2;
	while(cin >> s){
		c1 = 9;
		c2 = 1;
		res1 = res2 = 0;
		for(int i = 0; i < 9; i++){
			int curr = s[i] - 48;
			res1 += (curr * c2++);
			res2 += (curr * c1--);
		}
		for(int i = 0; i < 9; i++){
			if(i % 3 == 0 && i != 0)
				cout << ".";
			cout << s[i];
		}
		cout << "-" << ((res1 % 11) % 10) << ((res2 % 11)) % 10 << endl;
	}

	return 0;
}