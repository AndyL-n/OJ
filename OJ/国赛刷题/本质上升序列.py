s = "tocyjkdzcieoiodfpbgcncsrjbhmugdnojjddhllnofawllbhfiadgdcdjstemphmnjihecoapdjjrprrqnhgccevdarufmliqijgihhfgdcmxvicfauachlifhafpdccfseflcdgjncadfclvfmadvrnaaahahndsikzssoywakgnfjjaihtniptwoulxbaeqkqhfwl"
length = len(s)

dp = [1 for i in range(length)]

ans = 0
for i in range(length):
  for j in range(i):
    if s[i] > s[j]:
      dp[i] += dp[j]
    elif s[i] == s[j]:
      dp[i] -= dp[j]

for i in dp:
  ans += i
print(ans)
