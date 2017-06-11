/*
Author: Ayman Salah

Category: Graphs, MST, Prim Algorithm
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


int main() {
	PLAY();

	double available_cable;
	while (cin >> available_cable) {
		int n;
		cin >> n;
		map<string, int> getIdx;
		for (int i = 0; i < n; i++) {
			string name;
			cin >> name;
			getIdx[name] = i;
		}
		vector<vector<pair<int, double>>> adj(n);
		int m;
		cin >> m;
		while (m--) {
			string name1, name2;
			double cost;
			cin >> name1 >> name2 >> cost;
			adj[getIdx[name1]].push_back({ getIdx[name2], cost });
			adj[getIdx[name2]].push_back({ getIdx[name1], cost });
		}


		vector<bool> vis(n, false);
		double mstCost = 0;
		priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> qu;
		qu.push({ 0, 0 });
		while (sz(qu)) {
			int curNode = qu.top().second;
			double curCost = qu.top().first;
			qu.pop();
			if (vis[curNode]) continue;
			vis[curNode] = true;
			mstCost += curCost;
			for (int i = 0; i < sz(adj[curNode]); i++) {
				if (!vis[adj[curNode][i].first])
					qu.push({ adj[curNode][i].second, adj[curNode][i].first });
			}
		}
		if (mstCost > available_cable)
			cout << "Not enough cable" << endl;
		else
			cout << "Need " << mstCost << " miles of cable" << endl;
	}
	return 0;
}
