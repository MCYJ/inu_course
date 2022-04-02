% 2행 3열
a = [1,2,3;4,5,6];

% concatenate 행의 갯수가 서로 같으면 concat 가능
b = [a,a];

% 특정 위치의 element 호출
b(1:2,3:4)
