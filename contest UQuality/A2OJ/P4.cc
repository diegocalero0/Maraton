#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	int n;
	cin >> t;
	unsigned long long res = 0;
	while(t--){
		res = 0;
		cin >> n;
		for(int i = n - 1; i >= 0; i--){
			res += 1 << i;
		}
		
		cout << res << endl;
	}
	

	return 0;
}