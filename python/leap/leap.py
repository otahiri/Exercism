def leap_year(year):
    return (not year % 4) and not (not year % 100 and year % 400)
