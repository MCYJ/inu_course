tol = 10^(-15);
n = 2;
f_old = 1;
f_cur = 1;
f_new = f_old+f_cur;

r_cur = f_cur/f_old;
r_new = f_new/f_cur;

while abs(r_cur - r_new) > tol
    n=n+1;
    f_old = f_cur;
    f_cur = f_new;
    f_new = f_old + f_cur;

    r_cur = f_cur/f_old;
    r_new = f_new/f_cur; 
end
fprintf("n : %d\n",n);
fprintf("f_cur : %f\n",f_cur);
fprintf("r_new : %f\n",r_new);