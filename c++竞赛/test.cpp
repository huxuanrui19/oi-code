#include<iostream> 
#include<string> 
using namespace std;
int main()
{
	string a1,b1;
	int a[201]={0},b[201]={0},c[202]={0};
	cin>>a1>>b1;
	int lena=a1.size();
	int lenb=b1.size();
	int lenc=1;
	for(int i=0;i<lena;i++)
	{
		a[lena-i]=a1[i]-'0';
	}
	for(int i=0;i<lenb;i++)
	{
		b[lenb-i]=b1[i]-'0';
	}
	while(lenc<=lena||lenc<=lenb)
	{
		c[lenc]=a[lenc]+b[lenc];
		if(c[lenc]>=10)
		{
			c[lenc]%=10;
			c[lenc+1]++;
		}
		lenc++;
	}
	if(c[lenc]==0)
		lenc--;
	for(int i=lenc;i>=1;i--)
	{
		cout<<c[i];
	}
	return 0;
}
