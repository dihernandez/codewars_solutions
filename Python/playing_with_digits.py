def dig_pow(n, p):
    total = 0
    n_list = [int(i) for i in str(n)]
    for index, number in enumerate(n_list):
        total += number**(p + index)
    return total/n if total % n == 0 else -1