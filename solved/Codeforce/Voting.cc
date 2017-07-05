#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	string s;

	cin >> n >> s;
	deque<int> r, d;

	for(int i = 0; i < n; i++)
		if(s[i] == 'D')
			d.push_back(i);
		else
			r.push_back(i);

	while(r.size() + d.size() > 1){
		if(r.size() > 0 && d.size() > 0){
			int currR = r.front(); r.pop_front();
			int currD = d.front(); d.pop_front();
			currR += n;
			currD += n;
			if(currR < currD){
				r.push_back(currR);
			}else{
				d.push_back(currD);
			}
		}else if(r.size() > 0){
			int currR1 = r.front(); r.pop_front();
			int currR2 = r.front(); r.pop_front();
			r.push_back(currR1 + n);
		}else{
			int currD1 = d.front(); d.pop_front();
			int currD2 = d.front(); d.pop_front();
			d.push_back(currD1 + n);
		}
	}

	if(r.size() > 0)
		cout << "R" << endl;
	else
		cout << "D" << endl;

	return 0;
}
