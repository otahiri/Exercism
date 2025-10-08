def is_armstrong_number(number):
    tmp = number
    res = 0
    power = len(str(number))
    while tmp > 0:
        res += pow(tmp % 10, power)
        tmp //= 10
    print(res)
    return number == res
