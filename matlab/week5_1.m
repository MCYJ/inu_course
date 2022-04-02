% 그림창 초기화
close all
figure
axis equal off
hold on

% area 구성
x = [0 3 3 0];
y = [0 0 1 1];
v = [0 1 1];
n = 100;

hold on;

for k=0:n
    f = k/n;
    fill(x, y+k, [f, 1-f, 1]);
end