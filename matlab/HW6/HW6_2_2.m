R1 = MakeRect(-2,1,-1,4);
R2 = MakeRect(-3,1,-3,4);

fprintf("%d\n", Cont(R1, R2));

hold on
ShowRect(R2, "b");
ShowRect(R1, "r");
hold off