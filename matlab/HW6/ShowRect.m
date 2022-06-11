function ShowRect(R,s)
% R is a rectangle
% s is one of the characters ’k’,’w’,’r’,’g’,’b’,’m’,’c’,’y’
% Displays R in the current figure window using the color s
% Assumes hold is on
fill([R.left R.right R.right R.left],...
[R.bot R.bot R.top R.top],s)
plot([R.left R.right R.right R.left],...
[R.bot R.bot R.top R.top],'k','Linewidth',2)