def func(*p):
    print("The max is {}, and the sum is {}.".format(max(p), sum(p)))

ret = []
while True:
    x = input("Please input the number.(input Q to quit)\n")
    if x == 'Q':
        break
    ret.append(int(x))

func(*ret)

