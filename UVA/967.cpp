/*
Author: Ayman Salah

Category: Implementation, Physics
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
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);
}

const double EPS = 1e-8;

int main() {
	PLAY();

	double UP, D, L, B, P, DOWN, V;
	int test = 1;
	while (cin >> UP) {
		if ((int)UP == 0) break;
		cin >> D >> L >> B >> P >> DOWN >> V;
		int rep = (int)ceil(V / B - EPS);
		double res = 0, tmp = L;
		while (rep--) {
			res += UP + DOWN + sqrt(2 * tmp / 386.4) + tmp / P;
			tmp += 6912 * B / (D*D*PI);
		}
		if (test > 1) ndl;
		printf("Scenario %d:\n", test++);
		printf("     up hill         %10.2lf sec\n", UP);
		printf("     well diameter   %10.2lf in\n", D);
		printf("     water level     %10.2lf in\n", L);
		printf("     bucket volume   %10.2lf cu ft\n", B);
		printf("     bucket ascent rate%8.2lf in/sec\n", P);
		printf("     down hill       %10.2lf sec\n", DOWN);
		printf("     required volume %10.2lf cu ft\n", V);
		printf("     TIME REQUIRED   %10.2lf sec\n", res);
	}

	return 0;
}
