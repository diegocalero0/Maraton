#include<bits/stdc++.h>
using namespace std;
#define INF 1e9


struct ii
{
	int cnt, val;
	ii(){cnt = val = INF;}

	ii(int a, int b){cnt = a; val = b;}

	bool operator < (ii other) const{
		if(val != other.val)
			return val < other.val;
		return cnt < other.cnt;
	}

};

const int N = 100;

int den[N];
ii dp[N][10005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
  
	int t;
	cin >> t;
	int n, mount;
	while(t--){

		cin >> mount >> n;

		for(int i = 0; i < n; i++){
			cin >> den[i];
		}


		for(int i = 0; i < n; i++)
			dp[i][0] = ii(0, 0);
		for(int i = 0; i <= mount; i++){
			if(den[0] >= i){
				dp[0][i] = ii(1, den[0]);
			}else{
				dp[0][i] = ii(INF, INF);
			}
		}

		for(int i = 1; i < n ; i++){
			for(int j = 1; j <= mount; j++){
				if(den[i] >= j){
					dp[i][j] = min(dp[i - 1][j], ii(1, den[i]));
				}else{
					dp[i][j] = min(dp[i - 1][j], ii(1 + dp[i - 1][j - den[i]].cnt, den[i] + dp[i - 1][j - den[i]].val));
				}
			}
		}



		cout << dp[n - 1][mount].val << " " << dp[n - 1][mount].cnt << "\n";

	}



	return 0;
}
