def increment_string(strng):
    num_index = -1
    print(strng)
    for c in strng:
        if c.isdigit():
            num_index = strng.find(c)
            break
    if num_index == -1:
        return strng + '1'
    else:
        num_digits = len(strng) - num_index
        new_num = int(strng[num_index:]) + 1
        new_str_l = list(str(new_num))
        while len(new_str_l) < num_digits:
            new_str_l.insert(0,'0')
        return strng[:num_index] + "".join(new_str_l)