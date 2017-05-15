#include<bits/stdc++.h>
using namespace std;

int main(){

	int t, n, m, u, v;
	cin >> t;
	while(t--){
		vector<int> gr1(3, 0);
		vector<int> gr2(3, 0);

		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> u >> v;
			u--;
			v--;
			gr1[u]++;
			gr1[v]++;
		}
		cin >> m;
		for(int i = 0; i < m; i++){
			cin >> u >> v;
			u--;
			v--;
			gr2[u]++;
			gr2[v]++;
		}
		sort(gr1.begin(), gr1.end());
		sort(gr2.begin(), gr2.end());
		bool flag = true;
		for(int i = 0; i < 3; i++){
			if(gr1[i] != gr2[i]){
				flag = false;
				cout << "no" << endl;
				break;
			}
		}
		if(flag)
			cout << "yes" << endl;
	}

	return 0;
}

