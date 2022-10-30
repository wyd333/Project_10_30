#include<cmath>
#include<iostream>
using namespace std;

//素数判断函数
int isPrime(int num)
{
	if(num == 2)
	{
		return true;
	}
	
	for(int i = 2; i <= sqrt(num); i++)
	{
		if(!(num % i))
		{
			return false;
		}
	}

	return true;
}

int main()
{
	int n = 0;	//素数的取值范围
	int k = 0;	//不能出现的数
	
	cin >> n >> k;
	int poke = 0;
	int i = 2;
	while(i <= n){
		//素数判断
		if(isPrime(i))
		{
			int flag = i;
			int count = 1;
			
			while(flag)
			{
				if(flag % 10 != k) 
				{
					flag /= 10;
				}
				else 
				{
					count = 0;
					break;
				};
			}
			if(count != 0) 
			{
				poke++;	
			}
		}
		i++;
	}
	cout << poke << endl;
	return 0;
}
