import random
import sys


def read_arg(arg, min_value, max_value):
    if arg == 'rand':
        return random.randint(min_value, max_value)
    else:
        return int(arg)


def spiral_iter(iters):
    yield (x := 0, y := 0)
    for i in range(iters):
        (dx, dy) = [(0, -1), (-1, 0), (0, 1), (1, 0)][i % 4]
        yield from ((x := x + dx, y := y + dy) for _ in range(i // 2 + 1))


def gen_spiral_matrix(M, N, cx, cy):
    assert 0 <= cx < N and 0 <= cy < M
    matrix = [[0 for _ in range(N)] for _ in range(M)]
    iters = max(M - cy, cy, N - cx, cx) * 4
    for (n, (x, y)) in enumerate(spiral_iter(iters)):
        assert n <= 1_000_000_000
        x += cx
        y += cy
        if 0 <= y < M and 0 <= x < N:
            matrix[y][x] = n + 1
    return matrix


if __name__ == '__main__':
    random.seed(sys.argv[1])
    M = read_arg(sys.argv[2], 1, 1000)
    N = read_arg(sys.argv[3], 1, 1000)
    cy = read_arg(sys.argv[4], 0, M - 1)
    cx = read_arg(sys.argv[5], 0, N - 1)
    matrix = gen_spiral_matrix(M, N, cx, cy)

    print(M, N)
    for row in matrix:
        for (i, cell) in enumerate(row):
            assert cell > 0
            if i > 0:
                print(end=' ')
            print(cell, end='')
        print()
