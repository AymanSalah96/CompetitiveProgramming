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
	cout << fixed << setprecision(15);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

const int N = 1e5 + 5;

int n, m, k, q, t;

int in[N], out[N];
int size[N], last_child[N];
int last_toy[N], play[N];
vector<int> adj[N];
pair<int, int> tmp[N];


void dfs(int node, int parent) {
	in[node] = ++t;
	size[node] = 1;
	for (int i = 0; i < sz(adj[node]); i++) {
		if (adj[node][i] != parent) {
			dfs(adj[node][i], node);
			size[node] += size[adj[node][i]];
		}
	}
	out[node] = t;
}

int main() {
	PLAY();


	cin >> n >> m >> k >> q;
	memset(last_child, -1, sizeof last_child);
	memset(play, 1, sizeof play);

	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		last_toy[a] = b;
		tmp[i] = { a, b };
	}

	for (int i = 0; i < k; i++) {
		int a = tmp[i].first;
		int b = tmp[i].second;
		if (b == last_toy[a]) {
			if (last_child[b] != -1) {
				int c = last_child[b];
				adj[a].push_back(c);
				adj[c].push_back(a);
				play[a] = 0;
			}
		}
		last_child[b] = a;
	}
	for (int i = 0; i < n; i++)
		if (play[i])
			dfs(i, -1);
	
	while (q--) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		if (last_child[y] == -1)
			cout << 0 << "\n";
		else {
			int z = last_child[y];
			if (in[z] >= in[x] && out[z] <= out[x])
				cout << size[x] << "\n";
			else
				cout << 0 << "\n";
		}
	}
	return 0;
}
