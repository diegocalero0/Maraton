#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2000 * 1000 + 10;
bool v[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int cases, n;
	cin >> cases;
	while(cases--){
		memset(v, 0, sizeof v);
		cin >> n;
		for(int i = 0; i < n; i++){
			long temp;
			cin >> temp;
			if(temp < MAXN)
				v[temp] = 1;
		}
		if(v[1] == 0){
			cout << v[1] << "\n";
		}else{
			for(int i = 2; i < MAXN; i++){
				if(v[i] == 0){
					cout << i - 1 << "\n";
					break;
				}else{
					for(int j = i + i; j < MAXN; j += i)
						v[j] = 1;
				}
			}
		}
	}

	return 0;
}