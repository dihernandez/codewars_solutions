import math
def divvy(mylist):
    output = []
    for i in range(3):
        output.append(mylist[i*3:i*3 + 3])

    return output    

matrix = []
matrix.extend(divvy([1,2,3,4,5,6,7,8,9]))
matrix.extend(divvy([2,3,1,5,6,4,8,9,7]))
matrix.extend(divvy([3,1,2,6,4,5,9,7,8]))
matrix.extend(divvy([4,5,6,7,8,9,1,2,3]))
matrix.extend(divvy([5,6,4,8,9,7,2,3,1]))
matrix.extend(divvy([6,4,5,9,7,8,3,1,2]))
matrix.extend(divvy([7,8,9,1,2,3,4,5,6]))
matrix.extend(divvy([8,9,7,2,3,1,5,6,4]))
matrix.extend(divvy([9,7,8,3,1,2,6,4,5]))

#print(matrix)

squares = []
fsquares = []
for s in range(9):
	fsquares.append([])
#for i in range(9):
#    idx = math.floor(i/3)
#    squares[idx].extend(matrix[idx][idx: idx + 3])
#   for i in range(9):
#       intermediate  = matrix[i*3 : i*3 + 3]
#       print("1 ", intermediate)
#   
#       intermediate.extend(matrix[i*6 : i*6 + 3])
#       print("2 ", intermediate)
#       intermediate.extend(matrix[i*9 : i*9 + 3])
#       print("3 ", intermediate)
#       squares.append(intermediate)

#for i in range(3):
#    squares.append(matrix[i

#for i in range(len(matrix)):
#    intermediate = []
#    for j in range(len(matrix[i])):
#            intermediate.append(matrix[i][j])
#    squares[i].append(intermediate)
#print([m for i,m in enumerate(matrix) if i%3 == 0])
squares.append([m for i,m in enumerate(matrix) if i%3 == 0])
squares.append([m for i,m in enumerate(matrix) if i%3 == 1])
squares.append([m for i,m in enumerate(matrix) if i%3 == 2])

#print(squares)
# for i in range(3):
# fsquares[0] = squares[0][0:3]
# fsquares[1] = squares[1][3:6]
# fsquares[2] = squares[2][6:9]
# fsquares[3] = squares[0][3:6]
# fsquares[4] = squares[1][6:9]
# fsquares[5] = squares[2][9:12]

for i in range(9):
	idx = math.floor(i/3)
	fsquares[i] = squares[idx][(i%3)*3 : (i%3)*3 + 3]

# for i in range(3):
# 	fsquares[(i*3)] = squares[i][3*i : 3*i + 3]
# 	print("idex is ", i*3, " squares idx is ", 3*i, " ", 3*i + 3)
# 	fsquares[((i*3) + 1)] = squares[i][3*i : 3*i + 3]
# 	print(i*3 + 1)
# 	fsquares[((i*3) + 2)] = squares[i][3*i : 3*i + 3]
# 	print(i*3 + 2)
#for i, sub_square in enumerate(squares):
#	fsquares[i].append(sub_square)
#print(squares[0])
print("squares are ", squares)
print("-----")
print(len(fsquares))
for f in fsquares:
	print(f)