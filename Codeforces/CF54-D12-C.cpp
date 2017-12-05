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
#define flush fflush(stdout)
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

ll count_ones(ll cur) {
	if (cur == 0) return 0;
	if (cur == 1) return 1;
	ll tmp = cur;
	ll cnt = 0;
	while (tmp) tmp /= 10, cnt = cnt * 10 + 1;
	tmp = cur;
	while (tmp > 1) tmp /= 10;
	if (tmp != 1) return cnt;
	ll digits = 0;
	tmp = cur;
	while (tmp) tmp /= 10, digits++;
	ll num = 1;
	digits--;
	while (digits--) num *= 10;
	cnt /= 10;
	return cnt + (cur - num + 1);
}


int n, mx;
ll l[1005], r[1005];
double dp[1005][1005];

double solve(int i, int cnt) {
	if (i == n) {
		if (cnt >= mx) return 1;
		return 0;
	}
	double &ret = dp[i][cnt];
	if (ret != -1) return ret;
	ll count = count_ones(r[i]) - count_ones(l[i] - 1);
	double ones = 1.0*count / (r[i] - l[i] + 1);
	ret = (1 - ones) * solve(i + 1, cnt);
	ret += ones * solve(i + 1, cnt + 1);
	return ret;
}

int main() {
	PLAY();

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> l[i] >> r[i];
	int k;
	cin >> k;

	mx = (k * n) / 100;
	mx += bool((k * n) % 100);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dp[i][j] = -1;
	cout << solve(0, 0) << endl;

	return 0;
}
