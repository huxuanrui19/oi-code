#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+10;
map<string,int> ma;
void init(int x){
	string s(x,'0');
	ma[s]=0;
	queue<string> q;
    q.push(s);
	while(!q.empty()){
		string ss=q.front();
		q.pop();
		for(int len=1;len<=x;len++){
			for(int l=0;l+len-1<x;l++){
				int r=l+len-1;
				for(int sta=1;sta<=2;sta++){
					string st=ss;
					for(int i=l;i<=r;i++){
						if(sta==1) st[i]=(ss[i]-'0'+1)%10+'0';
						else st[i]=(ss[i]-'0'-1+10)%10+'0';
					}
					if(!ma.count(st)){
						ma[st]=ma[ss]+1;
						q.push(st);
					}
				}
			}
		}
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,q;
	cin>>n>>q;
	init(n);
	while(q--){
		string a,b;
		cin>>a>>b;
		string tar="";
		for(int i=0;i<n;i++){
			if(a[i]>b[i]) tar=tar+char(b[i]-a[i]+10+'0');
			else tar=tar+char(b[i]-a[i]+'0');
		}
		cout<<ma[tar]<<"\n";
	}
	return 0;
}
