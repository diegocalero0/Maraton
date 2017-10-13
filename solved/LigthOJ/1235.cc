#include<bits/stdc++.h>
using namespace std;

const int N = 40;
const int MAX = 1e9 + 1;


long den[N];
int n;
void gsum(int u, long sum, int limit, vector<long> &sums){
	sums.push_back(sum);
	if(u == limit)
		return;
	gsum(u + 1, sum + den[u], limit, sums);
	gsum(u + 1, sum, limit, sums);
	gsum(u + 1, sum + (2 * den[u]), limit, sums);
}

int main(){

	int t;
	scanf("%d", &t);
	int cases = 1;
	int k;
	int naux;

	while(t--){
		
		scanf("%d%d", &n, &k);
		vector<long> sum1, sum2;
		for(int i = 0; i < n; i++){
			scanf("%ld", &den[i]);
		}

		int m = n / 2;
		gsum(0, 0, m, sum1);
		gsum(m, 0, n, sum2);
		sort(sum2.begin(), sum2.end());
		
		printf("Case %d: ", cases++);
	
		bool flag = false;
		for(int i = 0; i < sum1.size(); i++){
			if(binary_search(sum2.begin(),sum2.end(), k - sum1[i])){
				printf("Yes\n");
				flag = true;
				break;
			}
		}
		if(!flag){
			printf("No\n");
		}

	}

	return 0;
}