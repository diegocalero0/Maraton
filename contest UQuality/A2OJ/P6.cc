#include<bits/stdc++.h>
using namespace std;

int main(){

	int t, n, k;
	double aveg, curr, maxN, newAveg, maxN2;
	cin >> t;
	while(t--){
		cin >> k >> n;
		while(n--){
			aveg = maxN = 0;
			maxN2 = 0;
			for(int i = 0; i < k; i++){
				cin >> curr;
				maxN = max(maxN, curr);
				if(curr < 7)
					maxN2 = max(maxN2, curr);
				aveg += curr;
			}
			aveg /= k;
			if(aveg >= 7.0){
				aveg = max(aveg, maxN);
			}else if(aveg >= 4.0 && aveg < 7){
				aveg = max(aveg, maxN2);
			}
			printf("%.2f\n", aveg);
		}
	}

	return 0;
}