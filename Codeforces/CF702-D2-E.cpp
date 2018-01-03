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


int nxt[100005];
ll w[100005];

int dp[100005][45];
ll sum[100005][45];
ll mn[100005][45];


int main() {
	PLAY();

	ll n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> nxt[i];
		dp[i][0] = nxt[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> w[i];
		sum[i][0] = w[i];
		mn[i][0] = w[i];
	}

	for (int step = 1; step < 45; step++) {
		for (int node = 0; node < n; node++) {
			dp[node][step] = dp[dp[node][step - 1]][step - 1];
			sum[node][step] = sum[node][step - 1] + sum[dp[node][step - 1]][step - 1];
			mn[node][step] = min(mn[node][step - 1], mn[dp[node][step - 1]][step - 1]);
		}
	}
	for (int i = 0; i < n; i++) {
		int cur_node = i;
		ll cur_sum = 0;
		ll cur_min = LLONG_MAX;
		ll rem = k;
		for (ll tmp = 44; tmp >= 0; tmp--) {
			if ((1LL << tmp) <= rem) {
				rem -= (1LL << tmp);
				cur_sum += sum[cur_node][tmp];
				cur_min = min(cur_min, mn[cur_node][tmp]);
				cur_node = dp[cur_node][tmp];
			}
		}
		cout << cur_sum << " " << cur_min << "\n";
	}

	return 0;
}
