fid = fopen('iris.csv', 'r');

A = textscan(fid, '%d %f %f %f %f %s','HeaderLines',1,'Delimiter',',');

labels = A{1,6};
pie(categorical(A{1,6}));

fclose(fid);