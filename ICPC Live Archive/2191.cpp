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
}

int a[200005];
int tree[600005];

void build(int cur, int i, int j) {
	if (i == j) {
		tree[cur] = a[i];
		return;
	}
	int mid = (i + j) / 2;
	int left = 2 * cur;
	int right = 2 * cur + 1;
	build(left, i, mid);
	build(right, mid + 1, j);
	tree[cur] = tree[left] + tree[right];
}

void update(int cur, int i, int j, int idx) {
	if (i == j && idx == i) {
		tree[cur] = a[idx];
		return;
	}
	int mid = (i + j) / 2;
	int left = 2 * cur;
	int right = 2 * cur + 1;
	if (idx <= mid)
		update(left, i, mid, idx);
	else
		update(right, mid + 1, j, idx);
	tree[cur] = tree[left] + tree[right];
}

int query(int cur, int i, int j, int from, int to) {
	if (from > j || to < i) return 0;
	if (i >= from && j <= to) return tree[cur];
	int mid = (i + j) / 2;
	int left = 2 * cur;
	int right = 2 * cur + 1;
	return query(left, i, mid, from, to) + query(right, mid + 1, j, from, to);
}
int main() {
	PLAY();

	int n;
	sfi1(n);
	int test = 1;
	while (n) {
		memset(tree, 0, sizeof tree);
		printf("Case %d:\n", test++);
		for (int i = 0; i < n; i++)
			sfi1(a[i]);
		build(1, 0, n - 1);
		while (true) {
			char ch[4];
			int x, y;
			scanf("%s", ch);
			if (ch[0] == 'E') break;
			sfi2(x, y);
			if (ch[0] == 'S') {
				a[x - 1] = y;
				update(1, 0, n - 1, x - 1);
			}
			else
				printf("%d\n", query(1, 0, n - 1, x - 1, y - 1));
		}
		sfi1(n);
		if (!n) break;
		ndl;
	}

	return 0;
}
