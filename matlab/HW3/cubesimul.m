function out=cubesimul(A)
% 오차설정
tol = 10^(-8);

% count 초기화
count = 0;

% 최초 L, W, H 설정
L = A;
W = 1;
H = 1;

% 요구되는 오차 이상일 경우 루프반복
while abs(L - 50^(1/3)) > tol
    % 카운트 증가
    count = count + 1;
    L = (L+W+H)/3;
    W = sqrt(A/L);
    H = sqrt(A/L);
end

% 전체자리수 20자리 소수점 11자리 출력
fprintf("근사값: %20.11f 반복횟수: %d\n", L, count);
out = L;