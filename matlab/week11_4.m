x = [30 50 10 60 40 20];
% vector x의 길이
n = length(x);
% compare 횟수와 swap횟수를 세기 위한 변수 초기화
c = 0;
s = 0;

% loop마다 
for k=1:n-1
    [x(k:n), C, S] = Bubble(x(k:n));
    c = c + C;
    s = s + S;
end

fprintf("%d %d\n", c, s);

