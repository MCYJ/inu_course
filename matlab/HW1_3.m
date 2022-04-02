% n=100인 경우 |pi-micro_n|을 계산
n = 100;
u_n = 0;

for k = 1:n
    u_n = u_n + (1/k)^4;
end

micro_n = (90*u_n)^(1/4);
fprintf("n=100인 경우 |pi-micro_n| 계산 : %12.10f\n", abs(pi-micro_n));

% n=500인 경우 |pi-micro_n|을 계산
n = 500;
u_n = 0;

for k = 1:n
    u_n = u_n + (1/k)^4;
end

micro_n = (90*u_n)^(1/4);
fprintf("n=500인 경우 |pi-micro_n| 계산 : %12.10f\n", abs(pi-micro_n));

% n=1000인 경우 |pi-micro_n|을 계산
n = 1000;
u_n = 0;

for k = 1:n
    u_n = u_n + (1/k)^4;
end

micro_n = (90*u_n)^(1/4);
fprintf("n=1000인 경우 |pi-micro_n| 계산 : %12.10f\n", abs(pi-micro_n));