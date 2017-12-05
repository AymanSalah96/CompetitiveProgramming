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

	cout << fixed << setprecision(2);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

double dp[50][50];
int p[50][50];

void build(int cur, int l, int r) {
	if (l == r) {
		dp[cur][l] = 1;
		return;
	}
	int left = cur * 2;
	int right = cur * 2 + 1;
	int mid = (l + r) / 2;
	build(left, l, mid);
	build(right, mid + 1, r);
	for (int i = l; i <= mid; i++)
		for (int j = mid + 1; j <= r; j++) {
			dp[cur][i] += dp[left][i] * dp[right][j] * p[i][j] / 100.0;
			dp[cur][j] += dp[left][i] * dp[right][j] * p[j][i] / 100.0;
		}
}

int main() {
	PLAY();

	string name[20];
	for (int i = 1; i <= 16; i++)
		cin >> name[i];
	for (int i = 1; i <= 16; i++)
		for (int j = 1; j <= 16; j++)
			cin >> p[i][j];
	build(1, 1, 16);
	for (int i = 1; i <= 16; i++)
		printf("%-10s p=%.2lf%%\n", name[i].c_str(), dp[1][i] * 100.0);

	return 0;
}
