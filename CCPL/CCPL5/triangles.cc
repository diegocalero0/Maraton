#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
int n;
string triangles[105];

bool isValid(int i, int j){
	if(i >= 0 && i < n && j >= 0 && j < ((n - i) * 2) - 1)
		return true;
	return false;
}

int sol2(int i, int j, int cont){
	int res = 0;
	int cont2 = 0;
	for(int k = j; cont2 < cont; k--){
		if(!isValid(i, k) || triangles[i][k] != '-')
			return 0;
		else cont2++;
	}
	return cont + sol2(i + 1, j, cont + 2);
}

int sol1(int i, int j, int cont){
	int res = 0;
	int cont2 = 0;
	for(int k = j; cont2 < cont; k++){
		if(!isValid(i, k) || triangles[i][k] != '-')
			return 0;
		else cont2++;
	}
	return cont + sol1(i - 1, j, cont + 2);
}

int main(){
	int t = 1;
	while(cin >> n && n){
		for(int i = 0; i < n; i++)
			cin >> triangles[i];
		int res = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < triangles[i].length(); j++){
				if(triangles[i][j] == '-'){
					if(j % 2 == 0)
						res = max(res, sol1(i, j, 1));
					else
						res = max(res, sol2(i, j, 1));
				}
			}
		}
		cout << "Triangle #" << t++ << endl;
		cout << "The largest triangle area is " << res << "." << endl;
		cout << endl;
	}

	return 0;
}