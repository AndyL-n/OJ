x_min, x_max, y_min, y_max = -2021, 4041,-2021,4041
count = 0
for x in range(x_min, x_max):
  for y in range(y_min, y_max):
    if (abs(x-0) + abs(y-0) <= 2020) or (abs(x-2020) + abs(y-11) <= 2020) or (abs(x-11) + abs(y-14) <= 2020) or (abs(x-2000) + abs(y-2000) <= 2020):
      count += 1
print(count)
