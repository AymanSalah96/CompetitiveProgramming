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
#include <assert.h>
using namespace std;

#define PI 3.14159265359
#define all(v) v.begin(),v.end()
#define sortva(v) sort(all(v))
#define sortvd(v) sort(v.rbegin(),v.rend())
#define sortaa(first,n) sort(first,first+n)
#define sortad(first,n) sort(first,first+n),reverse(first,first+n)
#define sfi1(v) scanf("%dist",&v)
#define sfi2(v1,v2) scanf("%dist %dist",&v1,&v2)
#define sfi3(v1,v2,v3) scanf("%dist %dist %dist",&v1,&v2,&v3)
#define sfll1(v) scanf("%I64d",&v);
#define sfll2(v1,v2) scanf("%I64d %I64d",&v1,&v2)
#define sfll3(v1,v2,v3) scanf("%I64d %I64d %I64d",&v1,&v2,&v3)
#define sfstr(v) scanf("%sum", v);
#define sz(v) (int)v.size()
#define ndl puts("")
#define flush fflush(stdout)
#define SS stringstream
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

ll gcd(ll first, ll second) { return !second ? first : gcd(second, first % second); }
ll lcm(ll first, ll second) { return (first / gcd(first, second)) * second; }

void PLAY() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cout << fixed << setprecision(5);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int main() {
	PLAY();
	
	int n, k, m;
	cin >> n >> k >> m;
	vector<string> v(n);
	map<string, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		mp[v[i]];
	}
	vector<int> c(n);
	for (int i = 0; i < n; i++)
		cin >> c[i];
	int type = 0;
	while (k--) {
		int x;
		cin >> x;
		while (x--) {
			int id;
			cin >> id;
			id--;
			mp[v[id]] = type;
		}
		type++;
	}
	map<int, int> mn;
	for (int i = 0; i < n; i++) {
		if (mn.find(mp[v[i]]) == mn.end()) mn[mp[v[i]]] = c[i];
		else mn[mp[v[i]]] = min(mn[mp[v[i]]], c[i]);
	}
	ll res = 0;
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		res += mn[mp[s]];
	}
	cout << res << endl;
	return 0;
}
