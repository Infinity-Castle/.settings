def is_prime(n, start=2):
    """ Recursive function to check if a number is prime.
    Args:
        n (int): The number to check for primality.
        start (int, optional): The starting point for divisibility check. Defaults to 2.
    Returns:
        bool: True if n is prime, False otherwise.
    """
    if n < 2:
        return False
    if n <= 3:
        return True
    if n % start == 0:
        return False
    if start * start > n:
        return True
    return is_prime(n, start + 1)

def print_primes(limit):
    """ Prints all prime numbers up to the given limit.
    Args:
        limit (int): The upper limit for checking prime numbers.
    """
    for num in range(2, limit + 1):
        if is_prime(num):
            print(num)

# Get input from the user
user_input = input("Enter the upper limit for prime numbers: ")

# Convert the input to an integer
try:
    limit = int(user_input)
except ValueError:
    print("Invalid input. Please enter an integer.")
else:
    # Call the print_primes function with the user input
    print_primes(limit)