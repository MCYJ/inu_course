function fVals = fOnGrid(x,y,f)
n = length(x);
m = length(y);
fVals = zeros(m,n);
for j=1:n
    for i=1:m
        % 행렬과 plot의 좌표방식이 달라서 i,j를 서로 교차함
        fVals(i,j) = f(x(j),y(i));
    end
end