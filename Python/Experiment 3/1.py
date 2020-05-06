class MyStack():
    ''' My own Stack class'''
    def __init__(self):
        self.S = []
        self.length = 0

    def push(self, value):
        '''Push value in the stack'''
        self.S.append(value)
        self.length += 1

    def pop(self):
        ''' Pop the last element in the stack'''
        if len(self.S) != 0:
            self.length -= 1
            return self.S.pop()

    def printStack(self):
        ''' print the all elements in the Stack'''
        print("The stack size is {}".format(self.length))
        for _ in self.S:
            print(_, end='')
        print()

S = MyStack()

S.push(1)
S.push(2)
S.push(3)
S.printStack()
print(S.pop())
S.printStack()