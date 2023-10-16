def count_unique_elem(input_list):
    count = 0
    l1 = []
    for item in input_list:
        if item not in l1:
            count += 1
            l1.append(item)
    return count

def lru(n, reference_list):
    paged_mem = []
    num_unique_el = count_unique_elem(reference_list)
    if num_unique_el <= n:
        for el in reference_list:
            if el not in paged_mem:
                paged_mem.append(el)
        paged_mem.extend([-1] * (n - num_unique_el))
    
    least_recently_used = -1
    seen_list = [-1]
    
    for page in reference_list:
        if page not in paged_mem:
            if len(paged_mem) < n:
                paged_mem.append(page)
            else:
                paged_mem[paged_mem.index(least_recently_used)] = page
        if page in seen_list:
            seen_list.remove(page)
            seen_list.append(page)
        elif len(seen_list) < n:
            seen_list.append(page)
        else:
            seen_list.pop(0)
            seen_list.append(page)
        least_recently_used = seen_list[0]

    return paged_mem
        