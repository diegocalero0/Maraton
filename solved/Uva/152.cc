#include<bits/stdc++.h>
using namespace std;

struct point
{
	double x, y, z;
	point(double x_, double y_, double z_):x(x_), y(y_), z(z_){};

	bool operator < (point o) const{
		if(x != o.x)
			return x < o.x;
		if(y != o.y)
			return x < o.y;
		return z < o.z;
	}
};

double dist(point p1, point p2){
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) + (p1.z - p2.z) * (p1.z - p2.z));
}

int main(){

	int x, y, z;
	vector<point> points;

	while(cin >> x >> y >> z && (x + y + z)){
		points.push_back(point(x, y, z));
	}

	double ds = 0.0;	
	sort(points.begin(), points.end());
	int res[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	for(int i = 0; i < points.size(); i++){
		int min_ = 100000;
		for(int j = 0; j < points.size(); j++){
			if(i != j){
				ds = dist(points[i], points[j]);
				if(ds < min_){
					min_ = (int)ds;
				}
			}
		}
		if(min_ < 10)
			res[min_]++;
	}

	for(int i = 0; i < 10; i++)
		printf("%4d", res[i]);
	printf("\n");
	return 0;
}
