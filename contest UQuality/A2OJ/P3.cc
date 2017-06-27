#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, curr, res = 0;

	cin >> n;
	int arr[4] = {0, 0, 0, 0};
	while(n--){
		cin >> curr;
		for(int i = 2; i <= 5; i++){
			if(curr % i == 0){
				arr[i - 2]++;
			}
		}
	}
	cout << arr[0] << " Multiplo(s) de 2" << endl;
	cout << arr[1] << " Multiplo(s) de 3" << endl;
	cout << arr[2] << " Multiplo(s) de 4" << endl;
	cout << arr[3] << " Multiplo(s) de 5" << endl;
	return 0;
}