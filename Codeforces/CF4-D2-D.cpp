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

int vis[5005];
pair<int, int> v[5005];
int n, h, w;
int dp[5005];

int solve(int node) {
	if (v[node].first < w || v[node].second < h) return 0;
	int &ret = dp[node];
	if (ret != -1) return ret;
	ret = 1;
	for (int j = 0; j < n; j++) {
		if (j == node) continue;
		if (v[j].first > w && v[j].second > h) {
			if (v[j].first < v[node].first && v[j].second < v[node].second)
				ret = max(ret, 1 + solve(j));
		}
	}
	return ret;
}
vector<int> ress;
void build(int node) {
	int ret = 1;
	int nxt = -1;
	ress.push_back(node + 1);
	for (int j = 0; j < n; j++) {
		if (j == node) continue;
		if (v[j].first > w && v[j].second > h) {
			if (v[j].first < v[node].first && v[j].second < v[node].second) {
				int tmp = 1 + solve(j);
				if (tmp > ret) {
					ret = tmp;
					nxt = j;
				}
			}
		}
	}
	if (nxt == -1) return;
	build(nxt);
}
int main() {
	PLAY();

	cin >> n >> w >> h;
	int res = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
		if (v[i].first > w && v[i].second > h) res = 1;
	}
	memset(dp, -1, sizeof dp);
	int idx = 0;
	for (int i = 0; i < n; i++) {
		if (v[i].first <= w || v[i].second <= h) continue;
		int tmp = solve(i);
		if (tmp > res) {
			res = tmp;
			idx = i;
		}
	}
	cout << res << endl;
	if (res == 1) {
		for (int i = 0; i < n; i++) {
			if (v[i].first > w && v[i].second > h) {
				cout << i + 1 << endl;
				return 0;
			}
		}
	}
	if (res == 0) return 0;
	build(idx);
	reverse(all(ress));
	for (int e : ress)
		cout << e << " ";
	return 0;
}
