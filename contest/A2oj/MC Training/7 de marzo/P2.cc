#include<bits/stdc++.h>
using namespace std;

int main(){

	string num;
	int d, n, curr, index, k;
	while(cin >> d >> n && d + n){
		getline(cin, num);
		getline(cin, num);
		index = -1;
		k = n;
		int res[d];
		for(int i = 0; i < d; i++){
			curr = num[i] - 48;

			while(n > 0 && index != -1 && res[index] < curr){
				n--;
				index--;
			}
			res[++index] = curr;
		}
		for(int i = 0; i < d - k; i++){
			cout << res[i];
		}
		cout << endl;
	}
	return 0;
}