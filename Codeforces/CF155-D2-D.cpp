/*
Author: Ayman Salah

Category: Number theory, Prime numbers, Sieve

Idea:
-Generate all the prime devisors of numbers from 1 to n.
-Then for each '+' query:
    -If it's already active output "Already on"
    -Otherwise check if this number is conflict with currently active numbers or not
        -If conflict "the number you want to add share a prime devisor with the current active numbers,
	then you are sure that they are not relativly prime", output "Conflict with " any number will make a conflict with.
	-Otherwise mark this number as active and put all it's prime devisors in an array of vectors it's index as the prime devisor
	and the values are the numbers itself.
-For each '-' query:
    -If it's already of output "Already off"
    -Otherwise mark this number off and remove all the prime devisors of this number.

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

set<int> cnt[100005];
vector<int> dv[100005];
bool prime[100005];
bool isOn[100005];

int main() {
	PLAY();

	for (int i = 2; i < 100005; i++)
		prime[i] = 1;
	for (int i = 2; i < 100005; i++) {
		if (prime[i]) {
			dv[i].push_back(i);
			for (int j = i * 2; j < 100005; j += i) {
				prime[j] = false;
				dv[j].push_back(i);
			}
		}
	}

	int n, m;
	cin >> n >> m;
	while (m--) {
		char op; int num;
		cin >> op >> num;
		if (op == '+') {
			if (isOn[num])
				cout << "Already on" << endl;
			else {
				bool ok = true;
				int conflictWith = -1;
				for (int i = 0; i < sz(dv[num]) && ok; i++) {
					if (sz(cnt[dv[num][i]])) {
						conflictWith = *cnt[dv[num][i]].begin();
						ok = false;
					}
				}
				if (ok) {
					for (int i = 0; i < sz(dv[num]); i++)
						cnt[dv[num][i]].insert(num);
					isOn[num] = true, cout << "Success" << endl;
				}
				else cout << "Conflict with " << conflictWith << endl;
			}
		}
		else {
			if (isOn[num]) {
				for (int i = 0; i < sz(dv[num]); i++) {
					if (cnt[dv[num][i]].find(num) != cnt[dv[num][i]].end())
						cnt[dv[num][i]].erase(num);
				}
				isOn[num] = false, cout << "Success" << endl;
			}
			else cout << "Already off" << endl;
		}
	}
	return 0;
}
