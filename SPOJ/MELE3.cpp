/*
Author: Ayman Salah

Category: Graphs, Shortest Path, Dijkstra Algorithm
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
	cout << fixed << setprecision(10);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int wait_time(int from, int to, int cost) {
	int dist = abs(from - to) * 10, ret;
	if (from < to) {
		ret = cost % dist;
		ret = (dist - ret) % dist;
	}
	else
		ret = cost % dist;
	return ret;
}

int main() {
	PLAY();

	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> adj(n);
	while (m--) {
		int u, v, w;
		cin >> u >> v;
		u--, v--;
		w = (v - u) * 5;
		adj[u].push_back({ v, w });
		adj[v].push_back({ u, w });
	}
	vector<bool> vis(n - 1, false);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qu;
	qu.push({ 0, 0 });
	int res = 0;
	while (sz(qu)) {
		int cur_floor = qu.top().second;
		int cur_cost = qu.top().first;
		qu.pop();
		if (cur_floor == n - 1) {
			res = cur_cost;
			break;
		}
		if (vis[cur_floor]) continue;
		vis[cur_floor] = true;
		for (int i = 0; i < sz(adj[cur_floor]); i++) {
			int next_floor = adj[cur_floor][i].first;
			int next_floor_cost = adj[cur_floor][i].second;
			qu.push({ cur_cost + wait_time(cur_floor, next_floor, cur_cost) + next_floor_cost, next_floor });
		}
	}
	cout << res << endl;
	return 0;
}
