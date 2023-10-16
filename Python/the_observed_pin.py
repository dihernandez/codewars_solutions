import itertools

def get_product(possible_digit_sources):
    combinations = list(itertools.product(*possible_digit_sources))
    return combinations

def get_pins(observed):
    possible_observed_digits = []
    possible_digit_sources = []
    num_digits = len(observed)
    possible_mistaken = {0:[0,8], 1:[1,2,4], 2:[1,2,3,5], 3:[2,3,6], 4:[1,4,5,7], 5:[2,4,5,6,8], 6:[3,5,6,9], 7:[4,7,8], 8:[5,7,8,9,0], 9:[6,8,9]} 
    
    results = []
    
    for number in observed:
        digit = int(number)
        possible_observed_digits.extend(possible_mistaken[digit])
        possible_digit_sources.append(possible_mistaken[digit])
    possible_combinations = get_product(possible_digit_sources)
    
    for num in possible_combinations:
        guess = ""
        for el in num:
            guess += str(el)
        results.append(guess) 
    res = [*set(results)]
    return res