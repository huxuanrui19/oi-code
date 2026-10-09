#include<bits/stdc++.h>
extern "C" int Seniorious(int);
extern "C" int Chtholly(int n,int times){
	int ans=1,l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1,flag=Seniorious(mid);
		if(flag==1) r=mid-1,ans=mid;
		else if(flag==-1) l=mid+1;
		else{
			ans=mid;break;
		}
	}
	return ans;
}
