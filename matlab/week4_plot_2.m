x = linspace(-2,3,200);
%y = (sin(5*x).^(-x/2))./(1+x.^2);
y = (sin(5*x).*exp(-x/2))./(1+x.^2);
plot(y);