#include<bits/stdc++.h>
using namespace std;

int n;
int m[50][50];

bool correct(int k, int l){
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(m[k][j] + m[i][l] == m[k][l])
				return true;
	return false;
}

int main(){

	cin >> n;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> m[i][j];

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(m[i][j] != 1 && !correct(i, j)){
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}