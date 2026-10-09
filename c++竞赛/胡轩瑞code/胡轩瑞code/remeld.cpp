#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int a[20],b[30];
int main() {
	freopen("remeld.in","r",stdin);
	freopen("remeld.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		for(int i=1;i<=14;i++) cin>>a[i];
		for(int i=1;i<=14;i++) b[a[i]]++;
		set<int> s;
		for(int i=1;i<=27;i++){
			if(b[i]) s.insert(i/9);
		}
		bool flag=0;
		if(s.size()==3) cout<<"1\n";
		else{
			for(int i=1;i<=27;i++){
				if(b[i]>=2){
					b[i]-=2;
					int lstlen1=0,lstlen2=0,lstlen3=0;
					bool mark=0;
					for(int k=0;k<=2;k++){	
						for(int j=1+k*9;j<=9+k*9;j++){
							if(b[j]==0){
								if(lstlen1+lstlen2+lstlen3!=0) continue;
								else{
									mark=0;
									break;
								}
							}
							else if(b[j]==1){
								ll cnt=0;
								if(lstlen1) cnt++;
								if(lstlen2) cnt++;
								if(lstlen3) cnt++;
								if(cnt>=1) mark=0;
								else{
									if(lstlen1) lstlen1++;
									if(lstlen2) lstlen2++;
									if(lstlen3) lstlen3++;
									lstlen1%=3;lstlen2%=3;lstlen3%=3;
								}
							}
							else if(b[j]==2){
								ll cnt=0;
								if(lstlen1) cnt++;
								if(lstlen2) cnt++;
								if(lstlen3) cnt++;
								if(cnt>=2) mark=0;
								else{
									if(lstlen1) lstlen1++;
									if(lstlen2) lstlen2++;
									if(lstlen3) lstlen3++;
									lstlen1%=3;lstlen2%=3;lstlen3%=3;
								}
							}
							else if(b[j]==3){
								ll cnt=0;
								if(lstlen1) cnt++;
								if(lstlen2) cnt++;
								if(lstlen3) cnt++;
								if(cnt==0) continue; 
								else{
									lstlen1++;
									lstlen2++;
									lstlen3++;
									lstlen1%=3;lstlen2%=3;lstlen3%=3;
								}
							}
							else if(b[j]==4){
								ll cnt=0;
								if(lstlen1) cnt++;
								if(lstlen2) cnt++;
								if(lstlen3) cnt++;
								if(cnt==1) continue; 
								else{
									lstlen1++;
									lstlen2++;
									lstlen3++;
									lstlen1%=3;lstlen2%=3;lstlen3%=3;
								}
							}
						}
						if((lstlen1+lstlen2+lstlen3)%3==0) mark=0;
					}
					flag|=mark;
				}
			}
			if(flag==1) cout<<"0\n";
			else cout<<"1\n";
		}
	}
	return 0;
}

