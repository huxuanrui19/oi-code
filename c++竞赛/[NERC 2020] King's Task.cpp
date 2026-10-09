#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n;
vector<int> a;
map<vector<int>,int> mp;
void dfs(vector<int> a,int step){
	if(mp.count(a)&&mp[a]<=step) return;
	if(!mp.count(a)) mp[a]=step;
	else mp[a]=min(mp[a],step);
	for(int i=1;i<=n;i++) swap(a[i*2-1],a[i*2]);
	dfs(a,step+1);
	for(int i=1;i<=n;i++) swap(a[i*2-1],a[i*2]);
	for(int i=1;i<=n;i++) swap(a[i],a[i+n]);
	dfs(a,step+1);
	return;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	a.resize(2*n+1);
	for(int i=1;i<=2*n;i++) a[i]=i;
	dfs(a,0);
	//cout<<mp.size()<<"\n";
	//cout.flush();
	vector<int> tar;
	tar.resize(2*n+1);
	for(int i=1;i<=2*n;i++) cin>>tar[i];
	if(!mp.count(tar)) cout<<"-1";
	else cout<<mp[tar];
	return 0;
}
/*
123456
214365
365214
632541
541632
456123
123456
12345678
21436587
65872143
56781234
12345678
*/
