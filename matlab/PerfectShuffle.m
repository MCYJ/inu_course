function y=PerfectShuffle(x)
n=length(x);
y=zeros(n,1);
m=n/2;
for k=1:m
    y(2*k-1) = x(k);
    y(2*k) = x(k+4);
end