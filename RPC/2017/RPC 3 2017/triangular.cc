#include<bits/stdc++.h>
using namespace std;
vector<long long> pre;


void findPair(int level, long long n){
	long long min = 2 + 8 * ( (level * (level + 1)) / 2);
	if(n <= min){
		long long b = min - (2 * level + 1);
		cout << (b - n) << " " << (level * -1) << "\n";
	}else{
		long long b = min + (2 * level + 1);
		long long x = n - b;
		long long y;
		long long max = 4 * (level + 2) * (level + 2) - 10 * (level + 2) + 7;
		if(x <= 0){
			long long by = max - (level + 1);
			y = n - by;
		}else{
			long long by = max + (level + 1);
			y = -n + by;
		}
		cout << x << " " << y << "\n";
	}
}

int binSearch(long long n){
	int min = 0;
	int max = pre.size() - 1;
	int m;
	while(max >= min){
		m = (min + max) / 2;
		if(pre[m] == n)
			return m;
		else if(pre[m] > n)
			max = m - 1;
		else
			min = m + 1;
	}

	return min;
}

void preCal(){
	long long n2 = 1000000000000;
	long long i = 1;
	long long cum = 4;
	long long incre = 12;
	pre.push_back(cum);
	while(cum < n2){
		cum += incre;
		incre += 8;
		i++;
		pre.push_back(cum);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	preCal();
	int t;
	long long n;
	cin >> t;
	while(t--){
		cin >> n;
		int level = binSearch(n);
		findPair(level, n);
	}

	return 0;
}
