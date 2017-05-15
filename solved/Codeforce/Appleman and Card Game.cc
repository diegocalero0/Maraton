#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
typedef __int64 LL;
int main(){

	LL letters[30], temp, res, k;

	int n;
	char s[100010];

	cin >> n >> k >> s;
	for(int i = 0; i < 26; i++)
		letters[i] = 0;
	for(int i = 0; i < n; i++)
		letters[s[i] - 65]++;
	priority_queue<long long> pq;

	for(int i = 0; i < 26; i++){
		pq.push(letters[i]);
	}

	res = 0;
	while(k > 0){
		temp = pq.top();
		pq.pop();

		if(temp <= k){

			res += (temp * temp);
			k -= temp;
		}else{
			res += (k * k);
			k = 0;
		}
	}
	cout << res << endl;
	return 0;
}