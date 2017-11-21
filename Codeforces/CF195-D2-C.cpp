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

void clear(string &s) {
	for (int i = 0; i < sz(s); i++)
		if (s[i] == ',' || s[i] == '(' || s[i] == ')')
			s[i] = ' ';
}

int main() {
	PLAY();

	int n;
	cin >> n;
	vector<int> tries;
	cin.ignore();
	int thr = -1;
	string type = "";
	for (int line = 0; line < n; line++) {
		string s;
		getline(cin, s);
		clear(s);
		string token;
		SS ss(s);
		ss >> token;
		if (token == "try")
			tries.push_back(line);
		else if (token == "catch") {
			string message = "";
			for (int i = 0; i < sz(s); i++)
				if (s[i] == '"') {
					i++;
					while (i < sz(s) && s[i] != '"')
						message += s[i], i++;
					break;
				}
			SS ss2(s);
			string expType;
			ss2 >> expType >> expType;
			if (tries.back() < thr && type == expType) {
				cout << message << endl;
				return 0;
			}
			tries.pop_back();
		}
		else if (token == "throw") {
			if (!sz(tries)) {
				cout << "Unhandled Exception" << endl;
				return 0;
			}
			SS ss2(s);
			ss2 >> type >> type;
			thr = line;
		}
		
	}
	cout << "Unhandled Exception" << endl;


	return 0;
}
