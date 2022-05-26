function a = compare1(s1,s2)
% a, k 초기화
a = 1;
k = 1;

% cell type으로 s1, s2를 대문자로 변환하여 저장
c0 = {upper(s1), upper(s2)};

% 잛은 문자열의 길이 저장
short = min(size(c0{1},2),size(c0{2},2));
size1 = size(c0{1},2);
size2 = size(c0{2},2);

% k의 크기가 짧은 문자열의 길이 이하이면서 첫번째문자열의 ascii순서가 뒷단어와 같은 상태
while k<=short && c0{1}(k)==c0{2}(k)
    k = k+1;
end

% loop가 짧은 문자열의 길이만큼 순회한 경우 : 
% s1, s2가 동일한 문자열로 이루어졌거나, 
% 짧은 문자열길이 만큼만 동일한 문자열이고, 길이가 다른 경우 
if k == short+1
    if size1 <= size2
        a = 1;
    else
        a = 0;
    end
% loop를 다 돌기전 ascii 크기가 서로 다른 경우 :
% loop를 탈출하게 만든 k번째 문자끼리 비교하여 순서 선택해야함
else
    if c0{1}(k) < c0{2}(k)
        a = 1;
    else
        a = 0;
    end
end