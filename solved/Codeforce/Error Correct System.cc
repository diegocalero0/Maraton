#include<bits/stdc++.h>
using namespace std;

int main(){

	int n,diff = 0;
	string s, t;
	
	cin >> n;
	cin >> s >> t;

	int abc[260], eqq[260][260];
	for(int i = 0; i < 260; i++){
		abc[i] = -1;
		for(int j = 0; j < 260; j++)
			eqq[i][j] = -1;
	}
	
	for(int i = 0; i < n; i++)
		if(s[i] != t[i]){
			diff++;
			abc[s[i]] = i;
			eqq[s[i]][t[i]] = i;
		}
	int l = -2, r = -2, res = 0;
	for(int i = 0; i < n; i++){
		if(abc[t[i]] != -1 && s[i] != t[i]){
			l = i; r = abc[t[i]];
			res = 1;
		}
	}

	for(int i = 'a'; i <= 'z'; i++){
		for(int j = 'a'; j <= 'z'; j++){
			if(eqq[i][j] != -1 && eqq[j][i] != -1){
				l  = eqq[i][j], r = eqq[j][i];
				res = 2;
				break;
			}
		}
	}

	diff -= res;
	cout << diff << endl << l + 1 << " " << r + 1 << endl;
	return 0;
}