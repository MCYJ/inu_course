%cut tile calculator
n = input('n :');
n1 = 0;
for k = 1:n
    n1 = n1 + floor(sqrt(n^2-k^2));
end
rhs = (4*n1)/(n^2);
fprintf('rhs : %12.8f\n',rhs);
fprintf('error : %12.8f\n',abs(pi-rhs));
