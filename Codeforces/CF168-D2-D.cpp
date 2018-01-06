/*
Author: Ayman Salah

Category: Dynamic Programming, Probabilities

Idea:
- state of DP will be (cur tour idx, number of wining tours so far, total available capacity so far)
- we will make a simple trick to make sure that the capacity in any state will be not less than zero
- in the worst case we will need a bag of capacity 200 so we will begin our state with capacity 200 + k
- and to make sure I have won the tour, the base case will check if I won the least number of tours and the capacity is not less than 200
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


int n, l, k;
int p[202], a[202];

double dp[205][205][405];

double solve(int i, int t_cnt, int w) {
	if (i == n) {
		if (t_cnt >= l)
			return w >= 200;
		return 0;
	}

	double &ret = dp[i][t_cnt][w];
	if (ret == ret) return ret;
	ret = 0;
	double w_p = p[i] / 100.0;
	double l_p = 1 - w_p;
	ret = w_p*solve(i + 1, t_cnt + 1, min(w + a[i], 400));
	ret += l_p*solve(i + 1, t_cnt, w);
	return ret;
}

int main() {
	PLAY();

	memset(dp, -1, sizeof dp);
	cin >> n >> l >> k;
	for (int i = 0; i < n; i++)
		cin >> p[i];
	for (int i = 0; i < n; i++)
		cin >> a[i];


	cout << solve(0, 0, 200 + k) << endl;

	return 0;
}
