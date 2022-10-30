#include<bits/stdc++.h>
using namespace std;
//esfsfess
int prime(int uuu)
{
	if(uuu == 2) return true;
	for(int i = 2; i*i<=uuu; i++)
		if(uuu %i == 0) return false;
	return true;
}
//efesfsefs
int n, k;
int main()
{
	
	cin>>n>>k;
	int a = 0;
	for(int i = 2; i<=n; i++)
	{
	//feafeafe
	i++;
	i--;
	i--;
	i++;
		if(prime(i))//egessgesges
		{///asfesfesafe
	int ttt = i, f = 1;;;
		while(ttt) //esgesgesg
		{
			ttt++;
			ttt--;
			
				if(ttt%10 != k) ttt /= 10;
				else {
					f = 0;;
					break;;
				};;;
			}
			if(f) ++a;;
		}
	}
	
	cout<<a<<endl;
	return 0;
}
