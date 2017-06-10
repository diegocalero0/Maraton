#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int main(){
	ll un[5000], potx[80], poty[80];
	ll x, y, l , r, res = 0;
	scanf("%lld %lld %lld %lld", &x, &y, &l, &r);
		
	ll pot = 1;
	int i1 = 0;
	potx[i1++] = pot;
	while(pot <= r / x){
		pot *= x;
		potx[i1++] = pot;
	}

	pot = 1;
	int i2 = 0;
	poty[i2++] = pot;
	while(pot <= r / y){
		pot *= y;
		poty[i2++] = pot;
	}
	int k = 0;
	for(int i = 0; i < i1; i++)
		for(int j = 0; j < i2; j++)
			if(potx[i] + poty[j] >= l && potx[i] + poty[j] <= r)
				un[k++] = potx[i] + poty[j];
	un[k++] = l - 1;
	un[k++] = r + 1;
	sort(un, un + k);
	for(int i = 0; i < k - 1; i++)
		res = max(res,un[i+1] - un[i]);
	res = res - 1;
	printf("%lld\n", res);
	return 0;
}
