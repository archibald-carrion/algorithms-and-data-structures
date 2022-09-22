# recursive function
def recursive_factorial(number):
    if (number==0) :
        return 1
    else:
        return number*recursive_factorial(number-1)

# factorial function
def factorial_iterative(number):
    buffer = 1
    for i in range(1, number+1):
        buffer = buffer*i
    return buffer

print(recursive_factorial(5))
print(factorial_iterative(5))

# 5*4*3*2*1 --> 120