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

	set<pair<int, int>> ranges;
	int n, k, a;
	cin >> n >> k >> a;
	ranges.insert({ 1, n });
	int cur = (n + 1) / (a + 1);
	int m; cin >> m;
	for (int i = 1; i <= m; i++) {
		int x; cin >> x;
		set<pair<int, int>>::iterator it = ranges.upper_bound({ x, INT_MAX });
		if (it == ranges.begin()) {
			cout << i << endl;
			return 0;
		}
		it--;
		cur -= (it->second - it->first + 2) / (a + 1);
		pair<int, int> first = { it->first, x - 1 };
		pair<int, int> second = { x + 1, it->second };
		cur += (first.second - first.first + 2) / (a + 1);
		cur += (second.second - second.first + 2) / (a + 1);
		if (cur < k) {
			cout << i << endl;
			return 0;
		}
		ranges.erase(it);
		ranges.insert(first);
		ranges.insert(second);
	}

	cout << -1 << endl;
	return 0;
}
