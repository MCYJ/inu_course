function [y, C, S] = Bubble(x)
n=length(x);
C = 0;
S = 0;
for k=n-1:-1:1
    C = C+1;
    if x(k+1) < x(k)
        temp = x(k+1);
        x(k+1) = x(k);
        x(k) = temp;
        S = S+1;
    end
end
y = x;