/*
Author: Ayman Salah

Category:
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
	cout << fixed << setprecision(1);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}


int L[200005], R[200005], pre[26];

int main() {
	PLAY();

	string s, t;
	cin >> s >> t;
	for (int i = 0, j = 0; i < sz(s); i++) {
		if (s[i] == t[j]) {
			L[i] = ++j;
			pre[s[i] - 'a'] = j;
		}
		else
			L[i] = pre[s[i] - 'a'];
	}
	for (int i = sz(s) - 1; i >= 0; i--)
		R[i] = R[i + 1] + (R[i + 1] < sz(t) && t[sz(t) - 1 - R[i + 1]] == s[i]);
	
	for (int i = 0; i < sz(s); i++) {
		if (!L[i] || L[i] + R[i + 1] < sz(t)) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;

	return 0;
}
