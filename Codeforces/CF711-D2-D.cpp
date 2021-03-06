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


int n;
int nxt[200005];
ll power[200005];
int vis[200005];
const int MOD = 1e9 + 7;
int comp;
vector<pair<int, int>> cycle;
void dfs(int node) {
	vis[node] = comp;
	if (vis[nxt[node]] == comp)
		cycle.push_back({ nxt[node], node});
	if (!vis[nxt[node]])
		dfs(nxt[node]);
}

int getLen(int x, int y) {
	int cnt = 1;
	while (x != y)
		x = nxt[x], cnt++;
	return cnt;
}

int main() {
	PLAY();

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> nxt[i], nxt[i]--;

	power[0] = 1;
	for (int i = 1; i < 200005; i++)
		power[i] = (power[i - 1] * 2LL) % MOD;

	
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			comp++;
			dfs(i);
		}
	}
	ll res = 1;
	for (int i = 0; i < sz(cycle); i++) {
		int cnt = getLen(cycle[i].first, cycle[i].second);
		res = (res * ((power[cnt] - 2 + MOD) % MOD)) % MOD;
		n -= cnt;
	}

	res = (res * power[n]) % MOD;
	cout << res << endl;
	return 0;
}
