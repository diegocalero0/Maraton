#include<bits/stdc++.h>
using namespace std;

int main(){

	int n, a;
	double min, ang, curr = 10000.0, best;

	cin >> n >> a;

	min = 180.0 / n;

	for(int i = 1; i <= n - 2; i++){
		ang = min * i;
		if(abs(ang - a) < curr){
			best = i;
			curr = abs(ang - a);
		}
	}

	cout << best + 2 << " " << 1 << " " << 2 << endl;
	return 0;
}