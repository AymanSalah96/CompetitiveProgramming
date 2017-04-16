/*
Author: Ayman Salah

Category: Implementation
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

bool is_mine[12][12];
bool touch[12][12];
char ans[12][12];

int n;
bool valid(int i, int j) { return i >= 0 && i < n && j >= 0 && j < n; }

char cnt(int i, int j) {
	int ret = 0;
	for (int k = 0; k < 8; k++) {
		int to_i = dx[k] + i;
		int to_j = dy[k] + j;
		if (!valid(to_i, to_j)) continue;
		ret += is_mine[to_i][to_j];
	}
	return char(ret + '0');
}
int main() {
	PLAY();


	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		char c;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				cin >> c;
				is_mine[i][j] = c == '*';
			}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				cin >> c;
				touch[i][j] = c == 'x';
			}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				ans[i][j] = '.';

		bool mine = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (touch[i][j]) {
					if (is_mine[i][j]) {
						mine = true;
						continue;
					}
					ans[i][j] = cnt(i, j);
				}
			}
		}
		if (mine) {
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++) {
					if (is_mine[i][j]) ans[i][j] = '*';
				}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << ans[i][j];
			cout << endl;
		}
		if (t)
			cout << endl;
	}

	return 0;
}
