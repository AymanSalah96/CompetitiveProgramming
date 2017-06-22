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

class WordFind {
public:
	int n, m;
	vector<string> g;
	
	bool in(int i, int j) { return i >= 0 && i < n && j >= 0 && j < m; }

	bool find(string w, int i, int j) {
		int dx[3] = { 0, 1, 1 };
		int dy[3] = { 1, 0, 1 };

		for (int k = 0; k < 3; k++) {
			int curi = i, curj = j, idx = 0;
			while (in(curi, curj) && idx < sz(w)) {
				if (w[idx] != g[curi][curj]) break;
				idx++;
				curi += dx[k];
				curj += dy[k];
			}
			if (idx == sz(w)) return true;
		}
		return false;
	}
	vector <string> findWords(vector <string> grid, vector <string> wordList) {
		n = sz(grid);
		m = sz(grid[0]);
		g = grid;
		vector<string> ret;
		for (int i = 0; i < sz(wordList); i++) {
			bool found = false;
			for (int a = 0; a < n && !found; a++) {
				for (int b = 0; b < m && !found; b++) {
					if (find(wordList[i], a, b)) {
						SS ss; ss << a; ss << " "; ss << b;
						ret.push_back(ss.str());
						found = true;
					}
				}
			}
			if (!found) ret.push_back("");
		}
		return ret;
	}
};
