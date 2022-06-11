fid = fopen('iris.csv', 'r');

A = textscan(fid, '%d %f %f %f %f %s','HeaderLines',1,'Delimiter',',');

labels = A{1,6};
histogram(A{1,2});
title('Sepal Length')

fclose(fid);