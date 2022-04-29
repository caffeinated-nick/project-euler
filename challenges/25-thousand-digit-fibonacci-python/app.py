
nextNum = 1
num = 1;
numTwo = 1;

i = 2;

while True:
  nextNum = num + numTwo
  i += 1
  if len(str(nextNum)) == 1000: 
    print(f"Found 1000 digit num i think it's {i}")
    quit()
  numTwo = num
  num = nextNum