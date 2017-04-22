#include<bits/stdc++.h>
using namespace std;

int main(){

	int t, n;
	cin >> t;

	while(t--){
		cin >> n;
		int sum = 0;
		for(int i = 1; i < sqrt(n); i++){
			if(n % i == 0 && i != n){
				sum += i;
				int i2 = n / i;
				if(i2 != i && n % i2 == 0 && i2 != n)
					sum += i2;
			}
			
		}

		if(sum == n)
			cout << "perfect\n";
		else if(sum > n)
			cout << "abundant\n";
		else
			cout << "deficient\n";

	}

	return 0;
}
