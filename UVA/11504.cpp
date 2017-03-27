/*
Author: Ayman Salah

Category: Graphs, SCC, Tarjan Algorithm

Idea:
- Find all SCC of the graph
- Rebuild the graph considering every SCC is a node itself
- Count how many SCC has no indegree edges (That will be the answer)
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


vector<int> adj[100005];

int dfs_number[100005];
int lowest_link[100005];
int same_stack[100005];
int cur_dfs_number = 1;

void tarjan(int node) {
	dfs_number[node] = lowest_link[node] = cur_dfs_number++;
	same_stack[node] = 1;
	for (int i = 0; i < sz(adj[node]); i++) {
		int child = adj[node][i];
		if (dfs_number[child] == -1) {
			tarjan(child);
			lowest_link[node] = min(lowest_link[node], lowest_link[child]);
		}
		else if (same_stack[child])
			lowest_link[node] = min(lowest_link[node], lowest_link[child]);
	}
	same_stack[node] = 0;
}
void clear(int n) {
	for (int i = 1; i <= n; i++)
		adj[i].clear();
	cur_dfs_number = 1;
	memset(dfs_number, -1, sizeof dfs_number);
	memset(same_stack, 0, sizeof same_stack);
	memset(lowest_link, 0, sizeof lowest_link);
}

int main() {
	PLAY();

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		clear(n);
		while (m--) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
		}
		for (int i = 1; i <= n; i++)
			if (dfs_number[i] == -1)
				tarjan(i);
		set<int> st;
		for (int i = 1; i <= n; i++)
			st.insert(lowest_link[i]);
		map<int, int> mp;
		int scc_size = 0;
		for (auto e : st)
			mp[e] = scc_size++;
		vector<vector<int>> new_adj(scc_size);
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < sz(adj[i]); j++) {
				if (mp[lowest_link[i]] != mp[lowest_link[adj[i][j]]])
					new_adj[mp[lowest_link[i]]].push_back(mp[lowest_link[adj[i][j]]]);
			}
		}
		vector<int> in(scc_size, 0);
		for (int i = 0; i < scc_size; i++)
			for (int j = 0; j < sz(new_adj[i]); j++) {
				in[new_adj[i][j]] = 1;
			}
		int res = 0;
		for (int i = 0; i < scc_size; i++)
			res += in[i] == 0;
		cout << res << endl;
	}

	
	return 0;
}
