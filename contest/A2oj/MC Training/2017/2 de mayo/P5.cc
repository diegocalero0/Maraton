#include<bits/stdc++.h>
using namespace std;

int main(){

	int t, n, x, y, sol;
	cin >> t;

	while(t--){
		vector<int> res(101, 0);
		vector<int> pre(101, -1);	
		sol = 0;
		cin >> n;
		while(n--){
			cin >> x >> y;
			res[x] = max(res[x], y);
			if(y >= 10 && y <= 100)
				pre[x] = max(pre[x], y);
		}
		for(int i = 0; i < 101; i++){
			if(pre[i] == -1)
				sol += res[i];
			else
				sol += pre[i];
		}
		cout << sol << endl;
	}

	return 0;
}