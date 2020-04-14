#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int data[10] = {0,1,2,3,4,5,6,7,8,9};
int main() {
	int n,count = 0;
	scanf("%d",&n);
	do {
		int digit = 0;
		for(int i = 1; i < 10; i++) {
			digit = digit * 10 + data[i];//整数部分 1到i位
			if(digit > n)break;
			for(int k = i+1; k < 9; k++) { //k前分子,k不能取9,分母至少1位
				int j,fenzi = 0,fenmu = 0;
				for(j = i + 1; j <= k; j++) //分子部分 i+1到k-1位
					fenzi = fenzi * 10 + data[j];
				for(; j < 10; j++) //分子部分 k到9位
					fenmu = fenmu * 10 + data[j];
				if(fenzi >= fenmu && fenzi % fenmu == 0 && fenzi / fenmu + digit == n)
					count++;
// cout << digit << " "<< fenzi << " "<< fenmu<<endl;
			}
		}
	} while(next_permutation(data+1,data+10));
	printf("%d\n",count);
	return 0;
}

