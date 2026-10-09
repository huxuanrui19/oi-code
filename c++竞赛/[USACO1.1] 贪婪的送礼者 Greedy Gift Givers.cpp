#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s[100];
string t;
map<string,int> name1,name2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		name1[s[i]]=name2[s[i]]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>t;
		int num,m;
		cin>>num>>m;
		if(m==0) continue;
		int cnt=num/m;
		string g;
		for(int i=1;i<=m;i++){
			cin>>g;
			name1[g]+=cnt;
			name2[t]+=cnt;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<s[i]<<" "<<name1[s[i]]-name2[s[i]]<<endl;
	}
	return 0;
}

