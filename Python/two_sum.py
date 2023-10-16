def two_sum(numbers, target):
    indices = []
    for index_1 in range(len(numbers)):
        for index_2 in range(index_1 + 1, len(numbers)):
            if numbers[index_1] + numbers[index_2] == target:
                indices = [index_1, index_2]
                break
        if len(indices) == 2:
            break
    return indices