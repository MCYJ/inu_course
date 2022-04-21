count = 0;
i = 0;
% random walk를 100회 반복
while i<100
    % n : 타일크기
    n=5;
    % hop counter
    k=0;
    % 현재의 위치 초기화
    xc=0;
    yc=0;
    % x와 y의 좌표가 테두리에 다다르지 않는 경우
    while abs(xc) < n && abs(yc) < n 
       % 균일분포난수활용
       r=rand();
       if r <= 0.25
           yc = yc+1;
       elseif 0.25 < r && r <= 0.5
           xc = xc+1;
       elseif 0.5 < r && r <= 0.75
           yc = yc-1;
       else
           xc = xc-1;
       end
       % hop counter 증가
       k=k+1;
       %fprintf("k : %d x : %d y : %d\n", k, xc, yc);
    end
    count = count + k;
    i = i + 1;
end
fprintf("%f\n", count/100);
