#include<bits/stdc++.h>
using namespace std;

int main(){

	int t, n;
	cin >> t;

	for(int k = 1; k <= t; k++){
		cin >> n;
		int arr[n + 5];
		int j = n - 1;
		int res = 0;
		for(int i = 0; i <= (n + res); i++){
			if(arr[i] != arr[j]){
				res++;
			}else{
				j--;
			}
			if(i == j) break;
		}
		cout << "Sequence #" << k << ": " << res << endl;
	}


	return 0;
}