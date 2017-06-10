#include<bits/stdc++.h>
using namespace std;

int main(){

	int d, sumTime;

	scanf("%d %d", &d, &sumTime);
	int min_[30], max_[30], diffTime = 0, minTime = 0, maxTime = 0;

	for(int i = 0; i < d; i++)
		scanf("%d %d", &min_[i], &max_[i]);

	for(int i = 0; i < d; i++){
		minTime += min_[i];
		maxTime += max_[i];
		diffTime = max_[i] - min_[i];
	}

	bool flag = 1;

	if(minTime > sumTime)
		flag = 0;
	if(minTime < sumTime && maxTime < sumTime)
		flag = 0;

	if(!flag){
		printf("NO\n");
		return 0;
	}

	printf("YES\n");
	vector<int> res;

	for(int i = 0; i < d; i++){
		int curr = max_[i];
		while(curr > min_[i] && maxTime > sumTime){
			curr--;
			maxTime--;
		}
		res.push_back(curr);
	}
	printf("%d", res[0]);
	for(int i = 1; i < d; i++)
		printf(" %d", res[i]);
	printf("\n");
	return 0;
}
