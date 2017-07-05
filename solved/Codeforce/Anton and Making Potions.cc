#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
int a[N], b[N], c[N], d[N]; 
int n, m, k, x, s;

int best(int val){
	int l = 0, r = k, mid;

	while(l < r){
		mid = (l + r + 1) / 2;
		if(d[mid] <= val){
			l = mid;
		}else{
			r = mid - 1;
		}
	}

	return c[l];
}

int main(){

	cin >> n >> m >> k;
	cin >> x >> s;
	a[0] = x;
	b[0] = c[0] = 0;
	d[0] = 0;
	for(int i = 1; i <= m; i++) cin >> a[i];
	for(int i = 1; i <= m; i++) cin >> b[i];
	for(int i = 1; i <= k; i++) cin >> c[i];
	for(int i = 1; i <= k; i++) cin >> d[i];

	long long res = 1LL * n * x;
	for(int i = 0; i <= m; i++){
		if(s - b[i] >= 0)
			res = min(res, 1LL * (n - best(s - b[i])) * a[i]);
	}


	cout << res << endl;
	return 0;
}