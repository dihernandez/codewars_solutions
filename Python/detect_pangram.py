import string

def is_pangram(s):
    letters = {c.lower() for c in s if c.isalpha()}
    return len(letters) == 26
