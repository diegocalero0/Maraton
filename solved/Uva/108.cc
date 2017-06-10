#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl
int main(){

	int n;
	cin >> n;
	int sum[150][150];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> sum[i][j];
			if(i > 0) sum[i][j] += sum[i - 1][j];
			if(j > 0) sum[i][j] += sum[i][j - 1];
			if(i > 0 && j > 0) sum[i][j] -= sum[i - 1][j - 1];
		}
	}

	int ans = 0, sumtemp = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			for(int k = i; k < n; k++)
				for(int l = j; l < n; l++){
					sumtemp = sum[k][l];
					if(i > 0) sumtemp -= sum[i - 1][l];
					if(j > 0) sumtemp -= sum[k][j - 1];
					if(i > 0 && j > 0) sumtemp += sum[i - 1][j - 1];
					ans = max(ans, sumtemp);
					//debug(ans);
				}
	cout << ans << endl;

	return 0;
}