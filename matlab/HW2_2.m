% M 설정
M = 1000;
% 최적의 p, q를 도출하기 위한 pbest, qbest 초기화
pbest = 1;
qbest = 1;
% 최소의 절대오차를 도출하기 위한 errorbest 초기화
errorbest = abs(pbest/qbest-pi);
fprintf("    p     q     | p/q - pi |\n");
fprintf("------------------------------\n")

for q=1:ceil(M/pi)
    pminus = floor(pi*q);
    pplus = ceil(pi*q);
    % 이전 과정에서 도출된 errorbest보다 이번 pplus와 pminus를 활용하여 계산한 pi가 작은 경우 재할당
    if errorbest > abs(pplus/q - pi) || errorbest > abs(pminus/q - pi)
        % 더 작은 절대오차가 나오는 경우 판단
        if abs(pminus/q - pi) > abs(pplus/q - pi)
            pbest = pplus;
            qbest = q;
            errorbest = abs(pplus/q - pi);
            fprintf("%5d %5d %15.8f\n",pbest,qbest,errorbest);
        else
            pbest = pminus;
            qbest = q;
            errorbest = abs(pminus/q - pi);
            fprintf("%5d %5d %15.8f\n",pbest,qbest,errorbest);
        end 
    end
end
