def comp(array1, array2):
    print(array1, array2)
    if array1 == None or array2 == None:
        return False
        
    squared_1 = [i**2 for i in array1]

    for i in squared_1:
        if i not in array2 or len(array1) != len(array2):
            return False
    for i in array2:
        if i**0.5 not in array1:
            return False
    for i in squared_1:
        if squared_1.count(i) != array2.count(i):
            return False
    for i in squared_1:
        if squared_1.count(i) != array2.count(i):
            return False
    return True
    