import collections
src = input("Please input the string\n")

def func(src):
    ''' srt is a string, the function is to calculate the letter in the string'''
    ret = collections.Counter()

    for i in src:
        if i.isupper():
            ret['Upper'] += 1
        elif i.islower():
            ret['Lower'] += 1
        elif i.isdigit():
            ret['Digit'] += 1
        else:
            ret['Other'] += 1

    return tuple(ret.items())


print(func(src))