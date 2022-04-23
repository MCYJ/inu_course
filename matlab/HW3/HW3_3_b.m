% 시뮬레이션의 N번 반복
N = 10000;

% 선분의 길이가 1보다 큰 경우를 누적
count = 0;

for k=1:N
    x1 = 2*rand-1;
    y1 = 2*rand-1;
    while sqrt(x1^2+y1^2) > 1
        x1 = 2*rand-1;
        y1 = 2*rand-1;
    end

    x2 = 2*rand-1;
    y2 = 2*rand-1;
    while sqrt(x2^2+y2^2) > 1
        x2 = 2*rand-1;
        y2 = 2*rand-1;
    end

    if sqrt((x1-x2)^2+(y1+y2)^2) > 1
        count = count + 1;
        %fprintf("%d %f\n", count, sqrt((x1-x2)^2+(y1+y2)^2));
    end
end
fprintf("확률: %f\n", (count/N)*100);