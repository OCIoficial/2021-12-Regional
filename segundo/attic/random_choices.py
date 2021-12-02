import random
import sys

random.seed(str(sys.argv[1:]))

N = int(sys.argv[2])
M = int(sys.argv[3])

assert 0 < M <= 1000000000

print(N)

elements = random.sample(range(1, 1000000001), M)
elements = random.choices(elements, k=N)

print(' '.join(str(i) for i in elements))
