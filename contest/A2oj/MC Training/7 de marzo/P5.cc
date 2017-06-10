#include<bits/stdc++.h>
using namespace std;

int main(){

    long double num;
    string sig;
	scanf("%LE", &num);
	stringstream ss;
	ss << num;
	ss >> sig;
	if(sig[0] != '-')
		cout << "+";
	printf("%.4LE\n", num);

	return 0;
}