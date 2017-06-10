#include<bits/stdc++.h>
using namespace std;


vector<long> start, end;
int s;
long intersections(){
	long i = 0, j = 0;
	long maxOver = 0, currOver = 0;
	while(i < s && j < s){
		if(start[i] < end[j]){
			currOver++;
			maxOver = max(maxOver, currOver);
			i++;
		}else{
			currOver--;
			j++;
		}
	}
	return maxOver;
}

int main(){
	int t, m;
	long n, a, b;
	
	cin >> t;
	while(t--){
		start.clear();
		end.clear();
		cin >> n >> m;
		s = m;
		while(m--){
			cin >> a >> b;
			start.push_back(a);
			end.push_back(b);
		}
		sort(start.begin(), start.end());
		sort(end.begin(), end.end());
		cout << intersections() << endl;
	}

}