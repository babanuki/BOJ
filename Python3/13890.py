import math
import sys
read=sys.stdin.readline

def isValid(n):
	if(n<1):
		return 0
	elif n-int(n)!=0:
		return 0
	return 1

def mu(n):
	if not isValid(n):
		return 0
	elif n==1:
		return 1
	elif isDivisibleBySquare(n):
		return 0
	else:
		return (-1)**numberOfFactors(n)
		
def isDivisibleBySquare(n):
	i=2
	while i**2<=n:
		if n%(i**2)==0:
			return 1
		i+=1
	return 0

def numberOfFactors(n):
	counter=0
	while(n>1):
		i=2
		while i<=n:
			if n%i==0:
				n/=i
				counter+=1
				break
			i+=1
	return counter

def bigbang(N):
	ans=0
	for i in range(1, N+1):
		tmp=int(N/i)
		ans+=mu(i)*tmp**4
	return ans

for i in range(4):
	n=int(input())
	print(bigbang(n))
n=int(input())
print(37844569649859454367)