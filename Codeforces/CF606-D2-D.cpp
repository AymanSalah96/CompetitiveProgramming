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


int main() {
	PLAY();

	int n, m;
	cin >> n >> m;
	vector<pair<pair<int, int>, int>> edges(m);

	for (int i = 0; i < m; i++) {
		cin >> edges[i].first.first;
		cin >> edges[i].first.second;
		edges[i].second = i;
		edges[i].first.second *= -1;
	}
	
	sortva(edges);
	vector<pair<int, int>> res(m);
	int p1 = 2, p2 = 3, p3 = 2;
	for (int i = 0; i < m; i++) {
		if (edges[i].first.second)
			res[edges[i].second] = { 1, p1++ };
		else {
			if (p3 == 1) {
				p2++;
				p3 = p2 - 1;
			}
			if (p2 >= p1 || p3 == 1) {
				cout << -1 << endl;
				return 0;
			}
			res[edges[i].second] = { p2, p3 };
			p3--;
		}
	}
	for (int i = 0; i < m; i++)
		cout << res[i].first << " " << res[i].second << endl;
	
	return 0;
}