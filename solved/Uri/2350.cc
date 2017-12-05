#include<bits/stdc++.h>
#include<unordered_set>
#define mod(n, m) (((n) % m + m) % m)

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

const int N = 5e5 + 7;
const ll MOD1 = 1000000007;
const ll MOD2 = 1000000009;
const ll MOD3 = 1000000010;
const ll X1 = 137;
const ll X2 = 139;

ii h[N];
ii r[N];

int arr[N];
int pos[30];

void getHash(string s){
	h[0].first = h[0].second = 0;
	r[0].first = r[0].second = 1;

	int n = s.length();

	for(int i = 1; i <= n; i++){
		r[i].first = mod(r[i - 1].first * X1, MOD1);
		r[i].second = mod(r[i - 1].second * X2, MOD2);

		h[i].first = mod(h[i - 1].first * X1 + s[i - 1], MOD1);
		h[i].second = mod(h[i - 1].second * X2 + s[i - 1], MOD2);

	}

	return h[n].first * MOD3 + h[n].second;

}

ll getHashArr(int n){
	h[0].first = h[0].second = 0;
	r[0].first = r[0].second = 1;

	for(int i = 1; i <= n; i++){
		r[i].first = mod(r[i - 1].first * X1, MOD1);
		r[i].second = mod(r[i - 1].second * X2, MOD2);

		h[i].first = mod(h[i - 1].first * X1 + (arr[i - 1] == -1 ? '*' : arr[i - 1]), MOD1);
		h[i].second = mod(h[i - 1].second * X2 + (arr[i - 1] == -1 ? '*' : arr[i - 1]), MOD2);

	}

	return h[n].first * MOD3 + h[n].second;

}

int main(){

	string s;
	int n, len;

	cin >> s >> n;
	len = s.length();
	for(int i = 0; i <= 26; i++)
		pos[i] = -1;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		int temp = arr[i];
		if(pos[arr[i]] != -1)
			arr[i] = i - pos[arr[i]];
		else
			arr[i] = -1;
		pos[temp] = i;
	}

	ll phash = getHashArr(n);

	for(int i = 0; i <= 26; i++)
		pos[i] = -1;
	for(int i = 0; i < len; i++){
		char temp = s[i];
		if(pos[s[i] - 'a'] == -1){
			s[i] = '*';
		}else{
			s[i] = (i - pos[s[i] - 'a']) + 48;
		}
		pos[temp - 'a'] = i;
	}

	getHash(s);
	

	int res = 0;
	ii currh = h[n];
	for(int i = 0; i <= len - n; i++){
		if(currh.first * MOD3 + curr.second == phash)
				res++;
		if(s[i] != )
		if(i == 0){
			currh = h[n];
			
		}else{
			currh.first = mod(h[i + n].first - mod(h[i - 1].first * r[n].first, MOD1), MOD1);
			currh.second = mod(h[i + n].second - mod(h[i - 1].second * r[n].second, MOD2), MOD2);

			if(s[i] != '*'){
				int ps = (s[i] - 48)
				if(i + n - ps)
			}

		}
	}

	cout << res << endl;

	return 0;
}