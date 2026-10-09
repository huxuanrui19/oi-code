#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=6e5+10;
int n,r,p,s;
string str[3];
string dfs(string x,int cur){
	if(cur==n) return x;
	string S=dfs("S",cur+1),P=dfs("P",cur+1),R=dfs("R",cur+1);
	if(x=="S") return min(S,P)+max(S,P);
	else if(x=="P") return min(P,R)+max(P,R);
	else return min(R,S)+max(R,S);
}
bool check(string tar){
	int pp,rr,ss;
	pp=rr=ss=0;
	for(int i=0;i<tar.size();i++){
		if(tar[i]=='P') pp++;
		else if(tar[i]=='R') rr++;
		else ss++;
	}
	if(ss==s&&pp==p&&rr==r) return 1;
	else return 0;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	cin>>q;
	for(int t=1;t<=q;t++){
		cin>>n>>r>>p>>s;
		cout<<"Case #"<<t<<": ";
		str[0]=dfs("S",0),str[1]=dfs("P",0),str[2]=dfs("R",0);
		sort(str,str+2);
		int flag=0;
		for(int i=0;i<=2;i++){
			if(check(str[i])){
				cout<<str[i]<<"\n";
				flag=1;
				break;
			}
		}
		if(flag==0) cout<<"IMPOSSIBLE\n";
	}
	return 0;
}

