function m = mmedian(x)
x = sort(x);
siz = rem(size(x), 2);
temp = size(x)/2;
if siz(2) == 0
    m = (x(temp(2)) + x(temp(2)+1))/2;
else
    m = x(ceil(temp(2)));
end