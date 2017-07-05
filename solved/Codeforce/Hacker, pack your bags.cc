#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define here cout << "entro" << endl;

struct state
{
	int l, r, duration;
	long long cost;
	state(int a, int b, long long c){
		l = a;
		r = b;
		cost = c;
		duration = r - l + 1;
	};

	state(){l = r = 0; duration = cost = 0;};

};

bool forL(const state &i, const state &j){
	return i.l < j.l;
}

bool forR(const state &i, const state &j){
	return i.r < j.r;
}

int main(){
	
	int n, x, l, r, k;
	long long cost;

	cin >> n >> x;
	
	state L[n], R[n];
	
	vector<long long> duration(200100, 1e18);

	for(int i = 0; i < n; i++){
		cin >> l >> r >> cost;
		L[i] = state(l, r, cost);
		R[i] = L[i];
	}
	sort(L, L + n, forL);
	sort(R, R + n, forR);
	long long res = 1e18;
	int j = 0;
	for(int i = 0; i < n; i++){
		state curr = L[i];

		while(j < n && R[j].r < curr.l){
			duration[R[j].r - R[j].l + 1] = min(duration[R[j].r - R[j].l + 1], R[j].cost);
			j++;
		}

		int d = x - (curr.r - curr.l + 1);
		if(d > 0 && duration[d] != 1e18)
			res = min(res, duration[d] + curr.cost);
	}

	if(res != 1e18) cout << res << endl;
	else cout << -1 << endl;
	return 0;
}