#include<bits/stdc++.h>
using namespace std;
int n, m;
int matrix[2000][2000];

bool isValid(int i, int j){
	if(i >= 0 && i < n && j >= 0 && j < m)
		return true;
	return false; 
}

int movi[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int movj[8] = {1, -1, 0, 1, -1, 0, 1, - 1};

bool isPeek(int i, int j){
	for(int k = 0; k < 8; k++){
		if(isValid(i + movi[k], j + movj[k])){
			if(matrix[i + movi[k]][j + movj[k]] >= matrix[i][j])
				return false;
		}
	}
	return true;
}

int main(){
	while(cin >> n >> m){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		vector<pair<int, int> > res;
		for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					if(isPeek(i, j))
						res.push_back(make_pair(i + 1, j + 1));
				}
		}
		sort(res.begin(), res.end());
		for(int i = 0; i < res.size(); i++){
			cout << res[i].first << " " << res[i].second << endl;
		}
		if(res.size() == 0)
			cout << -1 << endl;
		cout << endl;
	}
	return 0;
}