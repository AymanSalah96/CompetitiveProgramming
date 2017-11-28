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


ll sum[200005], a[200005], mx[200005];
vector<int> adj[200005];
bool vis[200005];
ll res = -2e18;
void solve(int node) {
	if (vis[node]) return;
	vis[node] = true;
	ll first = -1e18, second = -1e18;
	for (int i = 0; i < sz(adj[node]); i++)
		if (!vis[adj[node][i]]) {
			solve(adj[node][i]);
			sum[node] += sum[adj[node][i]];
			mx[node] = max(mx[node], mx[adj[node][i]]);
			if (first > second) swap(first, second);
			if (first < mx[adj[node][i]])
				first = mx[adj[node][i]];
		}
	mx[node] = max(mx[node], sum[node]);
	if (first != -1e18 && second != -1e18)
		res = max(res, first + second);
}


int main() {
	PLAY();
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i], sum[i] = a[i], mx[i] = -1e18;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	solve(0);
	if (res <= -2e18)
		cout << "Impossible" << endl;
	else
		cout << res << endl;
	return 0;
}
