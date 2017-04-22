#include<bits/stdc++.h>
using namespace std;

int main(){

	int n, temp;
	cin >> n;
	vector<int> v(n + 5, 0);
	for(int i = 0; i < n - 1; i++){
		cin >> temp;
		v[--temp]++;
	}

	for(int i = 0; i < n; i++){
		if(v[i] == 0){
			cout << i + 1 << endl;
			break;
		}
	}

	return 0;
}