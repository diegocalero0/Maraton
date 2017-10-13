#include<bits/stdc++.h>
using namespace std;

bool seen[5000];

int main(){

	int n;
	cin >> n;
	int arr[n];
	int res = 0;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}


	sort(arr, arr + n);

	for(int i = 0; i < n; i++){
		res++;
		if(i != n - 1 && abs(arr[i] - arr[i + 1]) <= 2){
			i++;
		}	
	}

	cout << res << endl;
	return 0;
}