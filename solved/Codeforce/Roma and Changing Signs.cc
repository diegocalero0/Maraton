#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n, k, curr;
	long sum = 0;
	vector<int> v;
	cin >> n >> k;

	int i;

	for(int i = 0; i < n; i++){
		cin >> curr;
		v.push_back(curr);
	}
	
	for(int i = 0; i < v.size() && k > 0; i++){
		if(v[i] < 0)
			v[i] = -v[i], k--;
	}
	
	int minin = 100000;
	for(int i = 0; i < n; i++){
		sum += v[i];
		minin = min(minin, v[i]); 
	}

	if(k % 2 != 0 && k > 0)
		sum -= minin * 2;

	cout << sum << endl;

	return 0;
}