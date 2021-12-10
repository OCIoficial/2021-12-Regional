import random
import sys

random.seed(str(sys.argv[1:]))

N = int(sys.argv[2])

print(N)

elements = random.sample(range(1, 1000000001), N)

print(' '.join(str(i) for i in elements))
