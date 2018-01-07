/*
Author: Ayman Salah

Category: dynamic programming

Idea:
- let your dp state (cur idx, number of left insertions so far, number of right insertions so far)
- as k will be not more that 20 you complexity should be n*20*20
*/

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
#define sortaa(a,n) sort(a,a+n)
#define sortad(a,n) sort(a,a+n),reverse(a,a+n)
#define sfi1(v) scanf("%d",&v)
#define sfi2(v1,v2) scanf("%d %d",&v1,&v2)
#define sfi3(v1,v2,v3) scanf("%d %d %d",&v1,&v2,&v3)
#define sfll1(v) scanf("%I64d",&v);
#define sfll2(v1,v2) scanf("%I64d %I64d",&v1,&v2)
#define sfll3(v1,v2,v3) scanf("%I64d %I64d %I64d",&v1,&v2,&v3)
#define sfstr(v) scanf("%s", v);
#define sz(v) (int)v.size()
#define ndl puts("")
#define SS stringstream
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

void PLAY() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cout << fixed << setprecision(10);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int dp[10005][25][25];
int n, a[10005], k;

int solve(int idx, int l, int r) {
	int left = idx;
	int right = n - idx - 1 - l + r;;
	if (left >= right) return 0;
	int &ret = dp[idx][l][r];
	if (ret != -1) return ret;
	if (l + r > k) return ret = 25;
	ret = 0;
	if (a[left] == a[right])
		return ret = solve(idx + 1, l, r);

	ret = 1 + solve(idx + 1, l, r + 1);
	ret = min(ret, 1 + solve(idx, l + 1, r));
	return ret;
}

int main() {
	PLAY();

	int t;
	cin >> t;
	int test = 1;
	while (t--) {
		cout << "Case " << test++ << ": ";
		cin >> n >> k;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		memset(dp, -1, sizeof dp);
		int res = solve(0, 0, 0);
		if (res == 0)
			cout << "Too easy" << "\n";
		else if (res > k)
			cout << "Too difficult" << "\n";
		else
			cout << res << "\n";
	}

	return 0;
}
