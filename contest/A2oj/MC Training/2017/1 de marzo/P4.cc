#include<bits/stdc++.h>
using namespace std;

int main(){

	int n, m, a, b;
	string matris[105];
	while(cin >> n >> m && n + m){
		for(int i = 0; i < n; i++){
			cin >> matris[i];
		}
		cin >> a >> b;
		int x = a / n;
		int y = b / m;

		for(int i = 0; i < n; i++){
			for(int k = 0; k < x; k++){
				for(int j = 0; j < m; j++){
					for(int l = 0; l < y; l++){
						cout << matris[i][j];
					}
				}
					cout << endl;
			}
		}
		cout << endl;
	}

	return 0;
}
