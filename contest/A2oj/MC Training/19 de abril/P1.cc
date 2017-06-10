#include<bits/stdc++.h>
using namespace std;

int main(){

	int t;
	int n;
	cin >> t;
	while(t--){
		cin >> n;
		int arr[n];
		int res = 0;
		for(int i = 0; i < n; i++)
			cin >> arr[i];
		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				if(arr[i] > arr[j]){
					int aux = arr[i];
					arr[i] = arr[j];
					arr[j] = aux;
					res++;
				}
			}
		}
		cout << "Optimal train swapping takes "<< res << " swaps." << endl;
	}
	cin >> t;

	return 0;
}