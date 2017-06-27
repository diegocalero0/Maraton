#include<bits/stdc++.h>
using namespace std;

int main(){

	int n, curr;
	set<int> s;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> curr;
		s.insert(curr);
	}


	cout << s.size() << endl;
	return 0;
}