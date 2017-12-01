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


bool isopen(char x) {
	return x == '(' || x == '[';
}

bool match(char x, char y) {
	return (x == '[' && y == ']') || (x == '(' && y == ')');
}

int main() {
	PLAY();

	
	string s;
	cin >> s;
	stack<pair<char, pair<int, int>>> st;
	int start = -1, cur = 0, mx = 0;
	int idx1 = 0, idx2 = 0;
	for (int i = 0; i < sz(s); i++) {
		cur += s[i] == '[';
		if (isopen(s[i]))
			st.push(make_pair(s[i], make_pair(i, cur)));
		else {
			if (!sz(st) || !match(st.top().first, s[i])) {
				while (sz(st)) st.pop();
				cur = 0;
				start = i;
			}
			else if (match(st.top().first, s[i])) {
				st.pop();
				if (sz(st)) {
					int top = st.top().second.second;
					if (cur - top > mx) {
						mx = cur - top;
						idx1 = st.top().second.first + 1;
						idx2 = i;
					}
				}
				else
					if (cur > mx) {
						mx = cur;
						idx1 = start + 1;
						idx2 = i;
					}
			}			
		}
	}
	cout << mx << endl;
	if (idx1 != idx2)
		cout << s.substr(idx1, (idx2 - idx1) + 1) << endl;

	return 0;
}
