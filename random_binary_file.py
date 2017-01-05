import random

f = open('file', 'w')
f.write(''.join(random.choice('01') for i in range(2048*4)))
f.close()
