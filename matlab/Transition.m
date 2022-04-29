function y = Transition(P,x)

[n,n] = size(P);
y = zeros(n,1);

for i=1:n
    for j=1:n
        y(i) = y(i) + P(i,j)*x(j);
    end
end