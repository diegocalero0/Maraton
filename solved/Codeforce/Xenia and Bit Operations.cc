#include<bits/stdc++.h>
using namespace std;

const int N = 200000;

long T[2 * N];
long t[N];

void build(int i, int l, int r, int h){
	if(l > r)
		return;
	if(l == r){
		T[i] = t[l];
	}else{
		int mid = (r + l) / 2;
		build(2 * i, l, mid, h - 1);
		build(2 * i + 1, mid + 1, r, h - 1);
		if(h % 2 == 0){
			T[i] = T[i * 2] ^ T[i * 2 + 1];
		}else{
			T[i] = T[i * 2] | T[i * 2 + 1];
		}
	}
}

void update(int i, int l, int r, int p, long v, int h){
	if(l > r || l > p || r < p) return;
	if(l == r){
		T[i] = v;
	}else{
		int mid = (l + r) / 2;
		update(i * 2, l, mid, p, v, h - 1);
		update(i * 2 + 1, mid + 1, r, p, v, h - 1);
		if(h % 2 == 0){
			T[i] = T[i * 2] ^ T[i * 2 + 1];
		}else{
			T[i] = T[i * 2] | T[i * 2 + 1];
		}
	}
}

int query(int i, int l, int r, int ql, int qr, int h){
	if(ql <= l && qr >= r){
		return T[i];
	}
	if(r < ql || l > qr)
		return 0;
	int mid = (l + r) / 2;
	if(h % 2 == 0){
		return  query(i * 2, l, mid, ql, qr, h - 1) ^ query(i * 2 + 1, mid + 1, r, ql, qr, h - 1);
	}else{
		return  query(i * 2, l, mid, ql, qr, h - 1) | query(i * 2 + 1, mid + 1, r, ql, qr, h - 1);
	}
}

int main(){


	int n;
	int q;
	int h;
	cin >> n >> q;
	h = n;
	n = pow(2, n);

	for(int i = 1; i <= n; i++)
		cin >> t[i];
	build(1, 1, n, h);
	int p;
	long b;
	
	while(q--){
		cin >> p >> b;
		update(1, 1, n, p, b, h);
		cout << query(1, 1, n, 1, n, h) << endl;

	}
	return 0;
}