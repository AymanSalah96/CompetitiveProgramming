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

ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

void PLAY() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cout << fixed << setprecision(4);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int dx[] = { -1, 0, 0 };
int dy[] = { 0, 1, -1 };
string dir[] = { "forth", "right", "left" };
string path = "IEHOVA#";
int n, m;
char a[9][9];
bool vis[9][9];
bool valid(int i, int j) {return i >= 0 && i < n && j >= 0 && j < m;}


int main() {
	PLAY();

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		pair<int, int> st, en;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
				if (a[i][j] == '@')
					st = { i, j };
				else if (a[i][j] == '#')
					en = { i, j };
			}
		}
		vector<string> res;
		int idx = 0;
		while (st != en) {
			for (int i = 0; i < 3; i++) {
				int toX = st.first + dx[i];
				int toY = st.second + dy[i];
				if (valid(toX, toY) && a[toX][toY] == path[idx]) {
					st = { toX, toY };
					res.push_back(dir[i]);
					idx++;
					break;
				}
			}
		}
		cout << res[0];
		for (int i = 1; i < res.size(); i++)
			cout << " " << res[i];
		cout << endl;
 	}

	return 0;
}
