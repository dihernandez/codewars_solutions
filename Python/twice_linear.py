def calculate_u(n):
    u = [1]
    x = 1
    counter = 0
        
    if n == None:
       return u

    while len(u) < n:
        if x not in u:
            u.append(x)
        if 2*x + 1 not in u:
            u.append(2*x + 1)
        if 3*x + 1 not in u:
            u.append(3*x + 1)
        u.sort()
        counter += 1
        x = u[counter]
    return u
    
def dbl_linear(n):
    u = calculate_u(n)
    print(u)
    return u[-2]



# def calculate_u(n):
#     u = [1]
#     x = 1
#     counter = 0
        
#     if n == None:
#        return u

#     while True:
#         if len(u) >= n:
#             break
            
#         if x not in u:
#             u.append(x) 
#         if 2*x + 1 not in u:
#             u.append(2*x + 1)
#             print("in 2*x + 1", 2*x +1 )
#         if 3*x + 1 not in u:
#             u.append(3*x + 1)
#         u.sort()
        
#         x = u[counter]
#         counter += 1
#         print(u, "counter is", counter, "x is", x, "2x + 1 is", 2*x + 1)
#     return u
#     #1, 3, 4, 7, 9, 10, 13, 15, 19, 21, 22, 27, 
# def dbl_linear(n):
#     u = calculate_u(n)
#     print(u)
#     return u[-1]


# import math

# def calculate_u(n):
#     u = [1]
#     x = 1
#     counter = 0
        
#     if n == None:
#        return u

#     while True:
#         if len(u) >= 2**(math.log(n,2)):
#             break
            
#         if x not in u:
#             u.append(x) 
#         if 2*x + 1 not in u:
#             u.append(2*x + 1)
#             #print("appending 2*x + 1", 2*x +1 )
#         if 3*x + 1 not in u:
#             u.append(3*x + 1)
#             #print("appending 3*x + 1", 3*x +1 )
#         u.sort()
        
#         x = u[counter]
#         counter = sum(2*i for i in range(x)) 

#         #print(u, "counter is", counter, "x is", x, "2x + 1 is", 2*x + 1)
#     return u
#     #1, 3, 4, 7, 9, 10, 13, 15, 19, 21, 22, 27, 
# def dbl_linear(n):
#     u = calculate_u(n)
#     print(u)
#     return u[n]



