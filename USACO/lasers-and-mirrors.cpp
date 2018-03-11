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
//#ifndef ONLINE_JUDGE
	freopen("lasers.in", "r", stdin);
	freopen("lasers.out", "w", stdout);
//#endif

	cout << fixed << setprecision(10);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

const int MAX = 1e6;

pair<pair<int, int>, int> arr[MAX];
pair<pair<int, int>, int> arr1[MAX];
vector<pair<int, int>> adj[MAX];
bool vis[MAX];

int main() {
	PLAY();

	int n;
	cin >> n;
	n += 2;
	for (int i = 0, idx = 0; i < n; i++, idx += 2) {
		cin >> arr[i].first.first >> arr[i].first.second;
		arr[i].second = idx;
		arr1[i] = { { arr[i].first.second, arr[i].first.first }, idx + 1 };
		adj[idx].push_back({ idx + 1, 1 });
		adj[idx + 1].push_back({ idx, 1 });
	}
	int from1 = 0, from2 = 1;
	int to1 = 2, to2 = 3;

	sort(arr, arr + n);
	map<int, int> prev;

	for (int i = 0; i < n; i++) {
		if (prev.find(arr[i].first.first) == prev.end())
			prev[arr[i].first.first] = arr[i].second;
		else {
			int p = prev[arr[i].first.first];
			adj[p].push_back({ arr[i].second, 0 });
			adj[arr[i].second].push_back({ p, 0 });
			prev[arr[i].first.first] = arr[i].second;
		}
	}
	
	sort(arr1, arr1 + n);
	prev.clear();

	for (int i = 0; i < n; i++) {
		if (prev.find(arr1[i].first.first) == prev.end())
			prev[arr1[i].first.first] = arr1[i].second;
		else {
			int p = prev[arr1[i].first.first];
			adj[p].push_back({ arr1[i].second, 0 });
			adj[arr1[i].second].push_back({ p, 0 });
			prev[arr1[i].first.first] = arr1[i].second;
		}
	}

	deque<pair<int, int>> qu;
	qu.push_back({ from1, 0 });
	qu.push_back({ from2, 0 });

	while (sz(qu)) {
		int cur_node = qu.front().first;
		int cur_cost = qu.front().second;
		if (cur_node == to1 || cur_node == to2) {
			cout << cur_cost << endl;
			return 0;
		}
		qu.pop_front();
		if (vis[cur_node]) continue;
		vis[cur_node] = true;
		for (int i = 0; i < sz(adj[cur_node]); i++) {
			int to_node = adj[cur_node][i].first;
			int to_cost = adj[cur_node][i].second;
			if (!vis[to_node]) {
				if (to_cost) qu.push_back({ to_node, cur_cost + 1 });
				else qu.push_front({ to_node, cur_cost });
			}
		}
	}

	cout << -1 << endl;

	return 0;
}
