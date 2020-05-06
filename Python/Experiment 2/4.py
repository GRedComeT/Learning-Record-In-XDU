Book = dict()

while True:
    indication = input("Please input the operation(Add, Del, Req)(Q to quit)\n")
    if indication == 'Q':
        break
    name = input("Please input the name\n")
    if indication == 'Add':
        Book[name] = dict()
        while True:
            massage = input("Please input the massage, space to part(telephone 123)(Q to quit)\n")
            if massage == 'Q':
                break
            t = massage.split(' ')
            Book[name][t[0]] = t[1]
    elif indication == 'Del':
        del Book[name]
    else:
        print(Book[name])

for person in Book.keys():
    print(Book[person])
