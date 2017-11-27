#include<bits/stdc++.h>
using namespace std;

int dig[10];

int main(){

	int k;
	cin >> k;

	string m[4];
	cin >> m[0] >> m[1] >> m[2] >> m[3];

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(m[i][j] >= '0' && m[i][j] <= '9'){
				dig[m[i][j] - '0']++;
				if(dig[m[i][j] - '0'] > 2 * k){
					cout << "NO" << endl;
					return 0;
				}
			}
		}
	}

	cout << "YES" << endl;

	return 0;
}