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
	cout << fixed << setprecision(2);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}


vector<int> adj[27];

bool vis[27];

vector<pair<int, int>> cur;

void dfs(int node) {
	if (vis[node]) return;
	vis[node] = true;
	for (int i = 0; i < sz(adj[node]); i++) {
		if (!vis[adj[node][i]]) {
			cur.push_back({ node, adj[node][i] });
			dfs(adj[node][i]);
		}
	}
}

int main() {
	PLAY();

	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			adj[a[i] - 'a'].push_back(b[i] - 'a');
			adj[b[i] - 'a'].push_back(a[i] - 'a');
		}
	}

	vector<pair<int, int>> res;
	for (int i = 0; i < 26; i++) {
		if (!vis[i]) {
			cur.clear();
			dfs(i);
			for (auto e : cur)
				res.push_back(e);
		}
	}
	cout << sz(res) << endl;
	for (auto e : res)
		cout << char(e.first + 'a') << " " << char(e.second + 'a') << "\n";

	return 0;
}