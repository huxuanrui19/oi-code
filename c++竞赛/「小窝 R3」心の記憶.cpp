#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		cin>>s;
		s=' '+s;
		if(n==1||n==m||(n==2&&(s==" 10"||s==" 01"))){
			cout<<"-1\n";continue;
		}
		int flag=0,pos=0;
		for(int i=1;i<n;i++){
			if(s[i]==s[i+1]){
				flag=1;
				pos=i;
				break;
			}
		}
		if(flag==1){
			for(int i=1;i<=n;i++){
				cout<<s[i];
				if(i==pos){
					char ch=(s[i]=='0'?'1':'0');
					for(int j=1;j<=m-n;j++){
						cout<<ch;
					}
				}
			}
		}
		else{
			for(int i=1;i<=n;i++){
				cout<<s[i];
				if(i==n-1){
					char ch=(s[i+1]=='0'?'1':'0');
					for(int j=1;j<=m-n;j++){
						cout<<ch;
					}
				}
			}
		}
		cout<<"\n";
	}
	return 0;
}

