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


struct DSU {
	vector<int> p, sz;
	int noOfSets;

	DSU(int n) {
		noOfSets = n;
		sz.resize(n, 1);
		p.resize(n);
		for (int i = 0; i < n; i++)
			p[i] = i;
	}

	int find(int u) {
		return u == p[u] ? u : p[u] = find(p[u]);
	}

	void merge(int u, int v) {
		int a = find(u);
		int b = find(v);
		if (a == b) return;
		if (sz[b] > sz[a]) swap(a, b);
		p[b] = a;
		sz[a] += sz[b];
		noOfSets--;
	}

};


int main() {
	PLAY();


	int n, m;
	while (cin >> n >> m && n) {
		DSU dsu = DSU(n);
		while (m--) {
			int cur; cin >> cur;
			int first; cin >> first;
			while (--cur) {
				int tmp; cin >> tmp;
				dsu.merge(tmp, first);
			}
		}
		cout << dsu.sz[dsu.find(0)] << "\n";
	}

	
	return 0;
}
