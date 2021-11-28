import random
import sys

random.seed(sys.argv[1])


def read_arg(arg, min_value, max_value):
    if arg == 'rand':
        return random.randint(min_value, max_value)
    else:
        return int(arg)


if __name__ == '__main__':
    M = read_arg(sys.argv[2], 1, 1000)
    N = read_arg(sys.argv[3], 1, 1000)
    MAX_HEIGHT = read_arg(sys.argv[4], 1, 1_000_000_000)

    for _ in range(M):
        row = [random.randint(1, MAX_HEIGHT) for _ in range(N)]
