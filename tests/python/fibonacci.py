import random
from binarylib import binary_string


test_count = 500
test_range = 4096
output_dir = "../cases/"

max_fibint = [0]
fib_table = [1]

# generate a fibonacci lookup table
# calculate the maximum fibonacci representable 64 bit number
def gen_LUT():
    fb_1 = 1
    fb_2 = 1
    
    # gen table
    for i in range(0,64):
        # make sure it doesn't become a float
        # this might trip on certain machines?
        assert type(fb_1 + fb_2) == int
        temp = fb_1 + fb_2
        fb_1 = fb_2
        fb_2 = temp    
        fib_table.append(fb_2)
        
        
    # calculate max representable
    # (it will be the number 10101010...1)
    i = 63
    while i >= 0:
        max_fibint[0] += fib_table[i]
        i = i - 2
        
# nth fibonacci number
# we only need the first 64 terms in this application.
# Also, it is aligned so that f_0 is the first bit (f_-1 would have to be 1)
def fibonacci(n):
    assert type(n) == int
    assert n < 64
    assert n >= 0
    return fib_table[i]
        
        
# returns [value, index]
def greatest_lteq(n):
    assert type(n) == int
    assert n <= max_fibint[0]
    
    if(n == 0):
        return [0,0]
        
    for i in range(0,65):
        if(n < fib_table[i]):
            return [fib_table[i-1], i-1]
    
def encode_fibonacci(n):
    if(n == 0):
        return 0
    assert type(n) == int
    assert n <= max_fibint[0]

    remaining = n
    fibo = 0
    # perform greedy algorithm
    while(True):
        temp = greatest_lteq(remaining)
        fibo += 2**temp[1]
        remaining -= temp[0]
        if(remaining == 0):
            return fibo

def decode_fibonacci(n):
    assert type(n) == int
    assert n <= max_fibint[0]
    
    total = 0
    A = binary_string(n)
    
    for i in range(0,64):
        if(A[i] == "1"):
            total += fib_table[63-i]

    return total

def generate_tests():
    tests = ""    
    for i in range(0,test_count):
        tests += str(i) + "\n"
        tests += "In\n"
        a = random.randint(0,test_range)
        tests += binary_string(a) + "\n"
        tests += "Out\n"
        tests += binary_string(encode_fibonacci(a)) + "\n"
        tests += "END\n\n"
        
    with open(output_dir+"fibonacci_constructor", "w") as fp:
        fp.write(tests)
        
    tests = ""    

    for i in range(0,test_count):
        tests += str(i) + "\n"
        tests += "In\n"
        a = random.randint(0,test_range)
        tests += binary_string(encode_fibonacci(a)) + "\n"
        tests += "Out\n"
        tests += binary_string(a) + "\n"
        tests += "END\n\n"
        
    with open(output_dir+"fibonacci_interpret", "w") as fp:
        fp.write(tests)

# test consistency of python implemenations
def test_python():
    for i in range(0,2*test_count):
        if(i > test_count):
            a = random.randint(0,test_range)
        else:
            a = i
        assert decode_fibonacci(encode_fibonacci(a)) == a

gen_LUT()
test_python()
generate_tests()

for i in range(0,64):
    pass
    #print(str(i)+":"+str(greatest_lteq(i)))
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    