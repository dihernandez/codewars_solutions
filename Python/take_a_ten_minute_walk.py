def isValidWalk(walk):
    #determine if walk is valid
    num_dir = {}
    for step in ['n','s','e','w']:
        num_dir[step] = 0
    for step in walk:
        if step in num_dir.keys():
            num_dir[step] += 1
    zero_displacement = num_dir['w'] == num_dir['e'] and num_dir['n'] == num_dir['s']
    return zero_displacement and len(walk) == 10