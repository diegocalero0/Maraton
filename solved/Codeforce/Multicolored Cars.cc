#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main(){

	int n, A, curr;
	cin >> n >> A;
	A--;
	vii cars(1000000, ii(0, 1));
	vi colors;

	cars[A].second = 0;
	for(int i = 0; i < n; i++){
		cin >> curr;
		curr--;
		colors.push_back(curr);
		if(curr != A && cars[curr].first < cars[A].first)
			cars[curr].second = 0;
		cars[curr].first++;
	}

	for(int i = 0; i < n; i++){
		if(cars[colors[i]].second && cars[colors[i]].first >= cars[A].first){
			cout << colors[i] + 1 << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
