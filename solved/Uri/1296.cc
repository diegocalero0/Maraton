#include<bits/stdc++.h>
using namespace std;

int main(){

	double a, b, c;
	while(cin >> a >> b >> c){
		double s = (a + b + c) * 0.5;
		double res;
		if(s * (s - a) * (s - b) * (s - c) <= 0)
			res = -1.0;
		else
			res = (4.0 / 3.0) * sqrt(s * (s - a) * (s - b) * (s - c));
		printf("%.3f\n", res);
	}
	return 0;
}