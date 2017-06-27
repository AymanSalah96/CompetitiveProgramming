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
	cout << fixed << setprecision(1);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int main() {
	PLAY();

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<pair<int, int>>> adj(n);
		while (m--) {
			int u, v, c;
			cin >> u >> v >> c;
			u--; v--;
			adj[u].push_back({ v, c });
			adj[v].push_back({ u, c });
		}

		priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> qu;
		qu.push({ 0, { 0, 0 } });
		vector<bool> vis(n, false);
		vector<pair<int, int>> MST_Edges;
		int MST1 = 0;
		while (sz(qu)) {
			int curCost = qu.top().first;
			int curNode = qu.top().second.first;
			int parentNode = qu.top().second.second;
			qu.pop();
			if (vis[curNode]) continue;
			vis[curNode] = true;
			MST1 += curCost;
			if (curNode != parentNode)
				MST_Edges.push_back({ curNode, parentNode });
			for (int i = 0; i < sz(adj[curNode]); i++)
				if (!vis[adj[curNode][i].first])
					qu.push({ adj[curNode][i].second, { adj[curNode][i].first, curNode } });
		}
		int MST2 = INT_MAX;
		int visEdge[101][101];
		for (int i = 0; i < sz(MST_Edges); i++) {
			memset(visEdge, false, sizeof visEdge);
			visEdge[MST_Edges[i].first][MST_Edges[i].second] = 
				visEdge[MST_Edges[i].second][MST_Edges[i].first] = true;
			int tmpMST = 0;
			priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> qu;
			qu.push({ 0, { 0, 0 } });
			vector<bool> vis(n, false);
			int cnt = 0;
			while (sz(qu)) {
				int curCost = qu.top().first;
				int curNode = qu.top().second.first;
				int parentNode = qu.top().second.second;
				qu.pop();
				if (vis[curNode] || visEdge[curNode][parentNode]) continue;
				visEdge[curNode][parentNode] = visEdge[parentNode][curNode] = true;
				vis[curNode] = true;
				tmpMST += curCost;
				cnt++;
				for (int i = 0; i < sz(adj[curNode]); i++)
					if (!vis[adj[curNode][i].first])
						qu.push({ adj[curNode][i].second, { adj[curNode][i].first, curNode } });
			}
			if (cnt == n)
				MST2 = min(MST2, tmpMST);
		}
		
		cout << MST1 << " " << MST2 << endl;
	}
		
	return 0;
}
