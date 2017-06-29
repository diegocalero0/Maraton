#include<bits/stdc++.h>
using namespace std;

string s;
int n;
bool solved = false;
vector<int> sol;
void solve(int last, bool left, int l, int r, int ps){
	if(ps == n){
		cout << "YES" << endl;
		solved = true;
		for(int i = 0; i < n; i++)
			if(!i)
				cout << sol[i];
			else
				cout << " " << sol[i];
		cout << endl;
	}
	for(int i = 1; i <= 10; i++){
		if(s[i - 1] == '1' && i != last && !solved){
			if(left){
				if(l + i > r){
					sol.push_back(i);
					solve(i, !left, l + i, r, ps + 1);
					sol.pop_back();
				}
			}else{
				if(r + i > l){
					sol.push_back(i);
					solve(i, !left, l, r + i, ps + 1);
					sol.pop_back();
				}
			}
		}
	}
}

int main(){

	cin >> s >> n;
	solve(0, true, 0, 0, 0);
	if(!solved)
		cout << "NO" << endl;
	return 0;
}
