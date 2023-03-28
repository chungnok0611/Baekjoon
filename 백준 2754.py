#딕셔너리 사용
dic = {'A+':'4.3', 'A0':'4.0', 'A-':'3.7',
       'B+':'3.3', 'B0':'3.0', 'B-':'2.7',
       'C+':'2.3', 'C0':'2.0', 'C-':'1.7',
       'D+':'1.3', 'D0':'1.0', 'D-':'0.7',
       'F':'0.0'}
grade = input()
print(dic[grade])


#if 문,elif문 사용
a=input()
if a =='A+':
    print(4.3)
elif a =='B+':
    print(3.3)
elif  a =='C+':
    print(2.3)
elif  a =='D+':
    print(1.3)
elif  a =='A0':
    print(4.0)
elif  a =='B0':
    print(3.0)
elif  a =='C0':
    print(2.0)
elif   a =='D0':
    print(1.0)
elif   a =='A-':
    print(3.7)
elif   a =='B-':
    print(2.7)
elif   a =='C-':
    print(1.7)
elif   a =='D-':
    print(0.7) 
elif  a =='F': 
    print(0.0)


