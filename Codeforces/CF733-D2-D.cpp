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


int get(int i, int j) {
	return 3 - (i + j);
}

int main() {
	PLAY();

	int n;
	cin >> n;
	vector<pair<vector<int>, int>> v(n, { vector<int>(3), 0 });
	map<pair<int, int>, set<pair<int, int>>> mp;
	int mx = INT_MIN, idx1 = -1, idx2 = -1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++)
			cin >> v[i].first[j];
		sortva(v[i].first);
		if (v[i].first[0] > mx) {
			mx = v[i].first[0];
			idx1 = i + 1;
		}
		v[i].second = i;
		for (int j = 0; j < 3; j++)
			for (int k = j + 1; k < 3; k++) {
				mp[{v[i].first[j], v[i].first[k]}].insert({ v[i].first[get(j, k)], i });
				mp[{v[i].first[k], v[i].first[j]}].insert({ v[i].first[get(j, k)], i });

			}
	}
	


	map<pair<int, int>, set<pair<int, int>>>::iterator it;
	set<pair<int, int>>::iterator stit;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = j + 1; k < 3; k++) {
				it = mp.find({ v[i].first[j], v[i].first[k] });
				stit = it->second.end();
				stit--;
				pair<int, int> p = *stit;
				while(p.second == i && stit != it->second.begin()) {
					stit--;
					p = *stit;
				}
				p = *stit;
				if(p.second != i) {
					int val = p.first + v[i].first[get(j, k)];
					val = min({ val, v[i].first[j], v[i].first[k] });
					if (val > mx) {
						mx = val;
						idx1 = i + 1;
						idx2 = p.second + 1;
					}
				}
			}
		}
	}
	if (idx2 == -1) {
		cout << 1 << endl;
		cout << idx1 << endl;
	}
	else {
		cout << 2 << endl;
		cout << idx1 << " " << idx2 << endl;
	}
	return 0;
}
