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


vector<int> mp[26];

int main() {
	PLAY();

	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < 26; i++)
			mp[i].clear();
		string T;
		int n;
		cin >> n >> T;
		for (int i = 0; i < sz(T); i++)
			mp[T[i] - 'A'].push_back(i);
		while (n--) {
			string S;
			cin >> S;
			int num = 0, prev_idx = 0;
			bool first = true, ok = true;
			for (int i = 0; i < sz(S) && ok; i++) {
				if (isdigit(S[i])) num = num * 10 + (S[i] - '0');
				else {
					if (first) {
						if (sz(mp[S[i] - 'A']) < num) ok = false;
						else prev_idx = mp[S[i] - 'A'][num - 1];
						first = false;
					}
					else {
						int idx = upper_bound(mp[S[i] - 'A'].begin(), mp[S[i] - 'A'].end(), prev_idx) - mp[S[i] - 'A'].begin();
						if (idx + num > sz(mp[S[i] -'A']) ) ok = false;
						else prev_idx = mp[S[i] - 'A'][idx + num - 1];
					}
					num = 0;
				}
			}
			cout << (ok ? "YES\n" : "NO\n");
		}
	}

	return 0;
}
