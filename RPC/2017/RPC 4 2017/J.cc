#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;

long long mod = 1000000000 + 7;

vector<long long> numberOfPrimesFactors(1000001, 0);
bool isPrime[1000001];
void criba(){
	for(int i = 0; i <= 1000000/2; i++)
		isPrime[i] = 1;
	isPrime[1] = isPrime[0] = 0;
	for(int i = 2; i <= 1000000; i++){
		if(isPrime[i]){
			numberOfPrimesFactors[i]++;
			for(int j = i * 2; j <= 1000000; j += i){
				isPrime[j] = 0;
				numberOfPrimesFactors[j]++;
			}
		}
	}
}

int main(){

	criba();

	long long n, x, y;
	
	
	while(cin >> n >> x >> y && (n + x + y)){
		long long ne = (y - x);
		long long result = 0;
		long long temp;
		long long mult = (((((ne % mod) * (((ne * ne) % mod - (3 * ne) % mod + 2) % mod)) % mod) / 6) + ne) % mod;
		for(int i = x; i < y - 1; i++){
			int dist = (y - i);
			temp = (mult * numberOfPrimesFactors[dist]) % mod; 
			result += temp;
			result %= mod;
		}
		cout << result << endl;
	}

	return 0;
}