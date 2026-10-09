#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n,s; 
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>s;int t=s;
	for(int i=1;i<=n;i++){
		string s;cin>>s;
		if(s.find("kirai")!=string::npos){
			if(t>=0) t=0;
			else continue;
		}
		else if(s.find("daishuki")!=string::npos) t+=2;
		else if(s.find("shuki")!=string::npos) t+=1;
		else t--;
	}
	if(t>0) cout<<t-s;
	else cout<<"shuki";
	return 0;
}

