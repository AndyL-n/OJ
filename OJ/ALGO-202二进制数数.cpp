#include<stdio.h>
int main()
{
	int L,R,ans = 0;
	scanf("%d%d",&L,&R);
	for(int i = L;i <= R;i++)
	{
		int tmp = i;
		while(tmp > 0)
		{
			ans += (tmp&1);
			tmp >>= 1;
		}
		
	} 
	printf("%d\n",ans);
	return 0; 
}
