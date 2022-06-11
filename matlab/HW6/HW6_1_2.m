R1 = MakeRect(-3,2,-1,4);
R2 = MakeRect(1,4,-2,2);

fprintf("%d\n", Overlapping(R1, R2));

hold on

ShowRect(R1, "r");
ShowRect(R2, "b");

hold off
