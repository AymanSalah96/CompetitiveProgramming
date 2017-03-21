/*
Author: Ayman Salah

Category: Geometry, Connected Components

Idea:
- For every two circles check if there overlap, then they are connected together.
- After building the adjacency list of the graph, get the maximum connected component with dfs or bfs.
*/
  
  
  #define _CRT_SECURE_NO_WARNINGS
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
	#include <hash_map>
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
	#define sz(v) v.size()
	#define ndl puts("")
	#define SS stringstream
	typedef long long ll;
	typedef unsigned long long ull;
	int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
	int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

	ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
	ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

	void PLAY() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
		cout << fixed << setprecision(4);
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	}

	struct Circle {
		double x, y, r;
	};

	vector<vector<int>> adj;
	int cnt = 0, vis[105];

	bool isConnected(Circle a, Circle b) {
		return (sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)) < a.r + b.r) &&
			(abs(a.r - b.r) <= sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)));
	}

	void dfs(int i) {
		if (vis[i]) return;
		vis[i] = true;
		cnt++;
		for (int j = 0; j < sz(adj[i]); j++)
			dfs(adj[i][j]);
	}

	int main() {
		PLAY();

		int n;
		while (cin >> n && n != -1) {
			vector<Circle> v(n);
			for (int i = 0; i < n; i++)
				cin >> v[i].x >> v[i].y >> v[i].r;
			adj.clear();
			adj.resize(n);
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					if (isConnected(v[i], v[j])) {
						adj[i].push_back(j);
						adj[j].push_back(i);
					}
				}
			}
			int res = 0;
			memset(vis, 0, sizeof vis);
			for (int i = 0; i < n; i++) {
				if (!vis[i]) {
					cnt = 0;
					dfs(i);
					res = max(cnt, res);
				}
			}
			cout << "The largest component contains " << res << " ring";
			if (res != 1) cout << 's';
			cout << ".\n";
		}

		return 0;
	}
