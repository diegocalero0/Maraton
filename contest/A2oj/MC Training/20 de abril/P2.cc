#include<bits/stdc++.h>
using namespace std;

int main(){

	int t, n, m;
	string temp;
	vector<string> names;
	cin >> t;
	map<string, int> wins;
	map<string, int> goals;
	map<string, int> points;
	while(t--){
		int n, m;
		wins.clear();
		names.clear();
		goals.clear();
		points.clear();
		cin >> n >> m;
		for(int i = 0; i < n; i++){
			cin >> temp;
			names.push_back(temp);
			wins[temp] = 0;
			goals[temp] = 0;
			points[temp] = 0;
		}
		while(m--){
			int x, y;
			string teamx, teamy;
			cin >> x >> teamx >> y >> teamy;
			goals[teamx] += x;
			goals[teamy] += y;
			if(x > y){
				wins[teamx]++;
				points[teamx] += 3;
			}else if(x < y){
				wins[teamy]++;
				points[teamy] += 3;
			}else{
				points[teamx]++;
				points[teamy]++;
			}
		}

		for(int i = 0; i < n - 1; i++){
			for(int j = 0; j < n - i - 1; j++){
				string j1 = names[j], j2 = names[j + 1];
				if(points[j1] < points[j2]){
					string temp = names[j];
					names[j] = names[j + 1];
					names[j + 1] = temp;
				}else if(points[j1] == points[j2]){
					if(wins[j1] < wins[j2]){
						string temp = names[j];
						names[j] = names[j + 1];
						names[j + 1] = temp;
					}else if(wins[j1] == wins[j2]){
						if(goals[j1] < goals[j2]){
							string temp = names[j];
							names[j] = names[j + 1];
							names[j + 1] = temp;
						}
					}
				}

			}
		}
		for(int i = 0; i < names.size(); i++){
			cout << names[i] << endl;
		}
	}

	return 0;
}