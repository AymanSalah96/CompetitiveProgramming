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

int toInt(string s) {
	SS ss(s);
	int ret; ss >> ret;
	return ret;
}

vector<int> getValues(string s) {
	vector<int> ret;
	SS ss(s);
	char tmp;
	while (ss >> tmp) {
		if (isdigit(tmp)) break;
	}
	string num = "";
	num += tmp;
	while (ss >> tmp) {
		if (!isdigit(tmp)) {
			ret.push_back(toInt(num));
			num = "";
			continue;
		}
		num += tmp;
	}
	return ret;
}
ll tree[1100005];
int v[100005];

void build(int cur, int l, int r) {
	if (l == r) {
		tree[cur] = v[l];
		return;
	}
	int left = cur * 2;
	int right = cur * 2 + 1;
	int mid = (l + r) / 2;
	build(left, l, mid);
	build(right, mid + 1, r);
	tree[cur] = min(tree[left], tree[right]);
}

void update(int cur, int l, int r, int idx) {
	if (l == r && idx == l) {
		tree[cur] = v[idx];
		return;
	}
	int left = cur * 2;
	int right = cur * 2 + 1;
	int mid = (l + r) / 2;
	if (idx <= mid)
		update(left, l, mid, idx);
	else
		update(right, mid + 1, r, idx);
	tree[cur] = min(tree[left], tree[right]);
}


int solve(int cur, int l, int r, int x, int y) {
	if (l > y || r < x) return INT_MAX;
	if (l >= x && r <= y) return tree[cur];
	int left = cur * 2;
	int right = cur * 2 + 1;
	int mid = (l + r) / 2;
	return min(solve(left, l, mid, x, y), solve(right, mid + 1, r, x, y));
}

int main() {
	PLAY();

	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	build(1, 1, n);
	cin.ignore();
	while (q--) {
		string line;
		getline(cin, line);
		vector<int> val = getValues(line);
		if (line[0] == 'q')
			cout << solve(1, 1, n, val[0], val[1]) << endl;
		else {
			int first = v[val[0]];
			for (int i = 1; i < sz(val); i++)
				v[val[i - 1]] = v[val[i]];
			v[val.back()] = first;
			for (int i = 0; i < sz(val); i++)
				update(1, 1, n, val[i]);
		}
	}

	return 0;
}
