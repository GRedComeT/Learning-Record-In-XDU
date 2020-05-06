x = input("Please input the year\n")
x = int(x)
""" or using the calender.isleap"""
if x % 400 == 0 or (x % 4 == 0 and x % 100 != 0):
    print("Yes")
else:
    print("No")