#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
struct point
{
	double x, y;
	point(){x = y = 0;};
	point(double a, double b):x(a), y(b){};

	bool operator <(point o) const{
		return x < o.x;
	}
};

struct segment
{
	point a, b;
	segment(){};
	segment(point x, point y):a(x), b(y){};
};

double getX(segment s, point b){
	double m = double(s.a.y - s.b.y) / (s.a.x - s.b.x);
	double x = ((b.y - s.a.y) / m) + s.a.x;
	return x;
}

double dist(point a, point b){
	return hypot(a.y - b.y, a.x - b.x);
}

int main(){

	int t, n;
	double x, y;
	cin >> t;
	vector<point> points;
	vector<segment> segments; 
	while(t--){
		points.clear();
		segments.clear();
		cin >> n;
		while(n--){
			cin >> x >> y;
			points.push_back(point(x, y));
		}

		sort(points.begin(), points.end());
		for(int i = 0; i < points.size() - 1; i++)
			if(points[i].y > points[i + 1].y)
				segments.push_back(segment(points[i], points[i + 1]));
		double res = 0.0;
		for(int i = 0; i < segments.size() - 1; i++){
			segment next;
			int k;
			bool flag = false;
			for(int j = i + 1; j < segments.size(); j++){
				if(segments[j].a.y < segments[i].a.y && segments[j].a.y >= next.a.y){
					next = segments[j];
					k = j;
					flag = true;
				}else if(segments[j].a.y >= segments[i].a.y){
					k = j;
					flag = false;
					break;
				}
			}
			if(flag){
				double sum = dist(segments[i].a, point(getX(segments[i], next.a), next.a.y));
				res += dist(segments[i].a, point(getX(segments[i], next.a), next.a.y));
				i = k - 1;
			}
		}
		res += dist(segments[segments.size() - 1].a, segments[segments.size() - 1].b);
		printf("%.2f\n", res);
	}

	return 0;
}