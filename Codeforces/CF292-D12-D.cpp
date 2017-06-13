/*
Author: Ayman Salah

Category: Graphs, Data Structures, DSU
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
#define sz(v) (int)v.size()
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
	cout << fixed << setprecision(1);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}


struct DSU {

	vector<int> parent;
	vector<int> rank;

	DSU(int n) {
		parent.resize(n);
		rank.resize(n);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			rank[i] = 1;
		}
	}

	int getParent(int node) {
		if (parent[node] == node) return node;
		return parent[node] = getParent(parent[node]);
	}

	int sameComponant(int x, int y) {
		return getParent(x) == getParent(y);
	}

	bool merge(int x, int y) {
		int Px = getParent(x);
		int Py = getParent(y);
		if (Px == Py) return false;
		if (rank[Px] < rank[Py])
			parent[Px] = Py, rank[Py]++;
		else
			parent[Py] = Px, rank[Px]++;
		return true;
	}

	int getCnt() {
		int ret = 0;
		for (int i = 0; i < parent.size(); i++)
			ret += parent[i] == i;
		return ret;
	}
};

int main() {
	PLAY();

	int n, m;
	cin >> n >> m;
	vector<int> x(m), y(m);
	for (int i = 0; i < m; i++) {
		cin >> x[i] >> y[i];
		x[i]--; y[i]--;
	}

	DSU dsu(n);
	vector<pair<int, pair<int, int>>> left;
	vector<pair<int, pair<int, int>>> right;

	for (int i = 0; i < m; i++)
		if (dsu.merge(x[i], y[i]))
			left.push_back({ i, { x[i], y[i] } });
	

	DSU dsu2(n);
	for (int i = m - 1; i >= 0; i--)
		if (dsu2.merge(x[i], y[i]))
			right.push_back({ i, { x[i], y[i] } });
	
	int k;
	cin >> k;
	while (k--) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		DSU dsu(n);
		for (int i = 0; i < sz(left) && left[i].first < l; i++)
			dsu.merge(left[i].second.first, left[i].second.second);
		for (int i = 0; i < sz(right) && right[i].first > r; i++)
			dsu.merge(right[i].second.first, right[i].second.second);
		cout << dsu.getCnt() << endl;
	}


	return 0;
}
