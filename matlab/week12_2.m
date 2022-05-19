x = 'ACGTTGCAGTTCCATATG';
y = '';

for k = 1:length(x)
    if strcmp(x(k),'A')
        y(k) = 'T';
    elseif strcmp(x(k),'T')
        y(k) = 'A';
    elseif strcmp(x(k),'C')
        y(k) = 'G';
    else 
        y(k) = 'C';
    end
end

fprintf("%s\n", x);
fprintf("%s\n", y);