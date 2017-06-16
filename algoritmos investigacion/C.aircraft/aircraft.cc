#include<bits/stdc++.h>
using namespace std;

/*
Problema: dados 3 valores y muchas ternas de numeros, verificar si existe una combinacion entre las
diferentes ternas que sumen los tres valos iniciales.

Se utiliza mapas de bits para probar todas las posibilidades es decir: 10101 indica que se sumaran las ternas 1, 3, y 5.
*/


int main(){

	long t, x, a, b, m, xsum, asum, bsum, ax[50], aa[50], ab[50];
	bool flag;
	string des;
	cin >> t;

	while(t--){
		cin >> x >> a >> b >> m;
		flag = 0;
		for(int i = 0; i < m; i++)
			cin >> des >> ax[i] >> aa[i] >> ab[i];
		for(int i = 1; i < (1 << m) && !flag; i++){
			xsum = asum = 0;
			bsum = 0;
			for(int j = 0; j < m; j++){
				if(i & (1 << j)){
					xsum += ax[j];
					asum += aa[j];
					bsum += ab[j];
				}
			}
			if(xsum == x && asum == a && bsum == b)
				flag = 1;
		}
		if(flag)
			cout << "POSSIBLE" << endl;
		else
			cout << "IMPOSSIBLE" << endl;
	}

	return 0;
}
