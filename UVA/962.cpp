/*
Author: Ayman Salah

Category: Implementation, Binary Search
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
ll power(ll a, ll b, ll ret = 1LL) {
	while (b--) ret = (ret * a);
	return ret;
}

void PLAY() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cout << fixed << setprecision(2);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}



int main() {
	PLAY();

	// generate all cubes
	vector<ll> cubes;
	for (ll i = 1; i < 1000; i++)
		cubes.push_back(i*i*i);
	
	// generate all cabs according to the problem defination
	vector<ll> cabs;
	map<ll, int> mp;
	for (int i = 0; i < sz(cubes); i++)
		for (int j = i; j < sz(cubes); j++) {
			mp[cubes[i] + cubes[j]]++;
			cabs.push_back(cubes[i] + cubes[j]);
		}
		
	set<ll> tmp;
	// finding all distinict cabs that can be made by at least two distinict ways
	for (auto e : mp)
		if (e.second >= 2) {
			tmp.insert(e.first);
		}
	cabs.clear();
	vector<ll> tmp1(all(tmp));
	// remove dublicates
	cabs = tmp1;
	ll a, b;
	while (cin >> a >> b) {
		// get first cab number >= a
		int idx = lower_bound(all(cabs), a) - cabs.begin();
		// last number in the range
		ll end = a + b;
		bool ok = false;
		// get all cabs in the range [a, a + b]
		while (idx < sz(cabs) && cabs[idx] <= end) {
			cout << cabs[idx++] << endl;
			ok = true;
		}
		// If there is no cabs found print "None"
		if (!ok)
			cout << "None" << endl;
	}
	
	return 0;
}
