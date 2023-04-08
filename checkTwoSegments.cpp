#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define itr iterator
#define ritr reverse_iterator
#define pint pair<int, int>
#define pll pair<ll, ll>
#define S second
#define F first
#define v(a) vector<a>
#define mk(a, b) make_pair(a, b)
#define psh(a) push_back(a)
#define mem(arr, a) memset(arr, a, sizeof(arr))
#define pr(n) printf("%d\n", n)
#define sc(n) scanf ("%d", &n)
#define scll(n) scanf ("%lld", &n)
#define prll(n) printf("%lld\n", n)
#define MOD 1000000007ll
#define inf 1000000000ll

typedef struct {
	int x, y;
}point;

int max (int x, int y) {
	if (x > y) {
		return x;
	}else {
		return y;
	}
}

int min (int x, int y) {
	if (x < y) {
		return x;
	}else {
		return y;
	}
}

int orientation (point a, point b, point c) {
	int o =  ((b.y - a.y)*(c.x - b.x) - (c.y - b.y)*(b.x - a.x));
	if(o == 0) {
		return 0;
	}else if (o < 0) {
		return 1;
	}else {
		return 2;
	}
}

int segment (point a, point b, point c) {
	if ((b.x <= max (a.x, c.x) && b.x >= min(a.x, c.x)) && (b.y <= max (a.y, c.y) && b.y >= min(a.y, c.y))) {
		return 1;
	}else {
		return 0;
	}
}

int check (point p1, point p2, point q1, point q2) {
	int o1 = orientation (p1, p2, q1);
	int o2 = orientation (p1, p2, q2);
	int o3 = orientation (q1, q2, p1);
	int o4 = orientation (q1, q2, p2);

	if (o1 != o2 && o3 != o4) {
		return 1;
	}
	if (o1 == 0 && segment (p1, q1, p2)) {
		return 1;
	}
	if (o2 == 0 && segment (p1, q2, p2)) {
		return 1;
	}
	if (o3 == 0 && segment (q1, p1, q2)) {
		return 1;
	}
	if (o4 == 0 && segment (q1, p2, q2)) {
		return 1;
	}
	return 0;
}

int main (void) {
	point p1, p2, q1, q2;
	cin>>p1.x>>p1.y;
	cin>>p2.x>>p2.y;
	cin>>q1.x>>q1.y;
	cin>>q2.x>>q2.y;

	if (check (p1, p2, q1, q2)) {
		cout<<"Yes they intersect"<<endl;
	}else {
		cout<<"NO they don't intersect"<<endl;
	}
	return 0;
}
