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


int tree[900005];
int cc[100005];
int rr[100005];
int id[100005];
int res[100005];


void build(int cur, int l, int r) {
	if (l == r) {
		tree[cur] = l;
		return;
	}
	int left = cur * 2;
	int right = cur * 2 + 1;
	int mid = (l + r) / 2;
	build(left, l, mid);
	build(right, mid + 1, r);
	if (rr[tree[left]] >= rr[tree[right]])
		tree[cur] = tree[left];
	else
		tree[cur] = tree[right];
}

int query(int cur, int l, int r, int x, int y) {
	if (l > y || r < x) return 0;
	if (l >= x && r <= y) return tree[cur];
	int left = cur * 2;
	int right = cur * 2 + 1;
	int mid = (l + r) / 2;
	int left_idx = query(left, l, mid, x, y);
	int right_idx = query(right, mid + 1, r, x, y);
	if (rr[left_idx] >= rr[right_idx])
		return left_idx;
	else
		return right_idx;
}
void update(int cur, int l, int r, int idx) {
	if (l == r && l == idx) {
		tree[cur] = 0;
		return;
	}
	int left = cur * 2;
	int right = cur * 2 + 1;
	int mid = (l + r) / 2;
	if (idx <= mid)
		update(left, l, mid, idx);
	else
		update(right, mid + 1, r, idx);
	if (rr[tree[left]] >= rr[tree[right]])
		tree[cur] = tree[left];
	else tree[cur] = tree[right];
}

int main() {
	PLAY();


	int n;
	cin >> n;
	vector<pair<pair<int, int>, int>> v(n + 1);
	rr[0] = INT_MIN;
	int tmp = 0;
	for (int i = 1; i <= n; i++) {
		cin >> v[i].first.first >> v[i].first.second;
		v[i].second = i;
		tmp = v[i].first.first;
	}
	sort(v.begin() + 1, v.end());
	for (int i = 1; i <= n; i++) {
		rr[i] = v[i].first.second;
		cc[i] = v[i].first.first;
		id[i] = v[i].second;
	}
	v.clear();
	int cur_r = 1;
	build(1, 1, n);
	int cnt = 0;
	while (cnt <= n + 2) {
		int idx = upper_bound(cc + 1, cc + n + 1, cur_r) - cc;
		idx--;
		if (idx == 0) break;
		if (idx == n) {
			res[cnt++] = n;
			break;
		}
		if (tmp <= cur_r) {
			res[cnt++] = n;
			break;
		}
		int next_idx = query(1, 1, n, 1, idx);
		if (next_idx == 0) break;
		update(1, 1, n, next_idx);
		res[cnt++] = id[next_idx];
		if (id[next_idx] == n) break;
		cur_r = rr[next_idx];
	}
	if (!cnt || (cnt && res[cnt - 1] != n))
		cout << "No such luck" << endl;
	else {
		cout << cnt << endl;
		for (int i = 0; i < cnt; i++)
			cout << res[i] << " ";
		cout << endl;
	}
	return 0;
}
