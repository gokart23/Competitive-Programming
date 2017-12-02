import itertools

def gen_primes(start, end):
    primes = []
    candidates = range(start, end, 2)
    for idx, candidate in enumerate(candidates):
        if candidates[idx] != -1:
            primes.append(candidate)
            for multiple in range(3*candidate, end, 2*candidate):
                candidates[(multiple-2)/2] = -1
    del candidates
    return primes

primes = [2] + gen_primes(3, 10000)
primes = filter(lambda x: x >= 1000, primes)

solutions = dict()
for prime in primes:
    count = []
    for perm_int in set(map(lambda x: int(''.join(x)), itertools.permutations(str(prime))) ):
        if perm_int > prime and perm_int in primes:
            count.append(perm_int)
    if len(count) >= 2:
        val = filter(lambda x: (2*x - prime) in count, count)
        if len(val) > 0:
            print prime, val, map(lambda x: 2*x - prime, val)
