# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")
A = ['RR','GG','RG','GR']
# Implement your solution here
l={1:0, 2:0, 3:0, 4:0} #dictionary of vals
for i in A: #turned into more readable input
    if i=='RR':
        l[1]+=1
    elif i=='RG':
        l[2]+=1
    elif i=='GR':
        l[3]+=1
    else:
        l[4]+=1
if l[2]==0 and l[3]==0: #if no rg gr
    print(max(l[1],l[4]))
if l[2]==0 or l[3]==0: #if rg or gr missing, can only use the other once
    print(l[1]+l[4]+1)
if l[2]==l[3] and (l[1]>0 and l[4]>0):
    print((2*l[2]) + l[1] + l[4]) #if equal amount and both rr gg present

count = (2*min(l[2], l[3])) + l[1] + l[4] #pair rg gr

if l[1]>0 and l[3]-min(l[2], l[3])>0: #if any remaining gr, can add 1
    count+=1
if l[4]>0 and l[2]-min(l[2], l[3]): #if any remaining rg, can add 1
    count+=1
print(count)

