#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n,ans1,ans2,b[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++) ans1+=b[i];
	for(int i=1;i<=n;i++) ans2+=b[i]*(b[i]!=b[i-1]);
	cout<<ans1<<"\n"<<ans2;
	return 0;
}

