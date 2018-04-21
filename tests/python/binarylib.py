# Python integers are only 32 bits
def binary_string(integer):        
    assert type(integer) == int    
    mask = 1    
    binary = ""
    
    for i in range(0,64):
        if(integer & mask != 0):
            binary = "1" + binary
        else:
            binary = "0" + binary
        mask = mask + mask
        
    return binary
