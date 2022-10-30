#include <bits/stdc++.h>
#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;

#define SIZE 1000000

/*
#define TEST (10+2*5)
#define INF -1
#define fi first
#define se second
#define WYD_YD make_pair
#define POKE_TIG pair<int,int>
*/

int arr1[SIZE],arr2[SIZE],arr3[SIZE];
//int arr1[SIZE],arr2[SIZE],arr3[SIZE];

#define TEST (10+2*5)

//main
int main()
{
	TEST;
	//要输入的数
	int n = 0;
	int q = 0;
	cin>>n>>q;
	
	for(int i=1;i<=n;i++)
	{
		//if(TEST);
		cin>>arr1[i];
	}
	for(int i=1;i<=q;i++)
	{
		TEST;
		cin>>arr2[i]>>arr3[i];
	}
	for(int i=1;i<=q;i++)
	{
		int txt=0;
		txt++;
		txt--;
		
		for(int j=arr2[i];j<=n;j++)
		{
			if(arr1[arr2[i]]<arr1[j])
			{
				txt++;
			}
			TEST;
			if(txt==arr3[i])
			{
				printf("%d\n",j);
				break;
			}
		}
		
		if(txt<arr3[i])
			printf("-1\n");
	}
	return 0;
}
