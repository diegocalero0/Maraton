#include<bits/stdc++.h>
using namespace std;

int main(){

	double sal, res = 0;
	cin >> sal;
	
	if(sal >= 4500.0){
		double temp = sal - 4500;
		sal -= temp;
		res += (temp * 28 / 100);
	}
	if(sal > 3000.0){
		double temp = sal - 3000;
		sal -= temp;
		res += (temp * 18 / 100);
	}

	if(sal > 2000.0){
		double temp = sal - 2000;
		sal -= temp;
		res += (temp * 8 / 100);
	}

	
	if(res != 0)
		printf("R$ %.2f\n", res);
	else
		cout << "Isento" << endl;
	return 0;
}