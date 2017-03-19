/*
Author: Ayman Salah

Category: Gready

Idea:
- Take alternately zeros and ones in the same order in the original decks.
- Try to begin with ones first, and another try with zeros
- Whatever the minimum from them it will be the final answer.
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
//#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
//#endif
	cout << fixed << setprecision(4);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
vector<int> a, b;
int n, m;
pair<vector<int>, vector<int>> solve(int cur) {
	int i = 0, j = 0;
	vector<int> merge, take;
	int tmp = 0;
	while (tmp < n + m) {
		if (i < n && a[i] == cur)
			merge.push_back(i + 1), i++, tmp++;
		else if (j < m && b[j] == cur)
			merge.push_back(j + n + 1), j++, tmp++;
		else  {
			cur = 1 - cur;
			if (tmp) take.push_back(tmp);
		}
	}
	if (tmp && cur) take.push_back(tmp);
	return{ merge, take };
}
int main() {
	PLAY();

	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> m;
	b.resize(m);
	for (int i = 0; i < m; i++)
		cin >> b[i];
	
	pair<vector<int>, vector<int>> ans1 = solve(0);
	pair<vector<int>, vector<int>> ans2 = solve(1);
	if (ans1.second.size() <= ans2.second.size()) {
		for (int i = 0; i < sz(ans1.first); i++)
			cout << ans1.first[i] << " ";
		cout << endl << sz(ans1.second) << endl;
		for (int i = 0; i < sz(ans1.second); i++)
			cout << ans1.second[i] << " ";
	}
	else {
		for (int i = 0; i < sz(ans2.first); i++)
			cout << ans2.first[i] << " ";
		cout << endl << sz(ans2.second) << endl;
		for (int i = 0; i < sz(ans2.second); i++)
			cout << ans2.second[i] << " ";
	}

	return 0;
}
