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


int a[200005], l[200005], r[200005], ans[200005];

int main() {
	PLAY();
	
	int n;
	cin >> n;
	fill(l, l + 200005, -1);
	fill(r, r + 200005, n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	stack<int> st;

	for (int i = 0; i < n; i++) {
		while (sz(st) && a[st.top()] >= a[i])
			st.pop();
		if (sz(st)) l[i] = st.top();
		st.push(i);
	}
	while (sz(st)) st.pop();

	for (int i = n - 1; i >= 0; i--){
		while (sz(st) && a[st.top()] >= a[i])
			st.pop();
		if (sz(st)) r[i] = st.top();
		st.push(i);
	}

	for (int i = 0; i < n; i++) {
		int len = r[i] - l[i] - 1;
		ans[len] = max(ans[len], a[i]);
	}
	for (int i = n; i >= 1; i--)
		ans[i] = max(ans[i], ans[i + 1]);
	for (int i = 1; i <= n; i++)
		cout << ans[i] << " ";

	return 0;
}
