def divide_chunks(l, n):
    for i in range(0, len(l), n):
        yield l[i:i + n]

def separate_liquids(glass):
    if len(glass) == 0:
        return []
    liquids = []
    density_chart = {'H':3, 'W': 2, 'A':1, 'O':0}
    reverse_density_chart = {3:'H', 2:'W', 1:'A', 0:'O'}

    all_liquids = []
    glass_width = len(glass[0])

    for level in glass:
        for el in level:
            if el not in liquids:
                liquids.append(el)
            all_liquids.append(el)
    num_liquids = len(liquids)

    sorted_densities = []
    sorted_liquids = []
    
    for liquid in all_liquids:
        sorted_densities.append(density_chart[liquid])
    sorted_densities.sort()

    for density_val in sorted_densities:
        sorted_liquids.append(reverse_density_chart[density_val])
    
    num_elements = len(all_liquids)
    
    output = list(divide_chunks(sorted_liquids, glass_width))
    
    return(output)