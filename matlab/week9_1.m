% 몇각형인지
n = input('number of polygon edge: ');
% smoothing 횟수
nsmooth = input('number of smoothings: ');

% Polygon의 (x,y) 좌표정의
% 균일분포 난수를 (n,1) 형태로 생성
x = rand(n,1);
y = rand(n,1);

figure;
% 1행 2열로 나눔
subplot(1,2,1);

% forward param 3 : edge / backward param 3 : point
% 'or' = 빨간색 동그라미 마커
% [x;x(1)] [y;y(1)] => 마지막 점과 첫번째 점을 잇기위해
plot([x;x(1)], [y;y(1)], 'k', x, y, 'or');

for k=1:nsmooth
    subplot(1,2,2);
    [x,y] = Smooth(x,y);
    plot([x;x(1)], [y;y(1)], 'k', x, y, 'or');
    
    % we hide the axes and use the axis option 'tight' to keep the displayed
    % polyons roughly same size
    % 축 없애고, 같은 크기로 유지되도록 range 조절
    axis tight off;
    title(sprintf('After %d Smoothings', k), 'FontWeight','bold','FontSize',14);
    
    % 
    pause(.1);
end


