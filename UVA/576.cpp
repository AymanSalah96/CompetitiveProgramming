/*
Author: Ayman Salah

Category: Implementation
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
#define sz(v) (int)v.size()
#define ndl puts("")
#define SS stringstream
typedef long long ll;
typedef unsigned long long ull;

int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll power(ll a, ll b, ll ret = 1LL) {
	while (b--) ret = (ret * a);
	return ret;
}

void PLAY() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cout << fixed << setprecision(2);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}



int main() {
	PLAY();


	string vow = "aeiouy";

	string line;
	while (getline(cin, line)) {
		if (line == "e/o/i") break;
		vector<string> lines;
		string tmp = "";
		for (int i = 0; i < sz(line); i++) {
			if (line[i] == '/') {
				lines.push_back(tmp);
				tmp = "";
			}
			else tmp += line[i];
		}
		if (sz(tmp)) lines.push_back(tmp);
		int a[] = { 5, 7, 5 };
		bool ok = true;
		for (int i = 0; i < 3; i++) {
			int cnt = 0;
			for (int j = 0; j < sz(lines[i]); j++) {
				if (vow.find(lines[i][j]) != -1) {
					cnt++;
					while (j < sz(lines[i]) && vow.find(lines[i][j]) != -1) j++;
				}
			}
			if (cnt != a[i]) {
				cout << i + 1 << endl;
				ok = false;
				break;
			}
		}
		if (ok)
			cout << "Y" << endl;
	}

	return 0;
}
