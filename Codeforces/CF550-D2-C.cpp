/*
Author: Ayman Salah

Category: Dynamic Programming
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
	cout << fixed << setprecision(10);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}


string num, res = "";

int dp[100][11];

int solve(int i, int cur) {
	if (i == sz(num)) return cur == 0;

	int &ret = dp[i][cur];
	if (ret != -1) return ret;

	ret = solve(i + 1, cur);

	if (cur == 10)
		ret |= solve(i + 1, (num[i] - '0') % 8);
	else
		ret |= solve(i + 1, (cur * 10 + (num[i] - '0')) % 8);

	return ret;
}

void print(int i, int cur) {
	if (i == sz(num)) return;

	int ch1, ch2, ch;
	
	ch1 = solve(i + 1, cur);

	if (cur == 10)
		ch2 = solve(i + 1, (num[i] - '0') % 8);
	else
		ch2 = solve(i + 1, (cur * 10 + (num[i] - '0')) % 8);
	
	ch = solve(i, cur);
	
	if (ch == ch1)
		print(i + 1, cur);
	else {
		res += num[i];
		print(i + 1, (cur == 10 ? (num[i] - '0') % 8 : (cur * 10 + (num[i] - '0')) % 8));
	}
}

int main() {
	PLAY();

	cin >> num;

	memset(dp, -1, sizeof dp);

	if (solve(0, 10)) {

		cout << "YES" << endl;
		print(0, 10);

		// remove leading zeros
		reverse(all(res));
		while (sz(res) > 1 && res.back() == '0') res.pop_back();
		reverse(all(res));

		cout << res << endl;
	}
	else
		cout << "NO" << endl;

	return 0;
}
