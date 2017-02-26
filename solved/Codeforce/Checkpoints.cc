#include<bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define debug(x) cout << #x << " = "<< x << endl
int main(){

	int n, a, curr;
	cin >> n >> a;
	vector<int> v;
	cout << 1e5 << endl;
	for(int i = 0; i < n; i++){
		cin >> curr;
		v.push_back(curr);
	}
	sort(v.begin(), v.end());

	int distI, distD, dist1,dist2;

	if(n > 1){
		distI = a - v[1];
		distD = v[n - 1] - a;
		if(distI > 0 && distD > 0)
			dist1 = min(2 * distI + distD, 2 * distD + distI);
		else if(distI <= 0)
			dist1 = v[n - 1] - a;
		else
			dist1 = a - v[1];
		distI = a - v[0];
		distD = v[n - 2] - a;
		if(distI > 0 && distD > 0)
			dist2 = min(2 * distI + distD, 2 * distD + distI);
		else if(distI <= 0)
			dist2 = v[n - 2] - a;
		else
			dist2 = a - v[0];
		cout << min(dist1,dist2) << "\n";
	}else
		cout << 0 << "\n";
	return 0;
}