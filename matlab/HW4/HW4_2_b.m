% seed를 0으로 초기화
rand('seed',0);
% 문제에서 제시한 5가지 n의 크기를 벡터로 생성
nList = [5,10,15,20,25];

fprintf("  n    네 개의 완전 코너      기본 edge 타일 \n");
fprintf("------------------------------------------------\n");
% for문을 통해 vector(iterater형)에 들어있는 n을 하나씩 사용
for n = nList
    % hopping 초기화 : 움직일때마다 증가
    hop = 0;
    % meetCenter 초기화 : center(0,0)를 도착했을 때 증가
    meetCenter = 0;
    meetEdge = 0;
    meetCorner = 0;
    for k=1:1000
        % 현재 위치 초기화
        xc = 0;
        yc = 0;
        while abs(xc) < n && abs(yc) < n
            r = rand;
            % 12.5%확률로 북쪽 방향으로 1이동
            if r <= 0.125
                yc=yc+1;
            % 12.5%확률로 동쪽 방향으로 1이동
            elseif 0.125 < r && r <= 0.250
                xc=xc+1;
            % 12.5%확률로 남쪽 방향으로 1이동
            elseif 0.250 < r && r <= 0.375
                yc=yc-1;
            % 12.5%확률로 서쪽 방향으로 1이동
            elseif 0.375 < r && r <= 0.500
                xc=xc-1;
            % 12.5%확률로 북동쪽 방향으로 1이동
            elseif 0.500 < r && r <= 0.625
                xc=xc+1;
                yc=yc+1;
            % 12.5%확률로 북서쪽 방향으로 1이동
            elseif 0.625 < r && r <= 0.750
                xc=xc-1;
                yc=yc+1;
            % 12.5%확률로 남동쪽 방향으로 1이동
            elseif 0.750 < r && r <= 0.875
                xc=xc+1;
                yc=yc-1;
            % 12.5%확률로 남서쪽 방향으로 1이동
            else
                xc=xc-1;
                yc=yc-1;
            end
            % 이동횟수 증가
            hop=hop+1;
            if xc == 0 && yc == 0
                meetCenter=meetCenter+1;
            end
        end

        % 단순히 edge인지, 완전한 네 개의 코너에 도달했는지 판단 후, 각각의 변수에 누적
        if (abs(xc) == n && abs(yc) == n)
            meetCorner=meetCorner+1;
        else
            meetEdge=meetEdge+1;
        end
    end
    % 1000번 시뮬레이션의 평균값을 구하기 위해 1000으로 나눔
    fprintf("%2d%20f%20f\n",n, meetCorner, meetEdge);
end

