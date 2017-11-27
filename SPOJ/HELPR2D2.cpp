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


int cur_idx;
int tree[11000000], k;


void update(int cur, int l, int r, int idx, int val) {
	if (l == r && l == idx) {
		tree[cur] += val;
		return;
	}
	int left = cur * 2;
	int right = cur * 2 + 1;
	int mid = (l + r) / 2;
	if (idx <= mid)
		update(left, l, mid, idx, val);
	else
		update(right, mid + 1, r, idx, val);
	tree[cur] = min(tree[left], tree[right]);
}


int query(int cur, int l, int r, int val) {
	if (l == r)
		return l;
	int left = cur * 2;
	int right = cur * 2 + 1;
	int mid = (l + r) / 2;	
	if (tree[left] + val <= k)
		return query(left, l, mid, val);
	return query(right, mid + 1, r, val);
}

int main() {
	PLAY();
	
	int t;
	cin >> t;
	while (t--) {
		memset(tree, 0, sizeof tree);
		cin >> k;
		cur_idx = 1;
		int n; cin >> n;
		string line;
		cin.ignore();
		ll sum = 0;
		while (n) {
			getline(cin, line);
			SS ss(line);
			char tmp;
			int cnt = 1, cap;
			if (line[0] == 'b')
				ss >> tmp >> cnt >> cap;
			else
				ss >> cap;
			n -= cnt;
			while (cnt--) {
				sum += cap;
				int idx = query(1, 1, 100000, cap);
				update(1, 1, 100000, idx, cap);
				cur_idx = max(cur_idx, idx);
			}
		}
		cout << cur_idx << " " << (cur_idx * k - sum) << "\n";
	}

	return 0;
}
