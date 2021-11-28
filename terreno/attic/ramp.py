import random
import sys


def read_arg(arg, min_value, max_value):
    if arg == 'rand':
        return random.randint(min_value, max_value)
    else:
        return int(arg)


def diagonal_iter(M, N):
    for k in range(1, M + N):
        x = max(0, k - M)
        for j in range(min(k, N - x, M)):
            yield (x + j, min(M, k) - j - 1)


def gen_ramp(M, N, ascending):
    matrix = [[0 for _ in range(N)] for _ in range(M)]
    for (n, (x, y)) in enumerate(diagonal_iter(M, N)):
        if ascending:
            matrix[y][x] = n + 1
        else:
            matrix[M - y - 1][N - x - 1] = n + 1
    return matrix


if __name__ == '__main__':
    random.seed(sys.argv[1])
    M = read_arg(sys.argv[2], 1, 1000)
    N = read_arg(sys.argv[3], 1, 1000)
    assert sys.argv[4] in ['asc', 'desc']
    ascending = True if sys.argv[4] == 'asc' else False
    matrix = gen_ramp(M, N, ascending)
    print(M, N)
    for row in matrix:
        for (i, cell) in enumerate(row):
            assert cell != 0
            if i > 0:
                print(end=' ')
            print(cell, end='')
        print()
