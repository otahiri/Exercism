def response(hey_bob):
    if not hey_bob:
        return "Fine. Be that way!"
    elif hey_bob.rstrip().endswith('?') and hey_bob.isupper():
        return "Calm down, I know what I'm doing!"
    elif hey_bob.rstrip().endswith('?'):
        return "Sure."
    elif hey_bob.isupper():
        return "Whoa, chill out!"
    elif hey_bob.isspace():
        return "Fine. Be that way!"
    else:
        return "Whatever."
