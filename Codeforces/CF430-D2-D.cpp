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

int n, m;
int grid[1005][1005];
ll topleft[1005][1005];
ll topright[1005][1005];
ll downleft[1005][1005];
ll downright[1005][1005];


int main() {
	PLAY();

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> grid[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			topleft[i][j] = grid[i][j] + max(topleft[i][j - 1], topleft[i - 1][j]);

	for (int i = 1; i <= n; i++)
		for (int j = m; j >= 1; j--)
			topright[i][j] = grid[i][j] + max(topright[i - 1][j], topright[i][j + 1]);

	
	for (int i = n; i >= 1; i--)
		for (int j = 1; j <= m; j++)
			downleft[i][j] = grid[i][j] + max(downleft[i][j - 1], downleft[i + 1][j]);


	for (int i = n; i >= 1; i--)
		for (int j = m; j >= 1; j--)
			downright[i][j] = grid[i][j] + max(downright[i][j + 1], downright[i + 1][j]);

	ll res = 0;

	for (int i = 2; i < n; i++)
		for (int j = 2; j < m; j++) {
			res = max(res, topleft[i][j - 1] + downright[i][j + 1] + topright[i - 1][j] + downleft[i + 1][j]);
			res = max(res, topleft[i - 1][j] + downright[i + 1][j] + topright[i][j + 1] + downleft[i][j - 1]);
		}
	cout << res << endl;

	return 0;
}
