def digital_root(n):
    digit_sum = sum([int(x) for x in str(n)])
    return digit_sum if digit_sum <= 9 else digital_root(digit_sum)