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

void print (int * arr, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf ("%d ", arr[i]);
	}
	printf ("\n");
}

int cmp (const void * a, const void * b) {
	int * a1, * a2;
	a1 = (int*)a;
	a2 = (int*)b;
	if (*a1 > *a2){
		return -1;
	}else {
		return 1;
	}
}

int main (void) {
	int n;
	int i;
	sc (n);
	int arr[n];
	for (i = 0; i < n; i++) {
		sc (arr[i]);
	}
	qsort (arr, n, sizeof(int), cmp);
	print(arr, n);
	return 0;
}
