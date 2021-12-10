import random
import sys

random.seed(str(sys.argv[1:]))

N = int(sys.argv[2])

print(N)

elements = list(range(1, N + 1))
random.shuffle(elements)

print(' '.join(str(i) for i in elements))
