fid = fopen('iris.csv', 'r');

A = textscan(fid, '%d %f %f %f %f %s','HeaderLines',1,'Delimiter',',');

fprintf("%d \n", length(find((A{1,2} >= 4.2) & (A{1,2} <= 6.2) & (A{1,5} >= 1.3) & (A{1,5} <= 2.0))));

fclose(fid);