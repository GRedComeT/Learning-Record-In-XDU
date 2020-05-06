import random
""" Or use the collections.Orderdict()"""

tot = {}

for _ in range(1000):
    i = random.randint(1, 100)
    if i not in tot:
        tot[i] = 0
    tot[i] += 1
# sort the dict by dict.keys
keys = tot.keys()
keys = sorted(keys)

res = dict([(key, tot[key]) for key in keys])

for key, value in res.items():
    print("The number {} has appeared {} times.".format(key, value))