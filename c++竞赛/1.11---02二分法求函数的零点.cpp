#include<bits/stdc++.h>
using namespace std;
const double INS=1e-7;
double f(double x)
{
	return pow(x,5)-15*pow(x,4)+85*pow(x,3)-225*pow(x,2)+274*x-121;
}
int main(){
	double l=1.5,r=2.4;
	double mid;
	while(l<r)
	{
		mid=(l+r)/2;
		if(abs(f(mid))<INS)
		{
			break;
		}
		else if(f(mid)*f(l)<0)
		{
			r=mid;
		}
		else if(f(mid)*f(r)<0)
		{
			l=mid;
		}
	}
	printf("%.6lf",mid);
	return 0;
}
