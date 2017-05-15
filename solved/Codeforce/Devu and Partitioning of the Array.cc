#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
typedef __int64 LL;

int main(){

	LL n, k, p, temp, ptemp;
	cin >> n >> k >> p;
	ptemp = p;
	vector<LL> pares, impares, res[100005];
	for(int i = 0; i < n; i++){
		cin >> temp;
		if(temp % 2 == 0)
			pares.push_back(temp);
		else
			impares.push_back(temp);
	}

	bool flag = 0;
	if(impares.size() >= k - p){
		for(int i = 0; i < k - p; i++){
			res[i].push_back(impares.back());
			impares.pop_back();
		}

		if(impares.size() % 2 == 0 && ((impares.size() / 2) + pares.size()) >= p ){
			for(int i = k - p; i < k; i++){
				if(!impares.empty()){
					LL s = impares.back(); impares.pop_back();
					LL f = impares.back(); impares.pop_back();
					res[i].push_back(s);
					res[i].push_back(f);
				}else{
					LL s = pares.back(); pares.pop_back();
					res[i].push_back(s);
				}
			}

			while(!impares.empty()){
				LL s = impares.back(); impares.pop_back();
				res[k - 1].push_back(s);
			}

			while(!pares.empty()){
				LL s = pares.back(); pares.pop_back();
				res[k - 1].push_back(s);
			}
			cout << "YES" << endl;
			flag = 1;
			for(int i = 0; i < k; i++){
				cout << res[i].size();
				for(int j = 0; j < res[i].size(); j++){
					cout << " " << res[i][j];
				}
				cout << endl;
			}
		}
	}
	if(!flag)
		cout << "NO" << endl;

}