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

struct val{
	ll mx_left;
	ll mx_right;
	ll tot_sum;
	ll best;
	val() {
		mx_left = mx_right = tot_sum = best = 0;
	}
};

val a[55];

ll calc_best(vector<int> &v) {
	ll mx = INT_MIN;
	ll sum = 0;
	for (int i = 0; i < sz(v); i++) {
		mx = max(mx, (ll)v[i]);
		sum += v[i];
		if (sum < 0) sum = 0;
		else mx = max(sum, mx);
	}
	return mx;
}

ll calc_left(vector<int> &v) {
	ll ret = INT_MIN;
	ll sum = 0;
	for (int i = 0; i < sz(v); i++) {
		sum += v[i];
		ret = max(ret, sum);
	}
	return ret;
}

ll calc_right(vector<int> &v) {
	ll ret = INT_MIN;
	ll sum = 0;
	for (int i = sz(v) - 1; i >= 0; i--) {
		sum += v[i];
		ret = max(ret, sum);
	}
	return ret;
}

ll calc_sum(vector<int> &v) {
	ll sum = 0;
	for (int i = 0; i < sz(v); i++)
		sum += v[i];
	return sum;
}

int idx[250005];

int main() {
	PLAY();

	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n);
	for (int i = 0; i < n; i++) {
		int l; cin >> l;
		v[i].resize(l);
		for (int j = 0; j < l; j++)
			cin >> v[i][j];
	}
	
	for (int i = 0; i < m; i++) {
		cin >> idx[i];
		idx[i]--;
	}

	ll res = INT_MIN;

	for (int i = 0; i < n; i++) {
		a[i].best = calc_best(v[i]);
		a[i].mx_left = calc_left(v[i]);
		a[i].mx_right = calc_right(v[i]);
		a[i].tot_sum = calc_sum(v[i]);
	}

	ll sum = 0;
	for (int i = 0; i < m; i++) {
		res = max(res, a[idx[i]].best);
		if (sum)
			res = max(res, sum + a[idx[i]].mx_left);
		sum = max(0ll, max(a[idx[i]].mx_right, sum + a[idx[i]].tot_sum));
	}
	cout << res << endl;

	return 0;
}
