#include<bits/stdc++.h>
using namespace std;

int main(){

	int n, res, t = 1;
	int curr;
	while(cin >> n && n){
		for(int i = 1; i <= n; i++){
		cin >> curr;
		if(curr == i)
			res = i;
		}
		cout << "Teste " << t++ << endl;
		cout << res << endl << endl;
	}
	return 0;
}