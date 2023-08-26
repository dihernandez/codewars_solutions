numeral_map = {'M':1000,'D':500, 'C':100, 'L':50, 'X':10, 'V': 5, 'I' : 1}
decimal_map = {1000: 'M',500:'D',100:'C', 50: 'L', 10 : 'X', 5:'V', 1:'I'}
# helper functions
def is_lesser(num1, num2):
    order_of_precedence = ['M','D','C','L','X','V','I']
    idx_num1 = order_of_precedence.index(num1)
    idx_num2 = order_of_precedence.index(num2)
    return idx_num1 < idx_num2

class RomanNumerals:
    def to_roman(val):
        roman_num = ''
        decimals = sorted(decimal_map.keys(), reverse = True)
        while len(decimals) > 0:
            selected_key = decimals.pop(0)
            print("selected key is ", selected_key, "val is ", val)
            num_repetitions = 0
            while val - selected_key >= 0:
                if num_repetitions < 3:
                    val = val - selected_key
                    roman_num += decimal_map[selected_key]
                    num_repetitions += 1
                else:
                    ordered_numerals = ['M', 'D', 'C', 'L', 'V','I']
                    decimal_map_index = ordered_numerals.index(roman_num[-1])
                    roman_num = roman_num[:-3]
                    roman_num += (ordered_numerals[decimal_map_index + 1])
                    roman_num += (ordered_numerals[decimal_map_index])
        return roman_num

    def from_roman(roman_num):
        value = 0
        if len(roman_num) == 1:
            return numeral_map[roman_num[0]]
        for i in range(len(roman_num) - 1):
            if is_lesser(roman_num[i + 1], roman_num[i]):
                value += numeral_map[roman_num[i + 1]] - numeral_map[roman_num[i]]
            else:
                value += numeral_map[roman_num[i]]
                if i == len(roman_num) - 2:
                    value += numeral_map[roman_num[-1]]
        return value