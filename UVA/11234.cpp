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

struct node {
	char val;
	node *l;
	node *r;
};

node* st[10005];
node* qu[10005];
node nodes[10005];

int main() {
	PLAY();

	int  t;
	cin >> t;
	
	while (t--) {
		string s;
		cin >> s;
		int  top = 0, cnt = 0;
		for (int i = 0; i < sz(s); i++) {
			nodes[cnt].val = s[i];
			if (islower(s[i])) {
				nodes[cnt].l = NULL;
				nodes[cnt].r = NULL;
				st[top++] = &nodes[cnt++];
			}
			else  {
				nodes[cnt].l = st[top - 1];
				nodes[cnt].r = st[top - 2];
				st[top - 2] = &nodes[cnt++];
				top--;
			}
		}

		int  l = 0, r = 0;
		string res = "";
		
		qu[r++] = st[0];
		while (l < r) {
			node *nw = qu[l++];
			res += nw->val;
			if (nw->r)
				qu[r++] = nw->r;
			
			if (nw->l)
				qu[r++] = nw->l;
		}
		reverse(all(res));
		cout << res << endl;
	}
	

	return 0;
}
