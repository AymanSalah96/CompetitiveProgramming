/*
Author: Ayman Salah

Category: Dynamic Programming
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
	cout << fixed << setprecision(10);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

void reformat(string &s) {
	for (int i = 0; i < sz(s); i++)
		if (!isalnum(s[i]))
			s[i] = ' ';
}
int dp[10000][10000];

int main() {
	PLAY();

	string a, b;
	int test = 1;
	while (getline(cin, a)) {
		getline(cin, b);
		reformat(a);
		reformat(b);
		SS ss1(a), ss2(b);
		string tmp;
		vector<string> words1, words2;
		while (ss1 >> tmp) words1.push_back(tmp);
		while (ss2 >> tmp) words2.push_back(tmp);
		cout << setw(2) << test++ << ". ";
		if (!sz(words1) || !sz(words2)) {
			cout << "Blank!" << endl;
			continue;
		}
		memset(dp, 0, sizeof dp);
		for (int i = 1; i <= sz(words1); i++) {
			for (int j = 1; j <= sz(words2); j++) {
				if (words1[i - 1] != words2[j - 1])
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				else
					dp[i][j] = 1 + dp[i - 1][j - 1];
			}
		}
		int res = dp[sz(words1)][sz(words2)];
		cout << "Length of longest match: " <<  res << endl;
	}


	return 0;
}
