#include<string.h>
#include<iostream>
using namespace std;

#define PUSHBACK push_back
#define PAIR pair<int,int>
#define lson length,n2,rt<<1,ls,rs
#define rson n2+1,r,rt<<1|1,ls,rs
#define TDD third



const int OST=6e5+10;
int n2,tg;

char str[OST];

int SPA[OST],CST[OST],RPT[OST],TPG[OST],WEIGHT[OST];

void digGet(int n1, int n2) {
	for (int i = 0; i <= n2; i++)
	{
		TPG[i] = 0;
	}
	for (int i = 1; i <= n1; i++)
	{
		TPG[RPT[i]]++;
	}
	for (int i=1; i<=n2; i++)
	{
		TPG[i]+=TPG[i-1];
	} 
	for (int i=n1; i>=1; i--)
	{
		SPA[TPG[RPT[CST[i]]]--]=CST[i];
	}
}

void funTo(int n1) {
	int z = 'z';
	n2 = z;
	for (int i=1; i <= n1; i++)
	{
		RPT[i]=(int)str[i],CST[i]=i;		
	}

	digGet(n1, n2);
	
	int key=1,flag=0;
	for (; flag<n1; n2=flag,key <<= 1) 
	{
		flag=0;
		for (int i=n1-key+1; i<=n1; i++)
		{
			CST[++flag]=i;
		}
			
		for (int i=1; i<=n1; i++) 
		{
			if (SPA[i]>key)
			{
				CST[++flag]=SPA[i]-key;
			}	
		}
		
		digGet(n1, n2);
		swap(CST,RPT);
		RPT[SPA[1]]=flag=1;
		for (int i=2; i<=n1; ++i)
			RPT[SPA[i]]=(CST[SPA[i-1]]==CST[SPA[i]]&&((SPA[i-1]+key>n1&&SPA[i]+key>n1)||(SPA[i-1]+key<=n1&&SPA[i]+key<=n1&&CST[SPA[i-1]+key]==CST[SPA[i]+key])))?flag:++flag;
	}
	
}

//getHeight º¯Êý
void getHeight(int n1) {
	int key = 0;
	
	for (int i = 1; i <= n1; i++) {
		if (RPT[i] == 1)
		{
			continue;			
		}

		if (key)
		{
			key--;		
		}

		int j = SPA[RPT[i]-1];
		while (i+key <= n1 && j+key <= n1 
			&& str[i+key] == str[j+key])
		{
			key++;	
		}
		WEIGHT[RPT[i]] = key;
	}
}
#define fi first
#define MAKEPAIR make_pair
//main
int main() 
{
	//input str
	scanf("%s",str+1);
	int length = strlen(str+1);
	
	for(int i = 1; i <= length; i++) 
	{
		str[i+length] = str[i];
	}
	
	int n1 = strlen(str+1);
	int sz=1;
	int tg=length+1;
	
	funTo(n1);
	getHeight(n1);
	
	long long a=0,b=0;
	long long tmp1 = 0;
	long long tmp2 = 0;
	long long tmp3 = 0;
	for (int i = 1; i <= n1; i++) 
	{
		tmp1 = n1-SPA[i]+1;
		tmp2 = min(max(tg-1,WEIGHT[i]),n1-SPA[i]+1);
		tmp3 = tmp1 - tmp2;
		a += tmp3;
	}
	for (int i=1; i <= n1; i++) 
	{
		tmp1 = n1-SPA[i]+1;
		tmp2 = min(max(sz-1,WEIGHT[i]),n1-SPA[i]+1);
		tmp3 = tmp1 - tmp2;
		b += tmp3;
	}
	
	printf("%lld\n",b-a);
}

