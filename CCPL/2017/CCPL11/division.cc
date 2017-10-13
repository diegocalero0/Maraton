#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;


int main(){

	int n;
	int ox, oy;
	int x, y;
	while(cin >> n && n){
		cin >> ox >> oy;
		ii o(ox, oy);

		while(n--){
			cin >> x >> y;

			

			if(x == o.first || y == o.second){
				cout << "divisa" << endl;
			}else if(x >= o.first && y >= o.second){
				cout << "NE" << endl;
			}else if(x >= o.first && y <= o.second){
				cout << "SE" << endl;
			}else if(x <= o.first && y <= o.second){
				cout << "SO" << endl;
			}else{
				cout << "NO" << endl;
			}

		}

	}



	return 0;
}