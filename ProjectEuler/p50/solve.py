import multiprocessing as mp

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

def check_sum(x):
    numbers, req_sum = x[0], x[1]
    if len(numbers) == 0:
        return (False, 0)

    curr_sum, start, end = numbers[0], 0, 1
    if curr_sum == req_sum:
#        print numbers[start:end], req_sum
        return (True, end-start)

    while end < len(numbers):
        while curr_sum > req_sum and start < end:
            curr_sum -= numbers[start]
            start += 1
            if curr_sum == req_sum:
#                print numbers[start:end], req_sum
                return (True, end-start)
        curr_sum += numbers[end]
        end += 1
        if curr_sum == req_sum:
#            print numbers[start:end], req_sum
            return (True, end-start)
    return (False, 0)

def process_inputs(x):
#    if idx % 1000 == 0:
#        print idx, "-", primes[idx]
    return (x[0][x[1][0]], check_sum(x[0][:x[1][0]], x[1][1]))

if __name__ == "__main__":
    max_res = (0, (0, 0))
    primes = [2] + gen_primes(3, 1000000)
    print "len(primes): ", len(primes)
    vals = [ (primes[:idx], x) for idx, x in enumerate(primes) ]
    pool = mp.Pool(processes=4)
    results = pool.map(check_sum, vals)
    max_res = max( filter( lambda (x,y): y[0], zip(primes, results) ), key=lambda x: x[1][1] )
    print max_res
