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

int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

ll gcd(ll first, ll second) { return !second ? first : gcd(second, first % second); }
ll lcm(ll first, ll second) { return (first / gcd(first, second)) * second; }

void PLAY() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cout << fixed << setprecision(15);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

const int MAX = 6e5;

ll n, r, k;
ll archers[MAX], dist[MAX];

bool valid(ll val) {
	memset(dist, 0, sizeof dist);
	ll tmp = 0, cursum = k;
	for (int i = 1; i <= n; ++i) {
		ll cur = val - archers[i] - tmp;
		if (cur < 0) {
			tmp += dist[i];
			continue;
		}
		if (cur > cursum) return false;
		cursum -= cur; tmp += cur; 
		ll idx = min(i + 2 * r, n);
		dist[idx] -= cur;
		tmp += dist[i];
	}
	return true;
}

int main() {
	PLAY();

	cin >> n >> r >> k;

	for (int i = 1; i <= n; i++) {
		cin >> archers[i];
		ll x = max(i - r, 1LL);
		ll y = min(i + r, n) + 1;
		dist[x] += archers[i];
		dist[y] -= archers[i];
	}

	for (int i = 1; i <= n; i++)
		archers[i] = archers[i - 1] + dist[i];
	
	ll lo = *min_element(archers + 1, archers + n + 1);
	ll hi = lo + k + 1, res = lo;

	while (lo  <= hi) {
		ll mid = (lo + hi) / 2;
		if (valid(mid)) {
			res = mid;
			lo = mid + 1;
		}
		else hi = mid - 1;
	}
	cout << res << endl;

	return 0;
}
