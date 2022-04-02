% circle size
% n은 3부터 시작해야한다 
% -> 가장작은 polygon은 삼각형
n = 10;
for k=1:8
    A_n = (n/2)*sin(2*pi/n);
    B_n = n*tan(pi/n);
    rho_n = (A_n+B_n)/2;
    n=10*n;
    fprintf("%10d %10f %10f %10f %10f\n",n ,A_n,B_n,rho_n,abs(rho_n-pi));
end