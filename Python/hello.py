# for input of int : a = int(input(a))
# if, elif, else

# array v
# v = []
# v.append(element) - push_back
# v.insert(idx, element) - v[idx] = element
# v.sort()

# set s
# s = {}
# s.add(element)
# s.remove(element)
# s1.union(s2) - unites the 2 sets
# s1.intersect(s2) - finds intersection of 2 sets

# for x in vector:
#    print(x)

# for i in range((start,end)):
#    print(i)

#def calc(a,b)
#    return (a+b)
import math
import sys
import os

if os.path.exists("./1.txt"):
    sys.stdin = open("1.txt", "r")
    sys.stdout = open("2.txt", "w") 

import array
m = 10**18 + 31

def binpow(n):
    if(n==0):
        return 1
    x = binpow(n//2)
    if(n%2==0):
        return (x*x)%m
    return (42*x*x)%m

def main():
    a = 960002411612632915
    arr = []
    last = binpow(719712190406269305)
    arr.append(last)
    n = 1
    cnt = 0
    while True:
        if(n==100000):
            break
        last = binpow(last)
        arr.append(last)
        n = n+1
        
    for i in arr:
        print(i, end = ",")

if __name__ == "__main__":
    main()
    
    

# vector = [1,2,2]
# print(vector)
# set = {2,1,2}
# print(set)

# help('cmath')
