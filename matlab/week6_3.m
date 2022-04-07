% L, W 근사

A = input('A :');
L = A;
W = 1;

% 오차 10^(-15) 할당
tol = 10e-15;
% 참값 sprt() 이용하여 계산
true_val = sqrt(A);

% 상대오차 relative tolerance : |L-W|/W
while abs(L-W)/W > tol
    L = (L+W)/2;
    W = A/L;
end

% 참값과 근사값 출력
fprintf("참값 : %.7f\n", true_val);
fprintf("근사값 : %.7f\n", W);