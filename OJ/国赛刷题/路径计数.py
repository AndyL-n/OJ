import sys
import os

n = 6
ans = 0
vis = [[0 for i in range(0,n)] for i in range(0,n)]
def DFS(x,y,deep):
##  print("enter"+ str(deep)+":("+str(x)+","+str(y)+")")
  global ans
  dir_x = [1,0,-1,0]
  dir_y = [0,-1,0,1]
  if deep > 12:
    return
  elif x == 0 and y == 0 and deep > 2:
    ans += 1
    return
  else:
    for i in range(0,4):
      xx = int(x+dir_x[i])
      yy = int(y+dir_y[i])
      if xx >= 0 and xx <= 5 and yy >= 0 and yy <= 5 and vis[xx][yy] == 0:
        vis[xx][yy] = 1
        DFS(xx,yy,deep+1)
        vis[xx][yy] = 0
  
if __name__ == '__main__':
  DFS(0,0,0)
  print(ans)
