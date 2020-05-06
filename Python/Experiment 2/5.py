x = input("Please input the number to calculate.\n")
x = int(x)

gen = (i for i in range(2, x+1) if 0 not in (i % j for j in range(2, int(i**0.5)+1)))

print(sum(gen))
