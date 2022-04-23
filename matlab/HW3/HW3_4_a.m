N = 10000;
count = 0;

L = -4;
R = 4;

for k=1:N
    x = (R-L)*rand+L;
    y = rand;

    if y <= exp(-(x^2)/2)/sqrt(2*pi)
        count = count + 1;
    end
end

fprintf("%f\n",(count/N)*(R-L)*1);