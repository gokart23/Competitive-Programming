import sys
import math

def is_prime(number, primes_list=[2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]):
    if number%2 == 0 or number < 0:
        return False
    if number <= primes_list[-1] and number in primes_list:
        return True
    for check_div in range(3, int(math.ceil(math.sqrt(number))) + 1, 2):
        if number % check_div == 0:
            return False
    primes_list.append(number)
    #print "Found prime: added %s to list [%d]" % (number, len(primes_list))
    return True

def quadratic_fn(number, a, b):
    return (number**2) + (a*number) + b

def get_prime_limit(a, b):
    prime_limit=1
    nums = []
    cur_num = quadratic_fn(prime_limit, a, b)
    while is_prime(cur_num):
        nums.append(cur_num)
        prime_limit += 1
        cur_num = quadratic_fn(prime_limit, a, b)
    #print "(%d, %d) : %s [%d/%d] - failed %d (%s)" % (a, b, ','.join([str(x) for x in nums]), prime_limit, len(nums), cur_num, is_prime(cur_num))
    return prime_limit

def print_limit(a, b, prime_limit):
    return
    if prime_limit >= 40:
        print "n**2 + (%d)*n + %d generates primes till %d" % (a, b, prime_limit)

def check_a(start_val, b):
    sys.stdout.write("%d," % (b))
    max_prime_limit, max_a = 0, 0
    for a in range(start_val, 1000, 2):
        prime_limit = get_prime_limit(a, b)
        print_limit(a, b, prime_limit)
        if max_prime_limit < prime_limit:
            max_prime_limit, max_a = prime_limit, a

        prime_limit = get_prime_limit(-a, b)
        print_limit(-a, b, prime_limit)
        if max_prime_limit < prime_limit:
            max_prime_limit, max_a = prime_limit, -a
    return (max_prime_limit, max_a)

if __name__ == "__main__":
    mapping = dict()
    # Only even prime is 2 - check for that
    mapping[2] = (2, check_a(2, 2))

    for b in range(3, 1001, 2):
        if not is_prime(b):
            continue
        mapping[b] = (b, check_a(1, b))
    print "\n"
    val = max( mapping.values(), key=lambda x: x[1][0] )
    print val, ": ", val[0] * val[1][1]
