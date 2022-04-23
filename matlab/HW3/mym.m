function mu = mym(x)
tot = 0;
for n=1:length(x)
    tot = tot + x(n);
end
mu = tot/length(x);