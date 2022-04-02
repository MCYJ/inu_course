% 내접원 외접원 이용하여 원의 크기 계산 및 오차출력
delta = input('delta?');
n = 3;
A_n = (n/2)*sin(2*pi/n);
B_n = n*tan(pi/n);
rho_n = (A_n+B_n)/2;
% 최초오차
error_n = B_n - A_n;
tic
while error_n > delta
    n = n + 1;
    A_n = (n/2)*sin(2*pi/n);
    B_n = n*tan(pi/n);
    rho_n = (A_n+B_n)/2;
    error_n = B_n - A_n; 
end
toc
fprintf("%10d %10f %10f %10.8f %10f\n", n, A_n, B_n, rho_n, error_n);