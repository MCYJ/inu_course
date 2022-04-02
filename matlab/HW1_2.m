% 1) n=10 일 때 B(전체 cut tiles의 수)를 계산
n = 10;
n1 = 0;
B = 0;
for k = 1:n
    n1 = n1 + floor(sqrt(n^2-k^2));
    B = B + ceil(sqrt(n^2-k^2)) - floor(sqrt(n^2-k^2));
    fprintf('%f %f\n', ceil(sqrt(n^2-k^2)), floor(sqrt(n^2-k^2)))
end
rhs = (4*n1)/(n^2);
fprintf('1) n=10 일 때 B : %d개\n', B*4);

% 2) n=10000 일 때 rho_n과 error를 명령창에 출력
n = 10000;
n1 = 0;
B = 0;
for k = 1:n
    n1 = n1 + floor(sqrt(n^2-k^2));
    B = B + ceil(sqrt(n^2-k^2)) - floor(sqrt(n^2-k^2));
end
rho_n = (4*(n1+B/2))/(n^2);
err = abs(pi-rho_n);
fprintf('2) n=10000 일 때 rho_n : %12.6f\n', rho_n);
fprintf('2) n=10000 일 때 error : %12.6f\n', err);
% Lecture2 page27의 결과보다 오차가 줄어들었다. 
% cut tile의 근사를 포함시켰기 때문에 오차가 줄어든 것으로 사료됨
