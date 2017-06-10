/*
Author: Ayman Salah

Category: Data Structures, Segment Tree
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
	cout << fixed << setprecision(10);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}


int a[100005];
int tree[1000000];

void build(int cur, int l, int r) {
	if (l == r) {
		tree[cur] = a[l];
		return;
	}
	int left = 2 * cur;
	int right = 2 * cur + 1;
	int mid = (l + r) / 2;
	build(left, l, mid);
	build(right, mid + 1, r);
	tree[cur] = tree[left] * tree[right];
}

void update(int cur, int l, int r, int idx, int v) {
	if (idx < l || idx > r) return;
	if (l == r && l == idx) {
		tree[cur] = v;
		return;
	}
	int left = 2 * cur;
	int right = 2 * cur + 1;
	int mid = (l + r) / 2;
	update(left, l, mid, idx, v);
	update(right, mid + 1, r, idx, v);
	tree[cur] = tree[left] * tree[right];
}

int query(int cur, int l, int r, int x, int y) {
	if (x > r || y < l) return 1;
	if (l >= x && r <= y) return tree[cur];
	int left = 2 * cur;
	int right = 2 * cur + 1;
	int mid = (l + r) / 2;
	return query(left, l, mid, x, y) * query(right, mid + 1, r, x, y);
}

void clear() {
	for (int i = 0; i < 1000000; i++)
		tree[i] = 1;
	memset(a, 0, sizeof a);
}

int main() {
	PLAY();

	int n, k;
	while (cin >> n >> k) {
		clear();
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (a[i] < 0) a[i] = -1;
			else if (a[i] > 0) a[i] = 1;
		}
		build(1, 1, n);
		while (k--) {
			char c;
			cin >> c;
			if (c == 'C') {
				int idx, v;
				cin >> idx >> v;
				if (v > 0) v = 1;
				else if (v < 0) v = -1;
				update(1, 1, n, idx, v);
			}
			else {
				int l, r;
				cin >> l >> r;
				int res = query(1, 1, n, l, r);
				if (res == 0) cout << "0";
				else if (res < 0) cout << "-";
				else cout << "+";
			}
		}
		cout << endl;
	}

	return 0;
}
