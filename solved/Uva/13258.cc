#include<bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl;
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

const ll MOD1 = 1000000007;
const ll MOD2 = 1000000009;
const ll MOD3 = 1000000010;

const ll X1 = 137;
const ll X2 = 139;
const int N = 1e5 + 7; 

#define mod(n, m) (((n) % m + m) % m)
ii h[N], ph[N];
ii r[N];


ii c1, c2;
int bs(int k, int plen){
	int l = 1, ri = plen;
	int m;
	int result = -1;
	while(l <= ri){
		m = (l + ri) / 2;
		c1.first = mod(ph[plen].first - mod(ph[m - 1].first * r[plen - m + 1].first, MOD1), MOD1);
		c1.second = mod(ph[plen].second - mod(ph[m - 1].second * r[plen - m + 1].second, MOD2), MOD2);
		c2.first = mod(h[plen + k].first - mod(h[m - 1 + k].first * r[plen - m + 1].first, MOD1), MOD1);
		c2.second = mod(h[plen + k].second - mod(h[m - 1 + k].second * r[plen - m + 1].second, MOD2), MOD2);

		if(c1.first * MOD3 + c1.second == c2.first * MOD3 + c2.second){
			ri = m - 1;
			result = m;
		}else{
			l = m + 1;
		}
	}

	
	return (result != -1 ? plen - result + 1 : 0);

}

int bs2(int k, int plen){
	int l = 1, ri = plen;
	int m;
	int result = -1;
	while(l <= ri){
		m = (l + ri) / 2;
		c1.first = ph[m].first;
		c1.second = ph[m].second;
		c2.first = mod(h[m + k].first - mod(h[k].first * r[m].first, MOD1), MOD1);
		c2.second = mod(h[m + k].second - mod(h[k].second * r[m].second, MOD2), MOD2);

		if(c1.first * MOD3 + c1.second == c2.first * MOD3 + c2.second){
			l = m + 1;
			result = m;;
		}else{
			ri = m - 1;
		}
	}

	return (result != -1 ? result: 0);
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s, p;
	int k, len, plen;
	int cases;
	cin >> cases;
	while(cases--){
		cin >> s >> p >> k;
		len = s.length(), plen = p.length();

		h[0].first = h[0].second = 0;
		r[0].first = r[0].second = 1;
		
		ph[0].first = ph[0].second = 0;

		for(int i = 1; i <= len; i++){
			r[i].first = mod(r[i - 1].first * X1, MOD1);
			r[i].second = mod(r[i - 1].second * X2, MOD2);

			h[i].first = mod(h[i - 1].first * X1 + s[i - 1], MOD1);
			h[i].second = mod(h[i - 1].second * X2 + s[i - 1], MOD2);


			if(i <= plen){
				ph[i].first = mod(ph[i - 1].first * X1 + p[i - 1], MOD1);
				ph[i].second = mod(ph[i - 1].second * X2 + p[i - 1], MOD2);
			}

		}

		int res = 0, n1, n2;

		for(int i = 0; i <= len - plen; i++){
			n1 = bs(i, plen);
			n2 = bs2(i, plen);
			if(n1 + n2 >= plen - k)
				res++;
		}

		cout << res << "\n";
	}
	
	return 0;
}