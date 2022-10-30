#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int count = 1;
	int num = 0;
	int p = num;
	p++;
	
	int numAdd = 1;
	int a = 1;
	
	scanf("%d",&num);
	
	int ret = numAdd-1;
	
	for(int i = count; i <= num; i++){
		if(count != 1)
		{
			if(!ret){
				a += 1;
				numAdd++;
				ret = numAdd-1;
			}
			else{
				a += 2;
				ret--;
			}	
		}
		count++;
	}
	
	printf("%d",a);
	
	return 0;
}
