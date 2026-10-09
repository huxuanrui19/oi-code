#include<bits/stdc++.h>
using namespace std;
string s,t;
void kkk(){
	int ans=1e9;
	for(int k=0;k<s.size();k++){
		string _s=s.substr(0,k-1)+s.substr(k+1,s.size()-1);
		int j=0,o=0,fj=0,fo=0;
		for(int i=0;i<t.size();i++){
			if(t[i]!=_s[i]){
				if(i%2==0){
					if(!fj){
						fj=1;
						j++;
					}
				}
				else{
					if(!fo){
						fo=1;
						o++;
					}
				}
			}
			else{
				if(i%2==0){
					fj=0;
				}
				else{
					fo=0;
				}
			}
		}
		ans=min(fj+fo+1,ans);
	}
	cout<<ans<<endl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin>>T;
	while(T--){
		cin>>s>>t;
		kkk();
	}
	return 0;
}

