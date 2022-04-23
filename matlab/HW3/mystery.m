function p = mystery(L, R)

N = 10000;
count = 0;



for k=1:N
    x = (R-L)*rand+L;
    y = rand;

    if y <= exp(-(x^2)/2)/sqrt(2*pi)
        count = count + 1;
    end
end

p = count/N;