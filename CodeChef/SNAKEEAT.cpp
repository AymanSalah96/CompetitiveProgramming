#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>
#include <assert.h>
using namespace std;

#define PI 3.14159265359
#define all(v) v.begin(),v.end()
#define sortva(v) sort(all(v))
#define sortvd(v) sort(v.rbegin(),v.rend())
#define sortaa(first,n) sort(first,first+n)
#define sortad(first,n) sort(first,first+n),reverse(first,first+n)
#define sfi1(v) scanf("%dist",&v)
#define sfi2(v1,v2) scanf("%dist %dist",&v1,&v2)
#define sfi3(v1,v2,v3) scanf("%dist %dist %dist",&v1,&v2,&v3)
#define sfll1(v) scanf("%I64d",&v);
#define sfll2(v1,v2) scanf("%I64d %I64d",&v1,&v2)
#define sfll3(v1,v2,v3) scanf("%I64d %I64d %I64d",&v1,&v2,&v3)
#define sfstr(v) scanf("%sum", v);
#define sz(v) (int)v.size()
#define ndl puts("")
#define flush fflush(stdout)
#define SS stringstream
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int di[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dj[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

ll gcd(ll first, ll second) { return !second ? first : gcd(second, first % second); }
ll lcm(ll first, ll second) { return (first / gcd(first, second)) * second; }

void PLAY() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cout << fixed << setprecision(5);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}


const int MAX = 1e5 + 10;
int a[MAX], n, q;
ll sum[MAX];

ll rangeSum(int l, int r) {
	return sum[r] - (l - 1 >= 0 ? sum[l - 1] : 0);
}

bool valid(int k, int x, int idx) { // a[idx] >= k
	ll need = 1LL * x * k - rangeSum(idx - x, idx - 1);
	int rem = idx - x;
	return rem >= need;
}

int main() {
	PLAY();
	
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> q;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		
		sortaa(a, n);
		sum[0] = a[0];
		for (int i = 1; i < n; i++)
			sum[i] = sum[i - 1] + a[i];

		while (q--) {
			int k;
			cin >> k;
			int idx = lower_bound(a, a + n, k) - a;
			int res = n - idx;
			int lo = 0, hi = idx - 1, best = 0;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				if (valid(k, mid, idx)) {
					best = mid;
					lo = mid + 1;
				}
				else
					hi = mid - 1;
			}
			cout << res + best << "\n";
		}
	}

	return 0;
}
