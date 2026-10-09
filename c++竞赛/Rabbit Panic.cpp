#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int t,n,m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		if(((n%2==0)&&(m%2==1))||(m==1&&n!=1)){
			cout<<"-1"<<endl;
		}
		else{
			if(n%2==0){
				int cnt=n/2-m/2+1;
				cout<<cnt<<endl;
				int a[m+1];
				for(int i=1;i<=m;i++){
					a[i]=cnt+i-1;
				}
				for(int i=1;i<=cnt;i++){
					for(int i=1;i<=m;i++){
						cout<<a[i]<<" ";
					}
					a[1]--;
					a[m]++;
					cout<<endl;
				}
			}
			else{
				if(m%2==0){
					int cnt=n/2-m/2+1;
					cout<<cnt<<endl;
					int a[m+1],flag=0;
					for(int i=1;i<=m;i++){
						if(cnt+i-1>=n/2+1){
							a[i]=cnt+i;
						}
						else{
							a[i]=cnt+i-1;
						}
					}
					for(int i=1;i<=cnt;i++){
						for(int i=1;i<=m;i++){
							cout<<a[i]<<" ";
						}
						a[1]--;
						a[m]++;
						cout<<endl;
					}
				}
				else{
					int cnt=n/2-m/2+1;
					cout<<cnt<<endl;
					int a[m+1];
					for(int i=1;i<=m;i++){
						a[i]=cnt+i-1;
					}
					for(int i=1;i<=cnt;i++){
						for(int i=1;i<=m;i++){
							cout<<a[i]<<" ";
						}
						a[1]--;
						a[m]++;
						cout<<endl;
					}
				}
			}
		}
	}
	return 0;
}

