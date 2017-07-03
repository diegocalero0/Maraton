#include<bits/stdc++.h>
using namespace std;
#define INF 600
#define debug(x) cout << #x << " = " << x << endl;
int m_[200][200];
int r[200], c[200];

int main(){

	int n, m;
	cin >> n >> m;

	for(int i = 0; i < m; i++)
		c[i] = INF;
	for(int i = 0; i < n; i++){
		r[i] = INF;
		for(int j = 0; j < m; j++){
			cin >> m_[i][j];
			r[i] = min(r[i], m_[i][j]);
			c[j] = min(c[j], m_[i][j]);
		}
	}
	vector< pair<string, int> > res;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){

			while(m_[i][j] != 0){


				if(!(m_[i][j] == 0 && (r[i] != 0 || c[j] != 0))){
					if(m_[i][j] == 0) continue;	
					else if (r[i] == 0 && c[j] == 0 && m_[i][j] != 0){
						cout << -1 << endl;
						return 0;
					}

					if(c[j] == 0){
						res.push_back(make_pair("row", i));
						for(int k = 0; k < m; k++){
							m_[i][k]--;
							r[i] = min(r[i], m_[i][k]);
							c[k] = min(c[k], m_[i][k]);
						}
					}else if(r[i] == 0){
						res.push_back(make_pair("col", j));
						for(int k = 0; k < n; k++){
							m_[k][j]--;
							r[k] = min(r[k], m_[k][j]);
							c[j] = min(c[j], m_[k][j]);
						}
					}else{
						if(m > n){
							res.push_back(make_pair("row", i));
							for(int k = 0; k < m; k++){
								m_[i][k]--;
								r[i] = min(r[i], m_[i][k]);
								c[k] = min(c[k], m_[i][k]);
							}
						}else{
							res.push_back(make_pair("col", j));
							for(int k = 0; k < n; k++){
								m_[k][j]--;
								r[k] = min(r[k], m_[k][j]);
								c[j] = min(c[j], m_[k][j]);
							}
						}
					}

				}else{
					cout << -1 << endl;
					return 0;
				}
			}
		}																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																							
	}

	cout << res.size() << endl;
	for(int i = 0; i < res.size(); i++){
		cout << res[i].first << " " << res[i].second + 1 << endl;
	}

	return 0;
}
