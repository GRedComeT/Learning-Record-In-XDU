import codecs
x = input("Please input the file name and the encoding format(using Space to part)\n")

x = x.split(' ')

f = codecs.open(x[0], 'r', x[1])
content = f.read()
f.close()

f = codecs.open(x[0], 'w', 'utf-8')
f.write(content)
f.close()