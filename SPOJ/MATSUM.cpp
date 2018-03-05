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
	cout << fixed << setprecision(10);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}


const int MAX = (1 << 10);

ll BIT[MAX][MAX], tmp[MAX][MAX];

ll get(int i, int j) {
	i++, j++;
	ll ret = 0;
	while (i) {
		int tmpj = j;
		while (tmpj) {
			ret += BIT[i - 1][tmpj - 1];
			tmpj -= (tmpj & -tmpj);
		}
		i -= (i & -i);
	}
	return ret;
}

void add(int i, int j, int val) {
	i++, j++;
	while (i <= MAX) {
		int tmpj = j;
		while (tmpj <= MAX) {
			BIT[i - 1][tmpj - 1] += val;
			tmpj += (tmpj & -tmpj);
		}
		i += (i & -i);
	}
}

ll get(int mni, int mnj, int mxi, int mxj) {
	return get(mxi, mxj) - get(mni - 1, mxj) - get(mxi, mnj - 1) + get(mni - 1, mnj - 1);
}

void clear() {
	memset(BIT, 0, sizeof BIT);
	memset(tmp, 0, sizeof tmp);
}

int main() {
	PLAY();

	int t;
	cin >> t;
	while (t--) {
		clear();
		int n;
		cin >> n;
		while (true) {
			string type;
			cin >> type;
			if (type == "SET") {
				int i, j, v;
				cin >> i >> j >> v;
				add(i, j, v - tmp[i][j]);
				tmp[i][j] = v;
			}
			else if (type == "SUM") {
				int mni, mnj, mxi, mxj;
				cin >> mni >> mnj >> mxi >> mxj;
				cout << get(mni, mnj, mxi, mxj) << "\n";
			}
			else break;
		}
	}
	
	return 0;
}
