def move_zeros(array):
    zero_queue = array
    non_zero_queue = []
    zeroes_at_end = []
    while zero_queue:
        val = zero_queue.pop(0)
        if val != 0:
            non_zero_queue.append(val)
        else:
            zeroes_at_end.append(val)
    non_zero_queue.extend(zeroes_at_end)
    return non_zero_queue
