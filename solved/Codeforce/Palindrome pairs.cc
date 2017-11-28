#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

const ll X = 137LL, X2 = 139LL;
const ll M1 = 1000000007LL;
const ll M2 = 1000000009LL;
const int N = 2005; 

#define mod(n, m) (((n) % m + m) % m)

ll h[N];
ll r[N];

ll rh[N];
ll rr[N];



void buildHash(string s){
	h[0] = rh[0] = 0;
	r[0] = rr[0] = 1;
	int n = s.length();
	for(int i = 1; i <= n; i++){
		r[i] = mod(r[i - 1] * X, M1);
		h[i] = mod(h[i - 1] * X + s[i - 1], M1);
	}

	reverse(s.begin(), s.end());

	for(int i = 1; i <= n; i++){
		rr[i] = mod(rr[i - 1] * X, M1);
		rh[i] = mod(rh[i - 1] * X + s[i - 1], M1);	
	}

}

int n;

bool isPalindrome(int i, int j){
	
	i++; j++;
	if(i == j)
		return true;
	int ni, nj;
	ni = n - j + 1; nj = n - i + 1;

	ll norm = mod(h[j] - mod(h[i - 1] * r[j - i + 1], M1), M1);
	ll reve = mod(rh[nj] - mod(rh[ni - 1] * rr[nj - ni + 1], M1), M1);

	return norm == reve;
}


vector<pair<int, int> > pal;

ll cont[N];
ll cont2[N];

int main(){


	string s;
	cin >> s;

	n = s.length();

	buildHash(s);

	for(int i = n - 1; i >= 0; i--){
		for(int j = 0; j <= i; j++){
			if(isPalindrome(j, i)){
				pal.push_back(make_pair(j, i));
				cont[j]++;
			}
		}
	}



	cont[n] = 0;
	for(int i = n - 1; i >= 0; i--){
		cont[i] += cont[i + 1];
	}

	


	ll res = 0LL;
	for(int i = 0; i < pal.size(); i++){
		res += cont[pal[i].second + 1];
	}

	cout << res << endl;

	return 0;
}