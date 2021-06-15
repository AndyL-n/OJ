# n = int(input())
# s = input()
# if len(s) % n == 0:
#     m = len(s) // n
#     data = [[] for _ in range(m)]
#     for index,val in enumerate(s):
#         data[index % m].append(val)
#     ans = 0
#     for val in data:
#         Max = 0
#         for i in set(val):
#             Max = val.count(i) if val.count(i) > Max else Max
#         ans += n - Max
#     print(ans)
# else:
#     print(-1)

k=int(input())
s=input()
d=[]
x=[]
s1=""
m=len(s)//k
c=0
# print(len(s))
if len(s)%k!=0:
     print("1")
else:
     for i in range(m):
          for i1 in range(k):
               s1+=s[i+i1*m]
          d.append(s1)
          s1=""
     for i in d:
          a=set(i)
          for i1 in a:
               x.append(i.count(i1))
          c+=k-max(x)
          x=[]
     print(c)

