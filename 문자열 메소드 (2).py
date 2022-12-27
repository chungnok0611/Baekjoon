s='wellcome to python'
print(s.startswith('wellcome')) #특정단어('what')으로 시작하는지? True 또는 False 나옴
print(s.endswith('python')) #특정단어('python')으로 끝나는지? True 또는 False 나옴
s1='...wellcome to python...'
print(s1.strip('.')) #불 필요 한 부분('.')을 삭제
print(s.replace('python','java')) #특정단어('python')을 특정단어('java')로 교체
print(s.find('python')) #인덱스 기준으로 특정부분('python')을 찾는다
s2='집가고싶다'
print(s2.center(11,'-')) #다른 무자들 사이 가운데로 