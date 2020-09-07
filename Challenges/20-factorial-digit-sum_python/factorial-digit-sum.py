factorial = 1
for i in range(1, 101):
  factorial *= i
  print(factorial);

digitSum = 0
for item in str(factorial):
  digitSum += int(item)
  print(digitSum)

print("Looks like the answer is: " + str(digitSum))