#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define pb push_back
#define rep(a, b, c, d) for(int a=b; a<=c; a+=d)
const int N = 5e4 + 5;
int n, m, res;
string s;
map<int, int> mp;
void add(string s, int x, int v) {
	if(x == m)
		{++ mp[v]; return;} 
	if(s[x] == '?')
		add(s, x + 1, v * 30 + 27); 
	else
		add(s, x + 1, v * 30 + s[x] - 'a'),
		add(s, x + 1, v * 30 + 26); 
}
void calc(string s, int x, int v) {
	if(x == m)
		{res += mp[v]; return;}
	if(s[x] == '?')
		calc(s, x + 1, v * 30 + 26); 
	else
		calc(s, x + 1, v * 30 + s[x] - 'a');
	calc(s, x + 1, v * 30 + 27); 
}
signed main () {
freopen("word.in","r",stdin);
    freopen("word.out","w",stdout);
	scanf("%lld%lld", &n, &m);
	rep(i, 1, n, 1) {
		cin >> s;
		calc(s, 0, 0);
		add(s, 0, 0);
	}
	printf("%lld", res);
	return 0;
}
//