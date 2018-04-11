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
#include <assert.h>
using namespace std;

#define PI 3.14159265359
#define all(v) v.begin(),v.end()
#define sortva(v) sort(all(v))
#define sortvd(v) sort(v.rbegin(),v.rend())
#define sortaa(first,n) sort(first,first+n)
#define sortad(first,n) sort(first,first+n),reverse(first,first+n)
#define sfi1(v) scanf("%dist",&v)
#define sfi2(v1,v2) scanf("%dist %dist",&v1,&v2)
#define sfi3(v1,v2,v3) scanf("%dist %dist %dist",&v1,&v2,&v3)
#define sfll1(v) scanf("%I64d",&v);
#define sfll2(v1,v2) scanf("%I64d %I64d",&v1,&v2)
#define sfll3(v1,v2,v3) scanf("%I64d %I64d %I64d",&v1,&v2,&v3)
#define sfstr(v) scanf("%sum", v);
#define sz(v) (int)v.size()
#define ndl puts("")
#define flush fflush(stdout)
#define SS stringstream
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int di[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dj[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

ll gcd(ll first, ll second) { return !second ? first : gcd(second, first % second); }
ll lcm(ll first, ll second) { return (first / gcd(first, second)) * second; }

void PLAY() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cout << fixed << setprecision(5);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

const int MAX = (1 << 18);

int q;
pair<char, int> queries[MAX];
map<int, int> mp;
int ori[MAX], BIT[MAX];


void add(int idx, int val) {
	idx++;
	while (idx <= MAX) {
		BIT[idx - 1] += val;
		idx += (idx & -idx);
	}
}

int get(int idx) {
	idx++;
	int ret = 0;
	while (idx) {
		ret += BIT[idx - 1];
		idx -= (idx & -idx);
	}
	return ret;
}

int cnt(int idx) {
	return get(idx) - get(idx - 1);
}

int find(int idx) {
	int s = 0;
	for (int i = (MAX >> 1); i; i >>= 1) {
		if (BIT[s + i - 1] < idx)
			idx -= BIT[(s += i) - 1];
	}
	return s;
}

int main() {
	PLAY();
	
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> queries[i].first >> queries[i].second;
		mp[queries[i].second];
	}

	int idx = 1;
	for (auto &e : mp) {
		ori[idx] = e.first;
		e.second = idx++;
	}

	for (int i = 0; i < q; i++) {
		int idx = mp[queries[i].second];
		switch (queries[i].first) {
		case 'I':
			if (cnt(idx) == 0)
				add(idx, 1);
			break;
		case 'C':
			cout << get(idx - 1) << "\n";
			break;
		case 'D':
			if (cnt(idx))
				add(idx, -1);
			break;
		case 'K':
			if (queries[i].second > get(MAX - 1))
				cout << "invalid\n";
			else
				cout << ori[find(queries[i].second)] << "\n";
			break;
		}
	}

	return 0;
}
