% Problem : Increas function check
L = input('L 입력');
R = input('R 입력');
b = input('b 입력');
c = input('c 입력');

if L > -b/2
    fprintf('증가함수임');
else
    fprintf('감소함수임');
end

if L > -b/2
    fprintf('최소값 : %d',L);
elseif R > -b/2
    fprintf('최소값 : %d',-b/2);
else
    fprintf('최소값 : %d', R);
end

