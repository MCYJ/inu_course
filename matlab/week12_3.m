% reverse complement operation
x = 'AGTAGCAT';
y = '';

for k = 1:length(x)
%    y(k) = x(length(x)-k+1);
    if strcmp(x(length(x)-k+1),'A')
        y(k) = 'T';
    elseif strcmp(x(length(x)-k+1),'T')
        y(k) = 'A';
    elseif strcmp(x(length(x)-k+1),'C')
        y(k) = 'G';
    else 
        y(k) = 'C';
    end
end
fprintf("%s\n",y);