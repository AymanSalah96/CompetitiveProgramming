/*
Author: Ayman Salah

Category: Dynamic Programming, Floyd Warshall, Shortest Path
*/

#define _CRT_SECURE_NO_WARNINGS
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
#include <hash_map>
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
#define sz(v) v.size()
#define ndl puts("")
#define SS stringstream
typedef long long ll;
typedef unsigned long long ull;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

void PLAY() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cout << fixed << setprecision(3);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}


int main() {
	PLAY();

	int a, b, test = 1;
	while (cin >> a >> b) {
		if (!a && !b) break;
		set<int> st;
		int cost[101][101];
		
		st.insert(a);
		st.insert(b);

		for (int i = 0; i < 101; i++)
			for (int j = 0; j < 101; j++)
				 cost[i][j] = 1e4;
		cost[a][b] = 1;
		while (cin >> a >> b) {
			if (!a && !b) break;
			st.insert(a);
			st.insert(b);
			cost[a][b] = 1;
		}
		int cnt = sz(st);


		for (int e : st)
			cost[e][e] = 0;

		for (int k = 1; k <= 100; k++)
			for (int i = 1; i <= 100; i++)
				for (int j = 1; j <= 100; j++) {
					if (cost[i][k] < 1e4 && cost[k][j] < 1e4)
						cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
				}
				
		double res = 0;
		for (int i = 1; i <= 100; i++)
			for (int j = 1; j <= 100; j++)
				if (cost[i][j] < 1e4)
					res += cost[i][j];
		
		res /= (cnt * (cnt - 1));
		cout << "Case " << test++ << ": average length between pages = " << res << " clicks" << endl;
		
	}

	return 0;
}
