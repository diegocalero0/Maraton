#include<bits/stdc++.h>
using namespace std;

struct query
{
	int l, r;
	long long c;
	query(int a, int b, long long c1){
		l = a;
		r = b;
		c = c1;
	}

	bool operator <(query o)const {
		if(l != o.l)
			return l < o.l;
		return r < o.r;

	}

};

const int N = 1e5 + 10;

long long P, Q, S;
int n;

query genQuery(int l, int r, int c){
	int L, R, C;
	L = (l * P + r) % n + 1;
	R = (r * Q + l) % n + 1;

	if(L > R)
    	swap(L , R);
	C = (c * S) % 1000000 + 1;
	return query(L, R, C);
}

int main(){

	int t, q;
	int l, r;
	long long c;
	cin >> t;

	while(t--){
		cin >> n >> q;
		cin >> l >> r >> c >> P >> Q >> S;

		vector<query> qs;
		qs.push_back(query(l, 1, c));
		qs.push_back(query(r + 1, -1, c));
		q--;
		while(q--){
			query curr = genQuery(l, r, c);

			l = curr.l;
			r = curr.r;
			c = curr.c;
			qs.push_back(query(l, 1, c));
			qs.push_back(query(r + 1, -1, c));
		}

		sort(qs.begin(), qs.end());

		long long cum = 0;
		long long best = 0;
		int pos = -1;
		for(int i = 0; i < qs.size(); i++){
			query qq = qs[i];
			if(qq.r == 1){
				cum += qq.c;
			}else{
				cum -= qq.c;
			}
			if(cum > best){
				best = cum;
				pos = qq.l;
			}
		}

		cout << pos << " " << best << endl;

	}

	return 0;
}