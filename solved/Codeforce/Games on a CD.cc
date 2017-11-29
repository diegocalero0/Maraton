#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

const ll MOD1 = 1000000007LL;
const ll MOD2 = 1000000009LL;
const ll MOD3 = 1000000010LL;
const ll X1 = 137;
const ll X2 = 139;
const int N = 2e6 + 7;

#define mod(n, m) (((n) % m + m) % m)

ii h[N];
ii r[N];

ii getHash(string s){
	h[0].first = h[0].second = 0;
	r[0].first = r[0].second = 1;
	int n = s.length();
	for(int i = 1; i <= n; i++){
		r[i].first = mod(r[i - 1].first * X1, MOD1);
		r[i].second = mod(r[i - 1].second * X2, MOD2);

		h[i].first = mod(h[i - 1].first * X1 + s[i - 1], MOD1);
		h[i].second = mod(h[i - 1].second * X2 + s[i - 1], MOD2);
	}

	return ii(h[n].first, h[n].second);

}

unordered_map<ll, int> hashes;
unordered_set<int> st;
ii getHash(ii hs, int i, int j){
	int len = j - i + 1;
	ll a = mod(h[j].first - mod(h[i - 1].first * r[len].first, MOD1), MOD1);
	ll b = mod(h[j].second - mod(h[i - 1].second * r[len].second, MOD2), MOD2);
	return ii(a, b);
}

int main(){


	int n, k, m, i, initlen;
	string s, curr;

	cin >> n;
	cin >> k;
	cin >> s;
	cin >> m;
	initlen = s.length();
	
	ii currh;
	for(int i = 0; i < m; i++){
		cin >> curr;
		if(curr.length() != k)
			continue;
		currh = getHash(curr);
		hashes[currh.first * MOD3 + currh.second] = i + 1;
		
	}


	s += s;
	ii shash = getHash(s);
	vector<int> sol;
	for(int i = 0; i < k; i++){
		int cont = 0;
		int j = i;
		sol.clear();
		st.clear();
		while(cont < n){

			currh =  getHash(shash, j + 1, j + k);
			
			int res = hashes[currh.first * MOD3 + currh.second];
			if(res == 0 || st.find(res) != st.end())
				break;
			st.insert(res);
			sol.push_back(res);
			cont++;
			j += k;
		}

		if(cont == n){
			cout << "YES" << endl;
			cout << sol[0];
			for(int b = 1; b < n; b++)
				cout << " "<< sol[b];
			cout << endl;
			return 0;
		}
	}

	cout << "NO" << endl;
	return 0;
}