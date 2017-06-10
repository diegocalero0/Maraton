#include<bits/stdc++.h>
using namespace std;

int main(){

	int n, curr, change;
	int arr[] = {0, 0, 0};
	cin >> n;
	bool flag = true;
	for(int i = 0; i < n; i++){
		cin >> curr;
		change = curr - 25;
		arr[(curr/25) - 1]++;	
		if(change){
			for(int i = 2; i >= 0; i--){
				while(change >= (i + 1) * 25 && arr[i] > 0){
					change -= (i + 1) * 25;
					arr[i]--;
				}
			}
			if(change != 0)
				flag = false;
		}
	}

	if(flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}
