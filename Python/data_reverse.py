def data_reverse(data):
    reversed = []
    for i in range(len(data), 0, -8):
        print(i, data[i-8:i])
        reversed.extend(data[(i-8):i])
    return reversed