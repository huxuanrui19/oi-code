#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
string s;
int cnt1,cnt2,cnt3,a[N],pos1[N],pos2[N],pos3[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k;
	cin>>n>>k;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='J') pos1[++cnt1]=i+1;
		if(s[i]=='O') pos2[++cnt2]=i+1;
		if(s[i]=='I') pos3[++cnt3]=i+1;
	}
	int poso=1,posi=1,ans=0x3f3f3f3f,flag=0;
	for(int i=1;i<=cnt1;i++){
		if((i+k-1)>cnt1) break;
		int endj=pos1[i+k-1];
		while(pos2[poso]<=endj&&poso<=cnt2) poso++;
		if((poso+k-1)>cnt2) break;
		int endo=pos2[poso+k-1];
		while(pos3[posi]<=endo&&posi<=cnt3) posi++;
		if((posi+k-1)>cnt3) break;
		ans=min(ans,pos3[posi+k-1]-pos1[i]+1-3*k);
		flag=1;
	}
	if(flag==0) cout<<"-1";
	else cout<<ans;
	return 0;
}
