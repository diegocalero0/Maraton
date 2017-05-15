#include<bits/stdc++.h>
using namespace std;

int main(){

	double n, h;

	cin >> n >> h;

	double area = (1 * h) / 2, res;
	area /= n;
	for(double x = 1; x < n; x++){
		res = sqrt((double)((double)2 * x * area * h));
		printf("%.12f ", res);
	}
	cout << endl;
	return 0;
}