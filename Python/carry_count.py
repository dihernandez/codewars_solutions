def solve(input_string):
    no_carry = "No carry operation\n"
    operations = "carry operations\n"
    num_carry_operations = 0
    prev_carry = False
    to_print = ""
        
    for l in input_string.split("\n"):
        prev_carry = False
        nums = l.split(" ")
        num_1 = nums[0]
        num_2 = nums[1]
                
        for idx in range(len(num_1) - 1, -1, -1):
            to_add = 0
            if prev_carry:
                to_add = 1
            if int(num_1[idx]) + int(num_2[idx]) + to_add > 9:
                prev_carry = True
                num_carry_operations += 1
            else:
                prev_carry = False
        if num_carry_operations == 0:
            to_print += no_carry
        else:
            num_ops = str(num_carry_operations) + " " + operations
            to_print += (num_ops)
        num_carry_operations = 0
    return to_print[:-1]