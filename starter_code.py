import math 

t="\t"

# Generate prime numbers infinitely
def InfinityPrimes():
    isPrime = lambda x: x > 1 and \
    all(x % num != 0 for num in range(2, int(x ** 0.5) + 1))
    num = 2
    while True:
        if isPrime(num):
            yield num
        num += 1

# Get first 15 primes
nextP=InfinityPrimes()
possible_prime=[next(nextP) for _ in range(15)]
print(t, "First 15 primes:", possible_prime)

# Multiply all primes together - this shows how big numbers get, excluded 13,23,27
product = math.prod([2, 3, 5, 7, 11, 17, 19, 29, 31, 41, 43, 47])
print(t, "Product of primes:", product)

    ##55580745059070

# Example: head and tail
# head = first 5 digits (55580)
# tail = last 5 digits (59070)
# middle = MISSING - we need to find it
head_and_tail = "55580|59070"

def primeRecovery(HeadTail, possiblePrime):
    """
    Find the nearest prime number that has the given head and tail.
    
    Args:
        HeadTail: string with format "head|tail" (e.g., "55580|59070")
        possiblePrime: list of prime numbers to use for building candidates
    
    Returns:
        The full prime number if found, or None if not found
    """
    head, tail = HeadTail.split("|")
    
    # Start building numbers with head + some middle + tail
    # Try different middle lengths and combinations
    # Check if result is prime
    # Return first valid prime found
    
    pass

result = primeRecovery(head_and_tail, possible_prime)
print(t, "Result:", result)




