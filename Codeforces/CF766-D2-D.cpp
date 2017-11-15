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
	cout << fixed << setprecision(10);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct DSU {
	vector<int> parent;
	vector<int> cnt;
	int N;
	DSU(int n) {
		N = n;
		parent.resize(n*2);
		cnt.resize(n*2);
		for (int i = 0; i < n*2; i++) {
			parent[i] = i;
			cnt[i] = 1;
		}
	}

	int root(int x) {
		if (parent[x] == x) return x;
		return parent[x] = root(parent[x]);
	}

	int query(int x, int y) {
		if (root(x) == root(y)) return 1;
		if (root(x) == root(y + N)) return 2;
		return 3;
	}

	void merge2(int x, int y) {
		int p1 = root(x);
		int p2 = root(y);
		if (p1 == p2) return;
		if (cnt[p1] > cnt[p2]) swap(p1, p2);
		parent[p1] = p2;
		cnt[p1] += cnt[p2];
	}

	bool merge(int x, int y, int rel)  {
		int p1 = root(x);
		int p2 = root(y);
		if (rel == 1) {
			if (root(x) == root(y + N)) return false;
			merge2(x, y);
			merge2(x + N, y + N);
		}
		else {
			if (p1 == p2) return false;
			merge2(x + N, y);
			merge2(x, y + N);
		}
		return true;
	}
};

int main() {
	PLAY();

	int n, m, q;
	cin >> n >> m >> q;
	DSU dsu(n);
	map<string, int> mp;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		mp[s] = i;
	}
	while (m--) {
		int t;
		string a, b;
		cin >> t >> a >> b;
		int idx1 = mp[a];
		int idx2 = mp[b];
		if (dsu.merge(idx1, idx2, t))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	while (q--) {
		string a, b;
		cin >> a >> b;
		cout << dsu.query(mp[a], mp[b]) << endl;
	}

	return 0;
}