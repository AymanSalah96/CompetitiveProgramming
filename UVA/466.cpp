/*
Author: Ayman Salah

Category: Brute Force
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
	cout << fixed << setprecision(1);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

char a[11][11], b[11][11], tmp[11][11];
int n;

void copy() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = tmp[i][j];
}

bool isSame() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] != b[i][j]) return false;
	return true;
}

void rotate() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tmp[j][i] = a[n - i - 1][j];
	copy();
}

void reflect() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tmp[i][j] = a[n - i - 1][j];
	copy();
}

int main() {
	PLAY();

	int test = 1;
	while (cin >> n) {
		string s1, s2;
		for (int i = 0; i < n; i++) {
			cin >> s1 >> s2;
			for (int j = 0; j < n; j++)
				a[i][j] = s1[j], b[i][j] = s2[j];
		}

		if (isSame())
			cout << "Pattern " << test++ << " was preserved." << endl;
		else {
			bool done = false;
			for (int i = 1; i <= 3 && !done; i++) {
				rotate();
				if (isSame()) {
					cout << "Pattern " << test++ << " was rotated " << i * 90 << " degrees." << endl;
					done = true;
				}
			}
			if (done) continue;
			rotate();
			reflect();
			if (isSame()) {
				cout << "Pattern " << test++ << " was reflected vertically." << endl;
				done = true;
			}
			for (int i = 1; i <= 3 && !done; i++) {
				rotate();
				if (isSame()) {
					cout << "Pattern " << test++ << " was reflected vertically and rotated " << i * 90 << " degrees." << endl;
					done = true;
				}
			}
			if (!done)
				cout << "Pattern " << test++ << " was improperly transformed." << endl;
		}
	}
	


	return 0;
}
