#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;

typedef long long ll;

vector<ll> sum;
vector<ll> arr;

bool binary_s(int l, int r, ll value){
	while(l <= r){
		int m = l + (r - l) / 2;

		if(sum[m] == value)
			return 1;

		if(sum[m] > value){
			r = m - 1;
		}else{
			l = m + 1;
		}
	}
	return 0;
}

int main(){

	int n;
	ll curr;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> curr;
		arr.push_back(curr);
		if(i > 0)	
			sum.push_back(sum[i - 1] + arr[i]);
		else
			sum.push_back(arr[i]);
	}

	if(sum[n - 1] % 2 != 0){
		cout << "NO" << endl;
		return 0;
	}

	for(int i = 0; i < n; i++){
		if(sum[i] * 2 == sum[n - 1]){
			cout << "YES" << endl;
			return 0;
		}
	}
	
	for(int i = 0; i < n; i++){
		if(binary_s(i + 1, n - 1, (sum[n - 1] / 2) + arr[i])){
			cout << "YES" << endl;
			return 0;
		}
		if(binary_s(0, i - 1, (sum[n - 1] / 2) - arr[i])){
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
