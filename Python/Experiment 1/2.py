import random

x = [random.randint(0, 10000) for _ in range(20)]

x = sorted(x[0:10], reverse=True) + x[10:20]
x = sorted(x[10:20], reverse=False) + x[0:10]

print(x)