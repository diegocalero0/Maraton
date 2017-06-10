#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

vector<ii> points;
int n;

double pointToLineDistance(ii A, ii B, ii P){
    double normalLength = sqrt((B.first - A.first) * (B.first - A.first) + (B.second - A.second) * (B.second - A.second));
    return abs((P.first - A.first) * (B.second - A.second) - (P.second - A.second) * (B.first - A.first)) / normalLength;
}

bool isLeft(ii A, ii B, ii C){
     return ((B.first - A.first)*(C.second - A.second) - (B.second - A.second)*(C.first - A.first)) > 0;
}

double diference(ii p1, ii p2){
	double dist;
	double sumL = 0, sumR = 0;
	for(int i = 0; i < n; i++){
		ii p3 = points[i];
		dist = pointToLineDistance(p1, p2, p3);
		if(dist != 0){
			if(isLeft(p1, p2, p3))
				sumL += dist;
			else
				sumR += dist;
		}
	}
	return abs(sumL - sumR);
}

int main(){

	int x, y;

	while(cin >> n && n){
		points.clear();
		for(int i = 0; i < n; i++){
			cin >> x >> y;
			points.push_back(ii(x, y));
		}
		double res = 1000000;
		for(int i = 0; i < n; i++){
			ii p1 = points[i];
			for(int j = i + 1; j < n; j++){
				ii p2 = points[j];
				res = min(res, diference(p1, p2));
			}
		}
		printf("%.3f\n", res);
	}

	return 0;
}