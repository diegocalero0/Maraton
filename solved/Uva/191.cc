#include<bits/stdc++.h>
using namespace std;

struct point
{
	int x, y;
	point(int x_, int y_):x(x_), y(y_){};
};

bool onSegment(point p, point r, point q){
	if(r.x <= max(p.x, q.x) && r.x >= min(p.x, q.x) && r.y <= max(p.y, q.y) && r.y >= min(p.y, q.y))
		return true;
	return false;
}

int orientation(point p, point q, point r){
	int val = (q.y - p.y) * (r.x - q.x) - (r.y - q.y) * (q.x - p.x);
	if(val == 0)
		return 0;
	if(val > 0)
		return 1;
	return -1;
}

bool intersect(point p1, point q1, point p2, point q2){
	int o1 = orientation(p1, q1, p2);
	int o2 = orientation(p1, q1, q2);
	int o3 = orientation(p2, q2, p1);
	int o4 = orientation(p2, q2, q1);

	if(o1 != o2 && o3 != o4)
		return true;

	if(o1 == 0 && onSegment(p1, p2, q1))
		return true;
	if(o2 == 0 && onSegment(p1, q2, q1))
		return true;
	if(o3 == 0 && onSegment(p2, p1, q2))
		return true;
	if(o4 == 0 && onSegment(p2, q1, q2))
		return true;
	return false;
}

bool inside(int l, int r, int t, int b, point c){
	if(c.x >= l && c.x <= r && c.y >= b && c.y <= t)
		return true;
	return false;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	int xi, yi, xe, ye, x1, y1, x2, y2;
	while(t--){
		cin >> xi >> yi >> xe >> ye >> x1 >> y1 >> x2 >> y2;
		if(x1 > x2)
			swap(x1, x2);
		if(y1 < y2)
			swap(y1, y2);
		point p1(x1, y1);
		point p2(x2, y1);
		point p3(x2, y2);
		point p4(x1, y2);

		point i(xi, yi);
		point e(xe, ye);
		if(intersect(i, e, p1, p2) || intersect(i, e, p2, p3) || intersect(i, e, p3, p4) || intersect(i, e, p4, p1) || (inside(p1.x, p2.x, p2.y, p3.y, i) && inside(p1.x, p2.x, p2.y, p3.y, e)))
			cout << "T" << endl;
		else
			cout << "F" << endl;
	}

	return 0;
}