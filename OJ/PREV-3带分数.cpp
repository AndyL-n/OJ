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
			digit = digit * 10 + data[i];//�������� 1��iλ
			if(digit > n)break;
			for(int k = i+1; k < 9; k++) { //kǰ����,k����ȡ9,��ĸ����1λ
				int j,fenzi = 0,fenmu = 0;
				for(j = i + 1; j <= k; j++) //���Ӳ��� i+1��k-1λ
					fenzi = fenzi * 10 + data[j];
				for(; j < 10; j++) //���Ӳ��� k��9λ
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

