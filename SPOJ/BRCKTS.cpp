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
	cout << fixed << setprecision(4);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

string s;
pair<int, int> tree[100000];

void build(int cur, int i, int j) {
	if (i == j) {
		tree[cur].first = tree[cur].second = (s[i] == '(' ? 1 : -1);
		return;
	}
	int mid = (i + j) / 2;
	int left = 2 * cur;
	int right = 2 * cur + 1;
	build(left, i, mid);
	build(right, mid + 1, j);
	tree[cur].first = tree[left].first + tree[right].first;
	tree[cur].second = min(tree[left].second, tree[left].first + tree[right].second);
}

void update(int cur, int i, int j, int idx) {
	if (i == j) {
		tree[cur].first = tree[cur].second = -tree[cur].first;
		return;
	}
	int mid = (i + j) / 2;
	int left = 2 * cur;
	int right = 2 * cur + 1;
	if (idx <= mid) update(left, i, mid, idx);
	else update(right, mid + 1, j, idx);
	tree[cur].first = tree[left].first + tree[right].first;
	tree[cur].second = min(tree[left].second, tree[left].first + tree[right].second);
}


int main() {
	PLAY();

	int n, q, x, test = 1;
	while (cin >> n) {
		cout << "Test " << test++ << ":\n";
		cin >> s;
		build(1, 0, n - 1);
		cin >> q;
		while (q--) {
			cin >> x;
			if (!x) {
				if (!tree[1].first && !tree[1].second)
					cout << "YES" << endl;
				else
					cout << "NO" << endl;
			}
			else update(1, 0, n - 1, x - 1);
		}
	}

	return 0;
}
