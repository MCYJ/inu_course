% seed를 0으로 초기화
rand('seed',0);
% 문제에서 제시한 5가지 n의 크기를 벡터로 생성
nList = [5,10,15,20,25];

fprintf("  n    Average to Boundary      Average to (0,0)\n");
fprintf("------------------------------------------------\n");
% for문을 통해 vector(iterater형)에 들어있는 n을 하나씩 사용
for n = nList
    % hopping 초기화 : 움직일때마다 증가
    hop = 0;
    % meetCenter 초기화 : center(0,0)를 도착했을 때 증가
    meetCenter = 0;

    for k=1:1000
        % 현재 위치 초기화
        xc = 0;
        yc = 0;
        while abs(xc) < n && abs(yc) < n
            r = rand;
            if r <= 0.25
                yc=yc+1;
            elseif 0.25 < r && r <= 0.5
                xc=xc+1;
            elseif 0.5 < r && r <= 0.75
                yc=yc+1;
            else
                xc=xc-1;
            end
            % 이동횟수 증가
            hop=hop+1;
            if xc == 0 && yc == 0
                meetCenter=meetCenter+1;
            end
          %  fprintf("xc: %d yc: %d\n",xc,yc);
        end
    end
    % 1000번 시뮬레이션의 평균값을 구하기 위해 1000으로 나눔
    fprintf("%2d%20f%20f\n",n, hop/1000, meetCenter/1000);
end

