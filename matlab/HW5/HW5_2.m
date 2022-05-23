s1 = 'apple';
s2 = 'pizza';
a = 1;
c0 = {upper(s1), upper(s2)};

% 잛은 문자열의 길이 저장
short = min(size(c0{1},2),size(c0{2},2));
size1 = size(c0{1},2);
size2 = size(c0{2},2);
k = 1;
while k<=short && c0{1}(k)<=c0{2}(k)
    k = k+1;
end

if k <= short+1
    a = 0;
else
    if size1 < size2
        a = 0;
    else
        a = 1;
    end
end
a