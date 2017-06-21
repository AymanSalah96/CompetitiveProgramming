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


int n, m;
vector<int> adj[100009];
int in[100009];

void clear() {
	memset(in, 0, sizeof in);
	for (int i = 0; i < n; i++)
		adj[i].clear();
}

int main() {
	PLAY();

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		clear();
		while (m--) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			adj[u].push_back(v);
			in[v]++;
		}
		queue<int> qu;
		for (int i = 0; i < n; i++)
			if (in[i] == 0)
				qu.push(i);
		vector<int> top;
		bool ok = true;
		while (sz(qu)) {
			if (sz(qu) > 1) ok = false;
			int cur = qu.front();
			qu.pop();
			top.push_back(cur);
			for (int i = 0; i < sz(adj[cur]); i++){
				in[adj[cur][i]]--;
				if (in[adj[cur][i]] == 0) qu.push(adj[cur][i]);
			}
		}
		if (sz(top) != n) cout << "recheck hints" << endl;
		else if (!ok) cout << "missing hints" << endl;
		else {
			for (int i = 0; i < sz(top); i++)
				cout << ++top[i] << " ";
			cout << endl;
		}
	}

	return 0;
}
