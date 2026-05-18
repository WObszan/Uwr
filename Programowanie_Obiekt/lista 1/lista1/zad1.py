### imperatywnie ###
def silnia(n):
    wynik = 1
    while n > 0:
        wynik *= n
        n -= 1
    return wynik

### funkcyjnie ###
def silnia(n):
    if n == 0 or n == 1:
        return 1
    return n * silnia(n-1)

### Symbol Newtona funkcyjnie###
def binom(n, k):
    return int (silnia(n) / (silnia(k) * silnia(n - k)))

### wypisanie funkcyjnie ###
def pascal_n_row(n):
    return [binom(n,k) for k in range(n+1)]

print(pascal_n_row(5))
