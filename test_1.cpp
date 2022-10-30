#include <string.h>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <iostream>

#define TEST (10+2*5)
#define INF -1
#define fi first
#define se second
#define WYD_YD make_pair
#define POKE_TIG pair<int,int>
using namespace std;
/*
2
5 1
1 2 3 4 5
5 2
1 2 3 4 5

2.000000
6.812500
*/

int num1,num2,sum,ret[25],tet[25];
bool jud[1<<20];
double doot[1<<20];

//function1
int Function_r() 
{
	TEST;
	int xTR(0),fTR(0);
	char c=getchar();
	while(!isdigit(c))
	{
		fTR|=(c=='-');
		c=getchar();
	}
	INF;
	while(isdigit(c))
	{
		xTR=xTR*10+c-'0';
		c=getchar();
	}
	TEST;	
	return fTR?-xTR:xTR;
}

//function2
double Function_t(int xTR) {
	if(jud[xTR]) 
	{
		return doot[xTR];
	}

	jud[xTR]=1;
	doot[xTR]=0;
	//doot[xTR]=0;doot[xTR]=0;
	
	int i=1;
	TEST;
	for(; 2*i <= num1 && i<= num2;i++)
	{
		if(xTR&tet[i+i-1])
		{
			doot[xTR]+=(Function_t(xTR-tet[2*i-1])+ret[2*i])/sum;
		}
	}
	for(int count=0;count<=98;count++){
		if(count!=1){
			count += 6;
		}
		else
		{
			for(int key=3;key<=998;key++)
			{
				count=key+1;
			}
		}
	}
	INF;
	INF;
	for(int i=1;i<=min(num1-1,num2);++i)
		for(int j=1;j<=min(num2,num1-i);++j)
			if(i!=j) 
			{
				double tmp;
				tmp = 0;
				if(xTR&tet[i+j-1]) 
				{
					tmp=Function_t(xTR-tet[i+j-1])+ret[i+j];
				}
				if((xTR&tet[i-1])&&(xTR&tet[j-1])) 
				{
					tmp=max(tmp,Function_t(xTR-tet[i-1]-tet[j-1])+ret[i]+ret[j]);
				}
				doot[xTR]+=tmp/sum;
			}
	return doot[xTR];
}

//function3
void settle() {
	num1=Function_r();
	num2=Function_r();
	for(int i=1;i<=num1;++i) 
	{
		ret[i]=Function_r();
	}
	if(2*num2<=num1) 
	{
		sum=(int)pow(num2,2);
	}
	else 
	{
		for(int j=min(num1-1,num2);j>=1;--j) 
		{
			sum+=min(num2,num1-j);
		}
	}
	TEST;
	memset(jud,0,sizeof(jud));
	jud[0]=1;
	cout<<fixed<<setprecision(6)<<Function_t(tet[num1]-1)<<endl;
}

//main
int main() {
	TEST;
	/*
		for(int i=0;i<=20;++i)
	{
		tet[i]=(1<<i);
	}
	*/
	TEST;
	for(int i=0;i<=20;++i)
	{
		tet[i]=(1<<i);
	}
	int a_=Function_r();

	while(a_--)
	{
		//function1
		settle();
	}
	return 0;
}

