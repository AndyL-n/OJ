import os
import sys

def exgcd(a,b,x,y):
  # 到达递归边界开始向上一层返回
  if b==0:
    x=1
    y=0
    return x,y,a

  x,y,r = exgcd(b,a%b,x,y)
  #把x y变成上一层的
  temp = y    
  y=x-(a//b)*y
  x=temp;
  # //得到a b的最大公因数
  return x,y,r

m = 1
x,y,k = map(abs,list(exgcd(97,127,0,0)))
print((x+y)*(m//k))
