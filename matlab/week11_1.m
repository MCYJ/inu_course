% contour plot : 등고선그리기
clear;
close all;

x = linspace(0,6,50);
y = linspace(0,4,50);

% @function_name : function handle, 함수를 매개변수로 활용
Tvals = fOnGrid(x,y,@T_plate);
contour(x,y,Tvals);
colorbar