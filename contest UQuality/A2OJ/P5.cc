#include<bits/stdc++.h>
using namespace std;

int n;

double solve(){
	double res = 1;
	double div = 0;
	while(n--){
		div += 2;
		div = 1 / div;
	}
	return res + div;
}

int main(){

	cin >> n;

	printf("%.10f\n", solve());

	return 0;
}