/*
Author: Ayman Salah

Category: Strings, Trie

Idea:
- Put all the words in a Trie data structure.
- For every given prefix search if it is exist or not.
- If exist, get all words that begin with that prefix from the Trie (make sure to not pick a word equal to that prefix).
- Otherwise there is no match.
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
	cout << fixed << setprecision(4);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct Trie {
	bool isWord;
	Trie *next[26];

	Trie() {
		isWord = false;
		memset(next, NULL, sizeof next);
	}
};

Trie *root;

void add(string s) {
	Trie *cur = root;
	for (int i = 0; i < sz(s); i++) {
		if (cur->next[s[i] - 'a'] == NULL)
			cur->next[s[i] - 'a'] = new Trie();
		cur = cur->next[s[i] - 'a'];
	}
	cur->isWord = true;
}

vector<string> match;

void getAllMatches(Trie *cur, string word) {
	if (cur->isWord)
		match.push_back(word);
	for (int i = 0; i < 26; i++) {
		if (cur->next[i] != NULL)
			getAllMatches(cur->next[i], word + char(i + 'a'));
	}
}

bool search(string prefix) {
	Trie *cur = root;
	for (int i = 0; i < sz(prefix); i++) {
		if (cur->next[prefix[i] - 'a'] == NULL)
			return false;
		cur = cur->next[prefix[i] - 'a'];
	}
	match.clear();
	getAllMatches(cur, "");
	return true;
}

int main() {
	PLAY();

	root = new Trie();
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		add(s);
	}
	cin >> n;
	for (int T = 1; T <= n; T++) {
		cout << "Case #" << T << ": " << endl;
		string s;
		cin >> s;
		if (search(s)) {
			for (string str : match) {
				if (sz(str))
					cout << s << str << endl;
			}
		}
		else
			cout << "No match." << endl;
	}
	
	return 0;
}
