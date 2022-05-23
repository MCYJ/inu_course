function a = compare1(s1,s2)
% s1, s2 대문자로 변경
c0 = {upper(s1), upper(s2)};

% 최초상태 0으로 설정
a = 1;
k = 1;

% 둘 중 더 짧은 문자열의 길이 저장
short1 = min(size(s1), size(s2));

% 짧은 문자열의 index를 초과하거나 동일한 index의 문자중 s1의 ASCII크기가 더 클 경우 종료
while (k <= short1 && s1(k) <= s2(k))
    
    k = k + 1;
end

% k가 short를 초과하지 않았다는 것은 s1의 k번째 문자가 s2의 k번째 문자보다 ASCII크기가 더 컸었다는 의미
if k <= short1
    a = 0;
else
    % s1의 길이가 s2보다 큰 경우
    if size(s1) > size(s2)
        a = 0;
    else
        a = 1;
    end
end