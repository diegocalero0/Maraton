#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
#define debug(x) cout << #x << " = " << x << endl;
long long dist(ii b1, ii b2){
	return (b1.first - b2.first) * (b1.first - b2.first) + (b1.second - b2.second) * (b1.second - b2.second);
}

int main(){

	int c, n, x, y, res;
	cin >> c;
	ii bw;
	while(c--){
		long long min = 1LL << 50;
		cin >> n;
		cin >> x >> y;
		bw = ii(x, y);
		for(int i = 1; i <= n; i++){
			cin >> x >> y;
			ii temp = ii(x, y);
			long long distTemp = dist(bw, temp);
			if(distTemp < min){
				min = distTemp;
				res = i;
			}
		}
		cout << res << endl;
	}

	return 0;
}