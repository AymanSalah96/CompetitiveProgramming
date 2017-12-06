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

int priority(char ch) {
	if (ch == '*') return 2;
	if (ch == '+' || ch == '-' || ch == '(') return 1;
}

string infix_to_postifx(string exp) {
	string postfix = "";
	stack<char> st;
	for (int i = 0; i < sz(exp); i++) {
		if (isdigit(exp[i])) {
			while (i < sz(exp) && isdigit(exp[i])) {
				postfix += exp[i];
				i++;
			}
			postfix += ",";
			i--;
		}
		else {
			if (exp[i] == '(')
				st.push(exp[i]);
			else if (exp[i] == ')') {
				while (sz(st) && st.top() != '(') {
					postfix += st.top();
					st.pop();
				}
				if (!sz(st)) return "ERROR";
				st.pop();
			}
			else {
				while (sz(st)
					&& st.top() != '('
					&& priority(st.top()) > priority(exp[i])) {
					postfix += st.top();
					st.pop();
				}
				st.push(exp[i]);
			}
		}
	}
	while (sz(st)) {
		postfix += st.top();
		st.pop();
	}
	return postfix;
}

int calc(int a, int b, char op) {
	if (op == '*') return a * b;
	if (op == '+') return a + b;
	if (op == '-') return a - b;
}

bool valid(string exp) {
	for (int i = 0; i < sz(exp); i++)
		if (isalpha(exp[i])) return false;
	return true;
}

int main() {
	PLAY();
	
	
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		if (!valid(s)) {
			cout << "ERROR\n";
			continue;
		}
		string postfix = infix_to_postifx(s);
		if (postfix == "ERROR") {
			cout << "ERROR\n";
			continue;
		}
		int res = 0;
		stack<int> st;
		bool error = false;
		for (int i = 0; i < sz(postfix); i++) {
			if (isdigit(postfix[i])) {
				int num = 0;
				while (i < sz(postfix) && postfix[i] != ',') {
					num = num * 10 + (postfix[i] - '0');
					i++;
				}
				st.push(num);
			}
			else {
				if (sz(st) < 2) {
					error = true;
					break;
				}
				int a = st.top();
				st.pop();
				int b = st.top();
				st.pop();
				st.push(calc(b, a, postfix[i]));
			}
		}
		if (error || sz(st) > 1)
			cout << "ERROR\n";
		else
			cout << st.top() << endl;
	}
	
	
	return 0;
}
