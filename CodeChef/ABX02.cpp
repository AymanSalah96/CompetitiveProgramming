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

const int MOD = 1e9 + 7;
int dp[3][105][105][55][55];
int p, q, n; 
int B1, B2;
int S1, S2;
int solve(int prev, int opend_count1, int opend_count2, int rem1, int rem2) {
	int total = (p + q) - (rem1 + rem2);
	if (total == n) return 1;
	int &ret = dp[prev][opend_count1][opend_count2][rem1][rem2];
	if (ret != -1) return ret;
	ret = 0;
	if (prev != 0) {
		// box1
		for (int i = 1; i <= S1; i++) {
			if (total + i > n) break;
			if (opend_count1 + 1 > B1) break;
			if (rem1 - i < 0) break;
			ret = (ret + solve(0, opend_count1 + 1, opend_count2, rem1 - i, rem2)) % MOD;
		}
	} 
	if (prev != 1) {
		// box2
		for (int i = 1; i <= S2; i++) {
			if (total + i > n) break;
			if (opend_count2 + 1 > B2) break;
			if (rem2 - i < 0) break;
			ret = (ret + solve(1, opend_count1, opend_count2 + 1, rem1, rem2 - i)) % MOD;
		}
	}
	return ret;
}

int main() {
	PLAY();
	int t;
	cin >> t;
	while (t--) {
		memset(dp, -1, sizeof dp);
		
		cin >> p >> q >> n;
		cin >> B1 >> B2;
		cin >> S1 >> S2;
		cout << solve(2, 0, 0, p, q) << "\n";
	}


	return 0;
}
