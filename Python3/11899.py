s=input()

chk1, chk2, ans=0, 0, 0

for i in s:
    if i==')':
        if chk1==0:
            ans+=1
        else:
            chk1-=1
    else:
        chk1+=1

for i in s[::-1]:
    if i=='(':
        if chk2==0:
            ans+=1
        else:
            chk2-=1
    else:
        chk2+=1

print(ans)




"""
a=input()
while a.count('()')!=0:
	a=a.replace('()','')
print(len(a))
"""
