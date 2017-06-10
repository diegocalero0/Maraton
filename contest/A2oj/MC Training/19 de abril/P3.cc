#include<bits/stdc++.h>
using namespace std;
int n = 1005;
bool prime[1005];

void sieve(){
    memset(prime, true, sizeof(prime));
 
    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
}

int main(){

	int n, m;
	sieve();
	cin >> n >> m;
	int p1, p2;
	for(int i = n; ; i--){
		if(prime[i]){
			p1 = i;
			break;
		}
	}
	for(int i = m; ; i--){
		if(prime[i]){
			p2 = i;
			break;
		}
	}
	cout << (p1 * p2) << endl;
	return 0;
}