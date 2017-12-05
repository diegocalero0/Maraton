#include<bits/stdc++.h>
using namespace std;

#define mod(n, m) (((n) % m + m) % m)

long long res = 0;
int m;
long long n;

void solved(int k){
	if(!k)
		return;
	stringstream ss;
	ss << k;
	string s1, s2;
	ss >> s1;
	s2 = s1;
	reverse(s2.begin(), s2.end());
	s1 = s1 + s2;
	stringstream ss2(s1);
	long long n;
	ss2 >> n;
	res = mod(res + n, m);
	solved(k - 1);

}

int main(){


	int n;
	cin >> n >> m;
	solved(n);

	cout << res << endl;

	return 0;
}