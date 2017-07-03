#include<bits/stdc++.h>
using namespace std;

int main(){

	double m, b;
	long long res = 0, y;
	cin >> m >> b;

	for(int x = 0; x <= b * m; x++){
		y = floor(-(x / m) + b);
		res = max(res, ((y + 1) * (x * (y + x + 1) + y)) / 2);
	}

	cout << res << endl;
	return 0;
}