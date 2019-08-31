list=[]
m=input()
n=int(input())
lens=len(m)
max=0
chk=0
k=0

for i in range(n):
    chk=0
    word, g=input().split()
    wlen=len(word)
    if lens > wlen:
        continue

    for j in range(lens):
        chk=word.find(m[j])
        if chk == -1: #chk가 -1이면 글자를 발견못했다는 거니까 다음 문장을 받습니다---------------
            break
    if chk == -1:
        continue #--------------------------------------------------여기까지 위 과정
    else:
        list+=[[word, int(g) / int(wlen-lens)]] #list에 [[문장A, 점수A], [문장B,점수B]] 이런식
        k+=1
        if k>=2:
            if (list[max][1] < list[k-1][1]): #새로 문장 받을때마다 최댓값을 비교해줍니다.
                max=k

if list == []:
    print('No Jam')
else:
    print(list[max][0])
