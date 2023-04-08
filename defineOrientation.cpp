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

int orientation (point a, point b, point c) {
	return ((b.y - a.y)*(c.x - b.x) - (c.y - b.y)*(b.x - a.x));
}

int main (void) {

	point a, b, c;
	cin>>a.x>>a.y;
	cin>>b.x>>b.y;
	cin>>c.x>>c.y;

	int response = orientation (a, b, c);
	if (response == 0) {
		cout<<"Colinear Points"<<endl;
	}else if (response < 0) {
		cout<<"Left Turn (Counter)"<<endl;
	}else if (response > 0) {
		cout<<"Right Turn (ClockWise)"<<endl;
	}
	
	return 0;
}
