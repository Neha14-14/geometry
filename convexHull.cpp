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

point low;

int orientation (point a, point b, point c) {
	return ((b.y - a.y)*(c.x - b.x) - (c.y - b.y)*(b.x - a.x));
}

void swap (point * a, point * b) {
	point temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int dis (point a, point b) {
	return ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int cmp (const void * a, const void * b) {
	point * a1, * a2;
	a1 = (point*)a;
	a2 = (point*)b;
	int o = orientation (low, *a1, *a2);
	if (o == 0) {
		if (dis(low, *a1) <= dis(low, *a2)) {
			return -1;
		}else{
			return 1;
		}
	}else if (o < 0){
		return -1;
	}else if (o > 0) {
		return 1;
	}
}

void print (point * arr, int n) {
	int i;
	for (i = 0; i < n; i++) {
		cout<<arr[i].x<<" "<<arr[i].y<<endl;
	}
}


int main (void) {
	int n;
	sc (n);
	int i;
	point arr[n];
	for (i = 0; i < n; i++) {
		cin>>arr[i].x>>arr[i].y;
	}
	int min = 0;
	for (i = 1; i < n; i++) {
		if (arr[i].y < arr[min].y) {
			min = i;
		}else if (arr[i].y == arr[min].y) {
			if (arr[i].x < arr[min].x) {
				min = i;
			}
		}
	}
	swap (&arr[0], &arr[min]);
	low = arr[0];
	qsort (&arr[1], n-1, sizeof(point), cmp);
	point plane[n];
	int ctr = 0;
	plane[ctr] = arr[0];
	ctr++;
	for (i = 1; i < n-1; i++){
		if (orientation (low, arr[i], arr[i+1]) != 0) {
			plane[ctr] = arr[i];
			ctr++;
		}
	}
	plane[ctr] = arr[n-1];
	ctr++;
	//print(arr, n);

	point s[ctr];
	int end = 0;
	s[end] = plane[0];
	end++;
	s[end] = plane[1];
	end++;
	s[end] = plane[2];
	for (i = 3; i < ctr; i++) {
		while (end > 0 && orientation(plane[end-1], plane[end], plane[i]) >= 0) {
			end--;
		}
		end++;
		s[end] = plane[i];
	}
	cout<<"Points in clockWise order"<<endl;
	print(s, end+1);
	return 0;
}
