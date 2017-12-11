/*
Author: Ayman Salah

Category: Gready

Idea:
- Find the minimum value and keep expanding left and right 
- until you can't find a value that is divisable by this minimum number.
- erase these values and get the next minimum value from the remaining ones 
- and keep doing this until there are not value left
- maximze on the size of the numbers and do this again to get all the ranges with this max size
*/

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
#define flush fflush(stdout)
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

int get_max(vector<int> v) {
	map<int, set<int>> mp;
	for (int i = 0; i < sz(v); i++)
		mp[v[i]].insert(i);
	int cur_mx = 1;
	int mn_idx = *mp.begin()->second.begin();
	mp.begin()->second.erase(mp.begin()->second.begin());
	if (sz(mp.begin()->second) == 0) mp.erase(mp.begin());
	while (true) {
		int cur = 1;
		for (int i = mn_idx + 1; i < sz(v); i++) {
			if (v[i] % v[mn_idx]) break;
			mp[v[i]].erase(i);
			if (sz(mp[v[i]]) == 0) mp.erase(v[i]);
			cur++;
		}
		for (int i = mn_idx - 1; i >= 0; i--) {
			if (v[i] % v[mn_idx]) break;
			mp[v[i]].erase(i);
			if (sz(mp[v[i]]) == 0) mp.erase(v[i]);
			cur++;
		}
		mp[v[mn_idx]].erase(mn_idx);
		if (sz(mp[v[mn_idx]]) == 0) mp.erase(v[mn_idx]);
		cur_mx = max(cur_mx, cur);
		if (sz(mp) == 0) break;
		mn_idx = *mp.begin()->second.begin();
		mp.begin()->second.erase(mp.begin()->second.begin());
		if (sz(mp.begin()->second) == 0) mp.erase(mp.begin());
	}
	return cur_mx;
}

void solve(vector<int> v, int size) {
	vector<int> res;
	map<int, set<int>> mp;
	for (int i = 0; i < sz(v); i++)
		mp[v[i]].insert(i);
	int mn_idx = *mp.begin()->second.begin();
	mp.begin()->second.erase(mp.begin()->second.begin());
	if (sz(mp.begin()->second) == 0) mp.erase(mp.begin());
	while (true) {
		int cur = 1;
		for (int i = mn_idx + 1; i < sz(v); i++) {
			if (v[i] % v[mn_idx]) break;
			mp[v[i]].erase(i);
			if (sz(mp[v[i]]) == 0) mp.erase(v[i]);
			cur++;
		}
		int i;
		for (i = mn_idx - 1; i >= 0 && v[i]; i--) {
			if (v[i] % v[mn_idx]) break;
			mp[v[i]].erase(i);
			if (sz(mp[v[i]]) == 0) mp.erase(v[i]);
			cur++;
		}
		mp[v[mn_idx]].erase(mn_idx);
		if (sz(mp[v[mn_idx]]) == 0) mp.erase(v[mn_idx]);
		if (cur == size)
			res.push_back(i + 1);
		if (sz(mp) == 0) break;
		mn_idx = *mp.begin()->second.begin();
		mp.begin()->second.erase(mp.begin()->second.begin());
		if (sz(mp.begin()->second) == 0) mp.erase(mp.begin());
	}
	cout << sz(res) << " " << size - 1 << endl;
	sortva(res);
	for (auto e : res)
		cout << ++e << " ";
}

int main() {
	PLAY();

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	int mx = get_max(v);
	solve(v, mx);

	return 0;
}
