#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;

typedef pair<int, int> ii;


int main(){
	map<int, int> mp;
	priority_queue<int> pq;
	int n, curr, cont;

	cin >> n;

	for(int i = 0; i < n * n; i++){
		cin >> curr;
		mp[curr]++;
		pq.push(curr);
	}

	vector<int> res;

	while(!pq.empty()){
		curr = pq.top();
		pq.pop();
		if(!mp[curr]) continue;
		cout << curr << " ";
		mp[curr]--;
		if(res.size() == n)
			break;
		for(int j = 0; j < res.size(); j++){
			int gcd = __gcd(res[j], curr);
			mp[gcd] -= 2;
		}
		res.push_back(curr);

	}
	cout << endl;
	return 0;
}