M = 10000000;
pbest = 1;
qbest = 1;
errorbest = abs(pbest/qbest-pi);
tic
for q=1:ceil(M/pi)
    pminus = floor(pi*q);
    pplus = ceil(pi*q);
    if errorbest > abs(pplus/q - pi)
        pbest = pplus;
        qbest = q;
        errorbest = abs(pplus/q - pi);
    end
    if errorbest > abs(pminus/q - pi)
        pbest = pminus;
        qbest = q;
        errorbest = abs(pminus/q - pi);
    end
end
toc
fprintf("%f\n",pbest/qbest);
fprintf("%d\n",pbest);
fprintf("%d\n",qbest);
fprintf("%f\n",errorbest);