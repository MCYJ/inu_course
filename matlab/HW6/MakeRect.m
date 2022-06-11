function R = MakeRect(a,b,c,d)
% a and b are real numbers that satisfy a <= b.
% c and d are real numbers that satisfy c <= d.
% R is a rectangle: the set of all (x,y) that satisfy
% R.a <= x <= R.b, R.c <= y <= R.d
R = struct('left',a,'right',b,'bot',c,'top',d);