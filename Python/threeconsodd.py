
def odd(x):
    return x%2!=0

count1 = False
count2 = False
flag = True
arr = [1,1,2,1,1]

for i in arr:
    if odd(i) and not count1:
        count1 = True
    elif odd(i) and count1 and not count2:
        count2 = True
    elif odd(i) and count1 and count2:
        print("True")
        flag = False
    elif not odd(i) and count1 and count2:
        count1 = False
        count2 = False
    elif not odd(i) and count1:
        count1 = False
    
if flag:
    print("False")