#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int T[N];

struct fw
{
	int n;
	

	void build(int t[], int m){
		n = m;
		for(int i = 1; i <= n; i++){
			if(t[i] % 2 == 0){
				update(i, 1);
			}
		}
		
	}

	void update(int i, int v){
		for(; i <= n; i +=(i & -i)){
			T[i] += v;
		}
	}

	int query(int i){
		int res = 0;
		for(; i > 0; i -= (i & -i)){
			res += T[i];
		}
		return res;
	}

	int query(int l, int r){
		return query(r) - query(l - 1);
	}

};

int main(){


	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int t[n + 5];

	for(int i = 1; i <= n; i++){
		cin >> t[i];
	}

	fw f;
	f.build(t, n);

	int q;
	cin >> q;

	int x, a, b;
	while(q--){
		cin >> x >> a >> b;
		if(!x){
			if(b % 2 == 0 && t[a] % 2 == 1){
				f.update(a, 1);
			}
			if(b % 2 == 1 && t[a] % 2 == 0){
				f.update(a, -1);
			}
			t[a] = b;
		}else if(x == 1){
			cout << f.query(a, b) << "\n";
		}else{
			cout << (b - a + 1) - f.query(a, b) << "\n";
		}
	}

	return 0;
}
