% seed를 0으로 초기화
randn('seed',0);

% 허근 갯수를 저장한 변수선언
img = 0;

% 1000번의 실험반복
for k=1:1000
    % 평균이 0이고, 표준편차는 0.4인 표준정규분포 난수생성
    a = 0.4*randn;
    b = 0.4*randn;
    c = 0.4*randn;
    
    % 판별식을 활용하여 만들어진 식의 허근여부를 확인
    d = b^2-4*a*c;
    
    if d < 0
        img=img+1;
    end
end
% 허근의 갯수 출력
fprintf("%d\n",img);
