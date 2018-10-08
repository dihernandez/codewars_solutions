# def find_max(arr):
#     if len(arr) < 2:
#         return None
#     m_arr = arr[1:-2]
#     return max(m_arr) if max(m_arr) > arr[0] and max(m_arr) > arr[-1] else None

# def pick_left(arr):
#     result = {"pos": [], "peaks": []}
#     if len(arr) <= 2:
#         return result
#     else:
#         max = find_max(arr)
#         if max is not None:
#             result["pos"] = result["pos"].append(arr.index(max))
#             result["peaks"] = result["peaks"].append(max)
#             return pick_left(arr[0: arr.index(max) - 1])

# def pick_right(arr):
#     result = {"pos": [], "peaks": []}
#     if len(arr) <= 2:
#         return result
#     else:
#         max = find_max(arr)
#         if max is not None:
#             result["pos"] = result["pos"].append(arr.index(max))
#             result["peaks"] = result["peaks"].append(max)
#             return pick_left(arr[arr.index(max) + 1 : -1])

# def pick_peaks(arr):
    
#     result = {"pos": [], "peaks": []}
#     if len(arr) <= 2:
#         return result
#     left_peaks = pick_left(arr)
#     right_peaks = pick_right(arr)
#     return left_peaks
        


def pick_peaks(arr):
    output = {"pos": [], "peaks": []}

    derivative_arr = [arr[i + 1] - arr[i] for i in range(len(arr)-1)]
    print(derivative_arr)
    print(arr)
    
    for i in range(1,len(derivative_arr) - 1):
        if derivative_arr[i]*derivative_arr[i+1] < 0 and derivative_arr[i] > 0:
            output["pos"].append(i + 1)
            output["peaks"].append(arr[i + 1])
    print(output)
    return output
            def pick_peaks(arr):
    output = {"pos": [], "peaks": []}

    derivative_arr = [arr[i + 1] - arr[i] for i in range(len(arr)-1)]
    derivative_arr.insert(0, 0)
    print(derivative_arr)
    print(arr)
    
    for i in range(len(derivative_arr) - 1):
        if derivative_arr[i]*derivative_arr[i+1] < 0:
            output["pos"].append(i)
            output["peaks"].append(arr(i))
    print(output)
    return output
            
            