#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+10;
int n,flag[N][N];
string s[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int len=s[i].size();
			if(s[j].substr(0,len)==s[i]) flag[j][i]=1;
		}
	}
	int ans=0;
	for(int a=1;a<=n;a++){
		for(int b=1;b<=n;b++){
			if(a==b) continue;
			for(int c=1;c<=n;c++){
				if(a==c||b==c||s[a].size()>s[c].size()) continue;
				for(int d=1;d<=n;d++){
					if(a==b||b==c||c==d||a==c||b==d||a==d||s[a].size()>s[c].size()||s[b].size()>s[d].size()){
						continue;
					}
					else{
						if(flag[c][a]&&flag[d][b]){
							if((s[a]+s[b])<(s[c]+s[d])) ans++;
						}
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

