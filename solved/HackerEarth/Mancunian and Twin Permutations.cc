#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N], b[N], res[N];
struct query
{
	int l, r, index, pos, flag;
	query(int l_, int r_, int index_, int pos_, int flag_){
		l = l_;
		r = r_;
		index = index_;
		pos = pos_;
		flag = flag_;
	}

	bool operator <(query q) const {
		return pos < q.pos;
	}
};

struct fw
{	
	
	int T[N];
	int n;

	fw(int m){
		n = m;
		for(int i = 0; i <= n; i++)
			T[i] = 0;
	}

	void update(int i, int value){
		if(i == 0) return;
		for(; i <= n; i += (i & -i)){
			T[i] += value;
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
	
	int n;
	cin >> n;

	int temp;
	for(int i = 1; i <= n; i++){
		cin >> temp;
		a[temp] = i;
	}
	for(int i = 1; i <= n; i++){
		cin >> b[i];
	}

	int q;
	cin >> q;

	int l1, r1,l2, r2;

	vector<query> qu;
	int k = 0;
	
	int q2 = q;
	while(q--){
		cin >> l1 >> r1 >> l2 >> r2;
		qu.push_back(query(l1,r1, k, r2, -1));
		qu.push_back(query(l1,r1, k, l2 - 1, 1));
		res[k++] = (r1 - l1 + 1);
	}

	sort(qu.begin(), qu.end());
	query curr(0,0,0,0,0);
	k = 0;
	fw f(n);
	for(int i = 0; i < qu.size(); i++){
		curr = qu[i];
		while(k <= curr.pos){
			f.update(a[b[k++]], 1);
		}
		res[curr.index] += curr.flag * f.query(curr.l, curr.r);
	}

	for(int i = 0; i < q2; i++){
		cout << res[i] << endl;
	}
	return 0;
}