#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, h, m, ah[100], am[100], aw[100], n, res;
	scanf("%d", &T);
	for(int cases = 1; cases <= T; cases++){
		scanf("%d", &n);
		scanf("%d:%d", &h, &m);
		res = 10000000;
		for(int i = 0; i < n; i++){
			scanf("%d:%d %d", &ah[i], &am[i], &aw[i]);
			int dh;
			int dm;
			if(ah[i] > h){
				dh = ah[i] - h - 1;
				dm = am[i] + (60 - m) + aw[i];
				res = min(res, dh * 60 + dm);
			}else if(ah[i] < h){
				dh = 24 -(h - ah[i]) - 1;
				dm = am[i] + (60 - m) + aw[i];
				res = min(res, dh * 60 + dm);
			}else{
				if(am[i] < m){
					dh = 24;
					dm = -(m - am[i]) + aw[i];
					res = min(res, dh * 60 + dm);
				}else{
					dh = 0;
					dm = am[i] - m + aw[i];
					res = min(res, dm);
				}
			}
		}
		cout << "Case " << cases << ": " << res << "\n";
	}

	return 0;
}