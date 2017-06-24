#include<bits/stdc++.h>
using namespace std;

#define eps 1e-9

struct line
{
	double a, b, c;
	line(){a = 0; b = 0; c = 0;};

};

struct point
{
	double x, y;
	point(){x = y = 0;};
	point(double x_, double y_):x(x_), y(y_){};
};

line pointsToLine(point p1, point p2){
	line res;
	if(fabs(p1.x - p2.x) < eps){
		res.a = 1.0;
		res.b = 0;
		res.c = -p1.x;
	}else{
		res.a = -(double)(p1.y - p2.y)/(p1.x - p2.x);
		res.b = 1.0;
		res.c = -(double)(res.a * p1.x) - p1.y;
	}
	return res;
}


point c;

bool areParallel(line l1, line l2){
	return fabs(l1.a - l2.a) < eps && fabs(l1.b - l1.b) < eps;
}

bool areSame(line l1, line l2){
	return areParallel(l1, l2) && fabs(l1.c - l2.c) < eps;
}

bool areIntersect(line l1, line l2){
	c.x = (l1.b * l2.c - l2.b * l1.c)/(l2.b * l1.a - l1.b * l2.a);
	if(l1.b > eps)
		c.y = -(l1.c + l1.a * c.x);
	else
		c.y = -(l2.c + l2.a * c.x);

	return true;
}

/*
1 are same
2 are parallel
3 are intersect
*/
int solve(line l1, line l2){
	if(areSame(l1, l2))
		return 1;
	if(areParallel(l1, l2))
		return 2;
	if(areIntersect(l1, l2))
		return 3;
}

int main(){
	int t;
	point p1, p2, p3, p4;
	cin >> t;
	cout << "INTERSECTING LINES OUTPUT" << endl;
	while(t--){
		cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
		int sol = solve(pointsToLine(p1, p2), pointsToLine(p3, p4));
		if(sol == 1){
			cout << "LINE" << endl;
		}else if(sol == 2){
			cout << "NONE" <<  endl;
		}else{
			printf("POINT %.2f %.2f\n", c.x, c.y);
		}

	}
	cout << "END OF OUTPUT" << endl;
	return 0;
}