#include<bits/stdc++.h>
using namespace std;

int main(){

	string n;
	int cont = 0;
	double d, sum = 0;

	while(getline(cin, n)){
		cont++;
		cin >> d;
		cin.ignore();
		sum += d;
	}
	sum /= cont;

	printf("%.1f\n", sum);

	return 0;
}