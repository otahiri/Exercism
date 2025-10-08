def steps(number):
    count = 0
    if number < 1:
        raise ValueError("Only positive integers are allowed")
    while number != 1:
        number = number * 3 + 1 if number % 2 else number / 2 
        count += 1
    return count
