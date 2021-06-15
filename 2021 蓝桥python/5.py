s = input()
ans = ""
for index,val in enumerate(s):
  if ord('a') <= ord(val) <= ord('z'):
    ans  += (chr((ord(val) - ord('a') + ord('A'))))
  else:
    ans += val
print(ans)
