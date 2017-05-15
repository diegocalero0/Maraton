#include<bits/stdc++.h>
using namespace std;

int main(){

	int t, n, m, aux;
	cin >> t;

	while(t--){
		cin >> n >> m;
		vector<int> votes(n, 0);
		for(int i = 0; i < m; i++){
			cin >> aux;
			aux--;
			votes[aux]++;
		}
		bool flag = false;
		for(int i = 0; i < n; i++)
			if((double)votes[i] > (double)((double)m / (double)2)){
				cout << i + 1 << endl;
				flag = true;
				break;
			}
		if(!flag)
			cout << -1 << endl;
	}

	return 0;
}