import collections

def get_divisors(m, n):
    divisors = []
    for i in range(m, n + 1):
        if n%i == 0:
            divisors.append(i)
    return divisors


def is_square(total):
    for i in get_divisors(1, total):
        if i**2 == total:
            return True

# def is_square(total):
#     divisors = get_divisors(1, total)
#     divisor_occurences = collections.defaultdict(int)
#     for d in divisors:
#         divisor_occurences[d] += 1
#     for v in divisor_occurences.values():
#         if v == 2:
#             return True

def list_squared(m, n):
    divisors = get_divisors(m, n)
    print(divisors)
    total = 0
    squares= []
    for d in divisors:
        total += d**2
        if is_square(total**2):
            squares.append([d, total**2])
        print(d, squares)
    return squares


print(list_squared(1,42))