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
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cout << fixed << setprecision(10);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

const int MAX = 2e5 + 10;
int a[MAX];

int main() {
	PLAY();

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	set<int> st;
	bool zero = false;
	for (int i = 1; i < n; ++i) {
		int tmp = abs(a[i] - a[i - 1]);
		if (!tmp) zero = true;
		st.insert(tmp);
	}

	if (sz(st) >= 3 || zero) {
		cout << "NO" << endl;
		return 0;
	}

	if (st.count(1)) st.erase(1); 
	
	if (sz(st) >= 2)  {
		cout << "NO" << endl;
		return 0;
	}

	int x = 1e9;
	if (!sz(st)) {
		cout << "YES" << endl;
		cout << x << " " << x << endl;
		return 0;
	}
	x = *st.begin();
	for (int i = 0; i < n - 1; i++) {
		if ((a[i] % x == 0 && a[i + 1] == 1 + a[i]) ||
			(a[i] % x == 1 && a[i + 1] == a[i] - 1)) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	cout << (ll)1e9 << " " << x << endl;
	return 0;
}
