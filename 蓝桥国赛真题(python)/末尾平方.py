ans = []
for i in range(4,100):
  ans.append(str(i*i)[-2:])

ans.append("01")
ans.append("04")
ans.append("09")
print(len(list(set(ans))))
