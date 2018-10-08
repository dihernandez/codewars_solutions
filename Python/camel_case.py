def camel_case(string):
    return "".join([x[0].upper() + x[1:] for x in string.split()])