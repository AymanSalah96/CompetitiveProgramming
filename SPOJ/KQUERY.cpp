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

const int MAX = (1 << 18);

int a[MAX], BIT[MAX];
int sorted[MAX];
int ans[MAX];

void add(int idx, int v) {
	idx++;
	while (idx <= MAX) {
		BIT[idx - 1] += v;
		idx += (idx & -idx);
	}
}

int get(int idx) {
	idx++;
	int ret = 0;
	while (idx) {
		ret += BIT[idx - 1];
		idx -= (idx & -idx);
	}
	return ret;
}

enum T { V, Q };

struct Event{
	int l, r, v, idx;
	T t;
}events[MAX];

bool cmp(int a, int b) {
	return make_pair(events[a].v, events[a].t) > make_pair(events[b].v, events[b].t);
}

int main() {
	PLAY();

	int n;
	cin >> n;
	int idx = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		events[idx].v = a[i];
		events[idx].idx = i;
		events[idx].t = V;
		idx++;
	}


	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r, v;
		cin >> l >> r >> v;
		events[idx].v = v;
		events[idx].l = l - 1;
		events[idx].r = r - 1;
		events[idx].idx = i;
		events[idx].t = Q;
		idx++;
	}

	iota(sorted, sorted + idx, 0);
	sort(sorted, sorted + idx, cmp);


	for (int i = 0; i < idx; i++) {
		Event &e = events[sorted[i]];
		if (e.t == V)
			add(e.idx, 1);
		else
			ans[e.idx] = get(e.r) - get(e.l - 1);
	}

	for (int i = 0; i < q; i++)
		cout << ans[i] << "\n";

	return 0;
}
