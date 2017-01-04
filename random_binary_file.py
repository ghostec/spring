import random

f = open('file', 'w')
f.write(''.join(random.choice('01') for i in range(1024)))
f.close()
