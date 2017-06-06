/*
Author: Ayman Salah

Category: Implementation, Brute Force
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

map<string, int> to_num;
map<int, string> to_char;

int num[] = { 1, 5, 10, 50, 100, 4, 9, 40, 90 };
string ch[] = { "i", "v", "x", "l", "c", "iv", "ix", "xl", "xc" };


string convert_to_roman(int n) {
	string ret = "";
	for (int i = 0; i < 9; i++) {
		while (n - num[i] >= 0) {
			n -= num[i];
			ret += to_char[num[i]];
		}
	}
	return ret;
}

int main() {
	PLAY();


	for (int i = 0; i < 9; i++) {
		to_char[num[i]] = ch[i];
		to_num[ch[i]] = num[i];
	}

	sortad(num, 9);

	int n;
	while (cin >> n && n) {
		map<char, int> cnt;
		for (int page = 1; page <= n; page++) {
			string roman = convert_to_roman(page);
			for (int i = 0; i < sz(roman); i++)
				cnt[roman[i]]++;
		}
		printf("%d: %d i, %d v, %d x, %d l, %d c\n",
			n, cnt['i'], cnt['v'], cnt['x'], cnt['l'], cnt['c']);
	}


	return 0;
}
