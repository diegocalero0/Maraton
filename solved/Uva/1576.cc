#include<bits/stdc++.h>
using namespace std;

int main(){

	int xi, h, xf, maxR = -1;
	int index = 0;
	vector<int> sol;
	vector<int> hs(15000, 0);
	while(cin >> xi >> h >> xf){
		for(int i = xi; i < xf; i++){
			hs[i] = max(hs[i], h);
		}
		maxR = max(maxR, xf);
	}
	int curr = 0;
	for(int i = 0; i < maxR + 1; i++){
		if(curr != hs[i]){
			sol.push_back(i);
			sol.push_back(hs[i]);
			curr = hs[i];
		}
	}

	cout << sol[0];
	for(int i = 1; i < sol.size(); i++){
		cout << " " << sol[i];
	}
	cout << endl;

	return 0;
}