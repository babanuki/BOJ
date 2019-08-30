s=input()

while(s!=s.replace('PPAP', 'P')):
    s=s.replace('PPAP', 'P')

if s=='P':
    print('PPAP')
else:
    print('NP')
