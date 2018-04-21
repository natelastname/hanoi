import random
from binarylib import binary_string

test_count = 500
test_range = 2048
output_dir = "../cases/"

# like base 2, in base -1+i we can "right shift" by dividing by -1+i.
# we then look at the remainder to see if we just shifted out a 0 or 1      
def encode_binarion(A):    
    quotient_r = A[0]
    quotient_i = A[1]    

    binary = ""    
    for i in range(0,64):
        if(quotient_r == 0 and quotient_i == 0):
            #break # it could break but it has to fill with 0s
            pass
        if((quotient_i ^ quotient_r) & 0x01 != 0):
            binary = "1" + binary
            quotient_r = quotient_r - 1
        else:
            binary = "0" + binary
            
        temp = quotient_r
        quotient_r = (-1 * quotient_r) + quotient_i;
        quotient_i = (-1 * temp) + (-1 * quotient_i);
        
        quotient_i = quotient_i // 2
        quotient_r = quotient_r // 2
    return binary


def gauss_mult(A,B):
    return [(A[0]*B[0])-(A[1]*B[1]),(A[0]*B[1])+(A[1]*B[0])]
    
def binarion_term(n):
    if(n == 0):
        return [1,0]
    else:
        return gauss_mult(binarion_term(n-1),[-1,1])
        
def gauss_add(A,B):
    return [A[0]+B[0], A[1]+B[1]]

def decode_binarion(A):
    total = [0,0]
    for i in range(0,64):
        if(A[i] == "1"):
            total = gauss_add(total,binarion_term(63-i))

    return total
            
# tests the consistency of the python test generation
def test_python():
    for i in range(1,test_count):    
        a = random.randint(-1*test_range,test_range)
        b = random.randint(-1*test_range,test_range)
        
        res = encode_binarion([a,b])
        assert decode_binarion(res) == [a,b]

def gen_tests():

    # create tests for constructing binarions
    tests = ""
    
    for i in range(0,test_count):
        tests += str(i) + "\n"
        tests += "In\n"
        a = random.randint(-1*test_range,test_range)
        b = random.randint(-1*test_range,test_range)
        tests += binary_string(a) + "\n"
        tests += binary_string(b) + "\n"
        tests += "Out\n"
        tests += encode_binarion([a,b]) + "\n"
        tests += "END\n\n"
        
    with open(output_dir+"binarion_constructor", "w") as fp:
        fp.write(tests)
        
    # create tests for converting binarion to normal complex
    tests = ""
        
    for i in range(0,test_count):
        a = random.randint(-1*test_range,test_range)
        b = random.randint(-1*test_range,test_range)
        
        tests += str(i) + "\n"
        tests += "In\n"
        tests += encode_binarion([a,b]) + "\n"
        tests += "Out\n"
        tests += binary_string(a) + "\n"
        tests += "END\n\n"
        
    with open(output_dir+"binarion_interpret_r", "w") as fp:
        fp.write(tests)
        
    tests = ""
        
    for i in range(0,test_count):
        a = random.randint(-1*test_range,test_range)
        b = random.randint(-1*test_range,test_range)
        
        tests += str(i) + "\n"
        tests += "In\n"
        tests += encode_binarion([a,b]) + "\n"
        tests += "Out\n"
        tests += binary_string(b) + "\n"
        tests += "END\n\n"
        
    with open(output_dir+"binarion_interpret_i", "w") as fp:
        fp.write(tests)        
        

test_python()
gen_tests()










































