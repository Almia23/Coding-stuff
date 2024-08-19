
x=-123
flag = False
if x<0:
    flag = True
    x*=-1
c=0
while x>0:
    r=x%10
    x=x//10
    c=c+r
    print(c)
    c*=10
c//=10
if flag:
    c=c*-1
print(c)