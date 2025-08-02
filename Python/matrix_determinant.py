def rank_one(matrix):
    if len(matrix) != 1 and len(matrix[0]) != 1:
        return False, "wrong matrix size"
    else:
        return matrix[0][0]

def rank_two(matrix):
    if len(matrix) != 2 and len(matrix[0]) != 2:
        return False, "wrong matrix size"
    else:
        a,b = matrix[0]
        c,d = matrix[1]
        return a*d - b*c

def select_minor(sel_x, sel_y, matrix):
    minor = []
    rank = len(matrix)
    for row in range(rank):
        m_row = []
        if row == sel_x:
            pass
        else:
            for col in range(rank):
                if col == sel_y:
                    pass
                else:
                    m_row.append(matrix[row][col])
        if len(m_row) > 0:
            minor.append(m_row)
    return minor

def rank_three(matrix):
    a_minor = select_minor(0, 0, matrix)
    b_minor = select_minor(0, 1, matrix)
    c_minor = select_minor(0, 2, matrix)
    a,b,c = matrix[0]
    return a*rank_two(a_minor) - b*rank_two(b_minor) + c*rank_two(c_minor)

def rank_n(matrix):
    rank = len(matrix)
    if rank <= 3:
        return rank_three(matrix)
    else:
        a_minor = select_minor(0,0,matrix)
        minors = []
        for pos in range(rank):
            minors.append(select_minor(0, pos, matrix))
        det = 0
        is_pos = True
        for idx, minor in enumerate(minors):
            if is_pos:
                det += matrix[0][idx]*rank_n(minor)
                is_pos = False
            else:
                det -= matrix[0][idx]*rank_n(minor)
                is_pos = True
        return det
        
def determinant(matrix):
    rank = len(matrix)
    if rank > 3:
        return rank_n(matrix)
    if rank == 3:
        return rank_three(matrix)
    elif rank == 2:
        return rank_two(matrix)
    elif rank == 1:
        return rank_one(matrix)
    else:
        return "not handled ever"