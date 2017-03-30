/*
Author: Ayman Salah

Category: Graphs, MST, Kruskal's Algorithm
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

struct DSU {

	vector<int> p;
	vector<int> rank;
	DSU(int n) {
		p.resize(n);
		rank.resize(n);
		for (int i = 0; i < n; i++)
			p[i] = i, rank[i] = 1;
	}

	int root(int node) {
		if (node == p[node]) return node;
		return p[node] = root(p[node]);
	}
	
	void merge(int a, int b) {
		int p_a = root(a);
		int p_b = root(b);
		if (rank[p_a] >= rank[p_b]) {
			p[p_b] = p_a;
			rank[p_b] += rank[p_a];
		}
		else {
			p[p_a] = p_b;
			rank[p_b] += rank[p_a];
		}
	}

	bool is_same(int a, int b) {
		return root(a) == root(b);
	}
};

struct edge {
	int from, to, w;
};

bool cmp(edge &e1, edge &e2) {
	return e1.w < e2.w;
}
int main() {
	PLAY();

	int t;
	cin >> t;
	int test = 1;
	while (t--) {
		cout << "Case #" << test++ << " : ";
		int n, m;
		cin >> n >> m;
		DSU dsu = DSU(n);
		vector<edge> v(m);
		for (int i = 0; i < m; i++) {
			cin >> v[i].from >> v[i].to >> v[i].w;
			v[i].from--, v[i].to--;
		}
		sort(all(v), cmp);
		vector<int> mst_edges;
		for (int i = 0; i < m; i++) {
			if (dsu.is_same(v[i].from, v[i].to)) continue;
			dsu.merge(v[i].from, v[i].to);
			mst_edges.push_back(i);
		}
		if (sz(mst_edges) != n - 1)
			cout << "No way" << endl;
		else {
			int mst_cost_2 = INT_MAX;
			for (int i = 0; i < sz(mst_edges); i++) {
				DSU new_dsu = DSU(n);
				int cur_cost = 0, number_of_edges = 0;
				for (int j = 0; j < m; j++) {
					if (mst_edges[i] == j || new_dsu.is_same(v[j].from, v[j].to)) continue;
					new_dsu.merge(v[j].from, v[j].to);
					cur_cost += v[j].w;
					number_of_edges++;
				}
				if (number_of_edges == n - 1)
					mst_cost_2 = min(mst_cost_2, cur_cost);
			}
			if (mst_cost_2 == INT_MAX)
				cout << "No second way" << endl;
			else
				cout << mst_cost_2 << endl;
		}
	}
	return 0;
}
