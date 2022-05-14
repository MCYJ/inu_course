
x = 10:10:80;
y = PerfectShuffle(x);
count = 1;
while sum(abs(x-transpose(y)))>0
    y = PerfectShuffle(y);
    count = count + 1;
end
fprintf("%d\n", count);