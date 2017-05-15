#include<bits/stdc++.h>
using namespace std;

int main(){

	int n, c;

	long long highs[110], colors[110];
	long long minh = 0;
	bool seen[i];
	while(cin >> n >> c){
		for(int i = 0; i < n; i++){
			cin >> highs[i];
		}
		for(int i = 0; i < c; i++)
			cin >> colors[i];
		long long res = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < n; j++){
				minh = highs[i];
				for(int k = j + 1; (k - j) < i; k++){
					minh = min(minh, highs);
				}
				res = max(res, minh * i);
			}
		}

	}

	return 0;
}