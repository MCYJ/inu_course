function [xNew, yNew] = Smooth(x,y)

n = length(x);
xNew = zeros(n,1);
yNew = zeros(n,1);

for i=1:n
    xNew(i) = (x(i) + x(rem(i, n)+1))/2;
    yNew(i) = (y(i) + y(rem(i, n)+1))/2;
end
