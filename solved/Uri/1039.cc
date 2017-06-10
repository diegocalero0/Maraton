#include<bits/stdc++.h>
using namespace std;

double dist(int x1, int y1, int x2, int y2){
	return hypot(x2 - x1, y2 - y1);
}

int main(){

	int r1, x1, y1, r2, x2, y2;

	while(scanf("%d %d %d %d %d %d", &r1, &x1, &y1, &r2, &x2, &y2) != EOF){
		double distCenters = dist(x1, y1, x2, y2);
		if(distCenters > r1 - r2)
			printf("MORTO\n");
		else
			printf("RICO\n");
	}

	return 0;
}
