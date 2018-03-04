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
	cout << fixed << setprecision(3);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

const ll MOD = (1LL << 32);
const int MAX = (1 << 18);

bool is_swap[26][26];
queue<int> pos[26];
int BIT[MAX];

int get(int idx) {
	++idx;
	int res = 0;
	while (idx) {
		res += BIT[idx - 1];
		idx -= (idx & -idx);
	}
	return res;
}

void add(int idx, int val) {
	++idx;
	while (idx <= MAX) {
		BIT[idx - 1] += val;
		idx += (idx & -idx);
	}
}

string a, b;

void clear() {
	memset(is_swap, 0, sizeof is_swap);
	memset(BIT, 0, sizeof BIT);
}

int main() {
	PLAY();

	int t;
	cin >> t;
	while (t--) {
		clear();
		int x;
		cin >> a >> b >> x;
		ll res = 0;
		while (x--) {
			string u;
			cin >> u;
			is_swap[u[0] - 'a'][u[1] - 'a'] = is_swap[u[1] - 'a'][u[0] - 'a'] = 1;
		}
		queue<int> emp;
		fill(pos, pos + 26, emp);
		for (int j = 0; j < sz(a); j++)
			pos[a[j] - 'a'].push(j);
		bool ok = 1;
		for (int j = 0; j < sz(b); j++) {
			int c = b[j] - 'a';
			if (pos[c].empty()) {
				ok = 0;
				break;
			}
			int idx = pos[c].front();
			pos[c].pop();
			for (int k = 0; k < 26; k++) {
				if (sz(pos[k]) && pos[k].front() < idx && !is_swap[k][c]) {
					ok = 0;
					break;
				}
			}
			if (!ok) break;
			res += idx + get(sz(a) - idx - 1) - j;
			add(sz(a) - idx - 1, 1);
		}
		if (!ok)
			cout << -1 << "\n";
		else
			cout << res << "\n";
	}
	return 0;
}
