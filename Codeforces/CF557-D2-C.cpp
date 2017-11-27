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


int num_cost[100005];
int mp[205][100005];
int freq_cum[100005];
int freq[100005];


int main() {
	PLAY();

	int n;
	cin >> n;
	vector<int> v(n);
	set<int> st;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		freq_cum[v[i]]++;
		freq[v[i]]++;
		st.insert(v[i]);
	}
	for (int i = 0; i < n; i++) {
		int d; cin >> d;
		num_cost[v[i]] += d;
		mp[d][v[i]]++;
	}
	vector<int> srtd(all(st));
	sortvd(srtd);
	
	for (int i = 1; i < 100005; i++) {
		num_cost[i] += num_cost[i - 1];
		freq_cum[i] += freq_cum[i - 1];
	}
	for (int i = 1; i <= 200; i++)
		for (int j = 1; j < 100005; j++)
			mp[i][j] += mp[i][j - 1];

	int res = INT_MAX;
	for (int i = 0; i < sz(srtd); i++) {
		int num = srtd[i];
		int cur_cost = num_cost[srtd[0]] - num_cost[srtd[i]];
		int removed = freq_cum[srtd[0]] - freq_cum[num];
		int rem = n - removed;
		int remove = max(0, rem - (freq[num] * 2 - 1));
		for (int cost = 1; cost <= 200 && remove; cost++) {
			int avilable = mp[cost][num - 1] - mp[cost][0];
			int cnt = min(remove, avilable);
			cur_cost += cnt * cost;
			remove -= cnt;
			
		}
		res = min(res, cur_cost);
	}
	cout << res << endl;
	return 0;
}
