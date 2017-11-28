#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
const int N = 6e5 + 7;


const ll X = 137LL;
const ll X2 = 139LL;
const ll MOD = 1000000007;
const ll MOD2 = 1000000009;
const ll MULT = 1000000010LL;
#define mod(n) (((n)%MOD+MOD)%MOD)
#define mod2(n) (((n)%MOD2+MOD2)%MOD2)

ii r[N];
ii h[N];

ii getHash(const string &s){
	h[0].first = h[0].second = 0;
	r[0].first = r[0].second = 1;
	
	int len = s.length();
	for(int i = 1; i <= len; i++){
		r[i].first = mod(r[i - 1].first * X);
		r[i].second = mod2(r[i - 1].second * X2);
		h[i].first = mod(h[i - 1].first * X + s[i - 1]);
		h[i].second= mod2(h[i - 1].second * X2 + s[i - 1]);
	}
	return ii(h[len].first, h[len].second);
}

unordered_set<ll> hashes;

ll getNewHash(const string &s, ii hash, int pos, char newc){
	int len = s.length();
	ll a = mod(hash.first - mod(s[pos] * r[len - pos - 1].first) + mod(newc * r[len - pos - 1].first));
	ll b = mod2(hash.second - mod2(s[pos] * r[len - pos - 1].second) + mod2(newc * r[len - pos - 1].second));
	return 1LL * (a * MULT + b);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	ii currh;
	string curr;
	string query;
	cin >> n >> q;

	
	

	for(int i = 0; i < n; i++){
		cin >> curr;
		ii hs = getHash(curr);
		hashes.insert(1LL * hs.first * MULT + hs.second);
	}

	bool correct = false;

	while(q--){
		cin >> query;
		currh = getHash(query);
		correct = false;
		for(int i = 0; i < query.length() && !correct; i++){
			for(char c = 'a'; c <= 'c'; c++){
				if(query[i] != c){
					if(hashes.find(getNewHash(query, currh, i, c)) != hashes.end()){
						correct = true;
					}
				}
			}
		}


		if(correct == true){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}

	}

	return 0;
}