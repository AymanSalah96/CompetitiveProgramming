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
	
	int n, k, p;
	cin >> n >> k >> p;
	vector<int> odd, even;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x % 2) odd.push_back(x);
		else even.push_back(x);
	}
	vector<vector<int>> even_ans(p);
	vector<vector<int>> odd_ans(k - p);
	int idx = 0;
	while (idx < sz(odd_ans) && sz(odd)) {
		odd_ans[idx++].push_back(odd.back());
		odd.pop_back();
	}
	idx = 0;
	while (idx < sz(even_ans) && sz(even)) {
		even_ans[idx].push_back(even.back());
		even.pop_back();
		idx++;
	}
	while (idx < sz(even_ans)) {
		if (sz(odd) >= 2) {
			even_ans[idx].push_back(odd.back());
			odd.pop_back();
			even_ans[idx].push_back(odd.back());
			odd.pop_back();
		}
		else break;
		idx++;
	}
	for (int i = 0; i < sz(even_ans); i++)
		if (sz(even_ans[i]) == 0) {
			cout << "NO" << endl;
			return 0;
		}
	for (int i = 0; i < sz(odd_ans); i++)
		if (sz(odd_ans[i]) == 0) {
			cout << "NO" << endl;
			return 0;
		}
	if (sz(even)) {
		if (sz(odd_ans)) {
			while (sz(even)) {
				odd_ans[0].push_back(even.back());
				even.pop_back();
			}
		}
		else if (sz(even_ans)) {
			while (sz(even)) {
				even_ans[0].push_back(even.back());
				even.pop_back();
			}
		}
		else {
			cout << "NO" << endl;
			return 0;
		}
	}
	if (sz(odd)) {
		if (sz(odd) % 2 == 0) {
			if (sz(even_ans)) {
				while (sz(odd)) {
					even_ans[0].push_back(odd.back());
					odd.pop_back();
				}
			}
			else if (sz(odd_ans)) {
				while (sz(odd)) {
					odd_ans[0].push_back(odd.back());
					odd.pop_back();
				}
			}
			else {
				cout << "NO" << endl;
				return 0;
			}
		}
		else {
			cout << "NO" << endl;
			return 0;
		}
	}
	
	cout << "YES" << endl;
	for (auto e : even_ans) {
		cout << sz(e) << " ";
		for (auto x : e)
			cout << x << " ";
		cout << endl;
	}
	for (auto e : odd_ans) {
		cout << sz(e) << " ";
		for (auto x : e)
			cout << x << " ";
		cout << endl;
	}

	return 0;
}
