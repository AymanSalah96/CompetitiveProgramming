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
	cout << fixed << setprecision(10);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int a[100005][30];
ll fact[100005];
ll inv[100005];
const int MOD = 1e9 + 7;

ll power(ll base, ll y) {
	if (!y) return 1;
	ll ret = power(base, y / 2);
	if (y % 2)
		return (((ret * ret) % MOD) * base) % MOD;
	return (ret * ret) % MOD;
}

ll nCr(ll n, ll k) {
	return (fact[n] * inv[k] % MOD) * inv[n - k] % MOD;
}

ll solve(int l, int r)  {
	map<char, int> mp;
	for (int x = 0; x < 26; x++) {
		int cnt = a[r][x] - (l - 1 >= 0 ? a[l - 1][x] : 0);
		if (cnt)
			mp[char(x + 'a')] = cnt;
	}
	ll res = 0;
	ll len = 0;
	ll odd = 0;
	for (auto e : mp){
		if (e.second % 2 == 1)
			odd++;
		len += e.second / 2;
	}
	res = max(1LL, odd);
	for(auto e : mp) {
		int cnt = e.second / 2;
		res = res * nCr(len, cnt) % MOD;
		len -= cnt;
	}

	return res % MOD;
 }

int main() {
	PLAY();

	fact[0] = 1;
	inv[0] = power(1, MOD - 2);
	for (int i = 1; i < 100005; i++) {
		fact[i] = (fact[i - 1] * i) % MOD;
		inv[i] = power(fact[i], MOD - 2);
	}
	int t;
	string s;
	cin >> s;
	for (int i = 0; i < sz(s); i++) {
		int idx = s[i] - 'a';
		a[i][idx] = 1;
	}
	for (int j = 0; j < 26; j++) {
		for (int i = 1; i < sz(s); i++)
			a[i][j] += a[i - 1][j];
	}
	cin >> t;
	while (t--) {
		int l, r;
		cin >> l >> r;
		l--; r--;
		cout << solve(l, r) % MOD << "\n";
	}
	
	return 0;
}
