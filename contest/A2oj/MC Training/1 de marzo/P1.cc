#include<bits/stdc++.h>
using namespace std;

int main(){

	int n, amount;
	char animal;
	int c = 0, r = 0, s = 0;
	cin >> n;
	while(n--){
		cin >> amount >> animal;
		if(animal == 'C')
			c += amount;

		if(animal == 'R')
			r += amount;

		if(animal == 'S')
			s += amount;
	}
	cout << "Total: " << s + r + c << " cobais" << endl;
	cout << "Total de coelhos: " << c <<  endl;
	cout << "Total de ratos: " << r << endl;
	cout << "Total de sapos: " << s << endl;
	double total =  (double)(c * 100) / (double)(r + c + s);
	printf("Percentual de coelhos: %.2f %%\n", total);
	total =  (double)(r * 100) / (double)(r + c + s);
	printf("Percentual de ratos: %.2f %%\n", total);
	total =  (double)(s * 100) / (double)(r + c + s);
	printf("Percentual de sapos: %.2f %%\n", total);
	return 0;
}
