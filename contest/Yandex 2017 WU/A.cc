#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;
	for(int i = 2LL; i < n; i++){
		if(n % i != 0){
			cout << i << endl;
			return 0;
		}
	}
	if(n == 2 || n == 1)
		cout << n + 1 << endl;

}