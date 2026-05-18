### imperatywnie ###
def gcd(p,q):
    rez = 1
    while q != 0:
        rez = q
        q = p%q
        p = rez
    return p

def wzglednie_pierwsze(n):
    wzglednie_pier = []
    for i in range(1,n+1):
        if gcd(n,i) == 1:
            wzglednie_pier.append(i)
    return wzglednie_pier

print(wzglednie_pierwsze(7))


### funkcyjnie ###
def gcd(p,q):
    if q == 0:
        return p
    return gcd(q, p % q)

def wzglednie_pierwsze(n):
    return [k for k in range(1, n+1) if gcd(n,k)==1]

print(wzglednie_pierwsze(7))