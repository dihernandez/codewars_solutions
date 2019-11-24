def int32_to_ip(int32):
    expanded = bin(int(int32))[2:]
    while len(expanded) < 32:
        expanded = '0' + expanded
    b1 = expanded[0:8]
    b2 = expanded[8:16]
    b3 = expanded[16:24]
    b4 = expanded[24:]
    r1 = str(int(b1,2)) if b1 != '' else '0'
    r2 = str(int(b2,2)) if b2 != '' else '0'
    r3 = str(int(b3,2)) if b3 != '' else '0'
    r4 = str(int(b4,2)) if b4 != '' else '0'
    return  r1 + "." + r2 + "." + r3 + "." + r4