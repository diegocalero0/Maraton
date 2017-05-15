#include<bits/stdc++.h>
using namespace std;

int main(){

	int t;
	long x;

	cin >> t;
	bool flag;
	while(t--){
		cin >> x;
		flag = true;
		for(int i = 2; i * i <= x && flag; i++){
			if(x % i == 0)
				flag = false;
		}
		if(flag)
			cout << "Prime" << endl;
		else
			cout << "Not Prime" << endl;
	}

	return 0;
}