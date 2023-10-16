def is_sublist(l):
    if len(l) == 0:
        return False
    for el in l:
        if type(el) is list:
            return True
    else:
        return False

def normalize(l):
    normalized = []
    for el in l:
        if isinstance(el, str):
            normalized.append(el)
        elif el == []:
            normalized.append([])
        elif isinstance(l, int):
            normalized.append(0)
        elif type(el) == list and not is_sublist(el):
            normalized.append([0 for x in el])
        else:
            normalized.append(dig_deep(el))
    return normalized

def dig_deep(l):
    if isinstance(l, int):
        return (0)
    elif type(l) == list and len(l) == 0:
        return (l)
    elif type(l) == list or not is_sublist(l):
        if len(l) == 0:
            replaced == []
        else:
            replaced = [0 if isinstance(x, int) else [] for x in l]
        return (replaced)
    elif is_sublist(l):
        return dig_deep(l[0])
    else:
        replaced = []
        return dig_deep(l)
    
def same_structure_as(original,other):
    if isinstance(original, int) or isinstance(other, int):
        return original == other
    if type(original) != type(other):
        return False
    original_copy = original.copy()
    other_copy = other.copy()

    for x in original_copy:
        if isinstance(x, str):
            original_copy.remove(x)
    for y in other_copy:
        if isinstance(y, str):
            other_copy.remove(y)
            
    x_common = normalize(original_copy)
    y_common = normalize(other_copy)

    if original_copy == other_copy[::-1]:
        return True
    if len(x_common) != len(y_common):
        return False
    for x,y in zip(x_common, y_common):
        if x != y:
            return False
    return True