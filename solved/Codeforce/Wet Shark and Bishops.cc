#include<bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;


map<int, int> n, p;


int main(){

	int m, x, y;
	cin >> m;

	for(int i = 0; i < m; i++){
		cin >> x >> y;
		n[x + y]++;
		p[y - x]++;
	}


	int res = 0;

	for(int i = -2000; i <= 2000; i++){
		if(n[i] > 1)
			res += (n[i] - 1) * (n[i]) / 2;
		if(p[i] > 1)
			res += (p[i] - 1) * (p[i]) / 2;
	}

	cout << res << endl;

	return 0;
}