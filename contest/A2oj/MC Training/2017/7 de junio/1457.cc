#include<bits/stdc++.h>
using namespace std;

int main(){

	int n, m, i, k;
	long long res;
	string s;
	cin >> n;

	while(n--){
		i = 0;
		res = 1;
		cin >> m >> s;
		k = s.length();
		while(m - i * k >= 1){
			res *= (m - i * k);
			i++;
		}
		printf("%lld\n", res);
	}

	return 0;
}