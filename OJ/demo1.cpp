#include <iostream>
#include <stdio.h> 
#include <cstring>
using namespace std;
int main()
{
	int i, j;
	char c[3][100];
	char *s[3];
	scanf("%s%s%s", c[0], c[1], c[2]);
  	for(i = 0;i < 3;i++)
		s[i] = c[i];
	for(i = 1; i < 3; i++)
    	for(j = 0; j < 3 - i; j++)
		{
    		char temp[100];
      		if(strcmp(s[j], s[j + 1]) == 1)
			{
        		temp = s[j];
        		s[j] = s[j + 1];
        		s[j + 1] = temp;
      		}
    	}
  for (i = 0; i < 3; i++) 
    printf("%s\n", s[i]);
  return 0;
}
