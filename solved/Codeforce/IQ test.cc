#include<bits/stdc++.h>
using namespace std;

int main(){

	int n, curr, arr[105], rese = 0, reso = 0;
	cin >> n;
	int odd = 0, even = 0;
	for(int i = 0; i < n; i++){
		cin >> curr;
		if(curr % 2){
			even++;
			rese = i + 1;
		}else{
			odd++;
			reso = i + 1;
		}
	}

	if(even + odd == 1){
		cout << 1 << endl;
		return 0;
	}

	if(even < odd)
		cout << rese << endl;
	else
		cout << reso << endl;
	return 0;
}
