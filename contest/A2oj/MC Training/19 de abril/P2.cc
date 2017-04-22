#include<bits/stdc++.h>
using namespace std;
typedef pair<double, double> ii;

double minDist(ii p1, ii p2){
	return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}

int compareY(const void* a, const void* b)
{
    ii *p1 = (ii *)a,   *p2 = (ii *)b;
    return (p1->second - p2->second);
}

double stripClosest(ii strip[], int size, double d)
{
    double min = d;  
 
    qsort(strip, size, sizeof(ii), compareY); 
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].second - strip[i].second) < min; ++j)
            if (minDist(strip[i],strip[j]) < min)
                min = minDist(strip[i], strip[j]);
 
    return min;
}

double complete(int n, ii p[]){
	double mini = 10000000;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			mini = min(mini, minDist(p[i], p[j]));
		}
	}
	return mini;
}

double divideAndConque(ii p[], int n){
	if(n <= 3)
		return complete(n, p);
	int mid = n / 2;
	ii midPoint = p[mid];

 	double dl = divideAndConque(p, mid);
    double dr = divideAndConque(p + mid, n-mid);
    double d = min(dl, dr);

    ii cut[n];
    int j = 0;
    for(int i = 0; i < n; i++){
    	if(abs(p[i].first - midPoint.first) < d)
    		cut[j++] = p[i];
    } 

    return min(d, stripClosest(cut, j, d));
}

int main(){
	int n;
	double x, y;
	vector<ii> points;
	while(cin >> n && n){
		points.clear();
		for(int i = 0; i < n; i++){
			cin >> x >> y;
			points.push_back(ii(x, y));
		}
		sort(points.begin(), points.end());
		ii p[n];
		for(int i = 0; i < n; i++)
			p[i] = points[i];
		double res = divideAndConque(p, n);
		if(res < 10000)
			printf("%.4f\n", res);
		else
			cout << "INFINITY" << endl;

	}
	return 0;
}