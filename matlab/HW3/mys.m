function sig = mys(x)
tot = 0;

for n=1:length(x)
    tot = tot + (x(n)-mym(x))^2;
end
tot = tot / (length(x)-1);
sig = sqrt(tot);