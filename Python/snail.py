def snail(snail_map):
    limit = len(snail_map) - 1
    solution = []
    if len(snail_map) == 0:
        return []
    if len(snail_map) == 1:
        return snail_map[0]
    if len(snail_map) == 2:
        return snail_map[0] + snail_map[1][::-1]
    # get top row
    while limit > 1:
        # top left to right
        solution.extend(snail_map[len(snail_map) - limit - 1][len(snail_map) - limit - 1 : limit  + 1])
        
        # get rightmost down
        for i in range(len(snail_map) - limit, limit + 1, 1):
            solution.append(snail_map[i][limit])
        
        # get bottom right to left
        solution.extend(snail_map[limit][::-1][len(snail_map) - limit: limit + 1])
        
        #get down to up
        for i in range(limit - 1, len(snail_map) - limit -1 , -1):
            solution.append(snail_map[i][len(snail_map) - limit - 1])
        limit -= 1
    if len(solution) == 8:
        solution.append(snail_map[len(snail_map)//2][len(snail_map)//2])
    print(solution)
    return solution