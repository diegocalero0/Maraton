#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
int main(){

	int n, k;
	cin >> n >> k;
	int arr[n];

	for(int i = 0; i < n; i++)
		cin >> arr[i];

	priority_queue<int, deque<int>, greater<int> > q;
	long long i = 0, solved = 0, currValue = 0, res = 0;
	while(solved < n){
		while(q.size() < k && i < n)
			q.push(arr[i++]);
		currValue += q.top(); q.pop();
		res += currValue;
		solved++;
	}
	cout << res << endl;
	return 0;
}