R1 = MakeRect(1,4,-2,2);
R2 = MakeRect(5,6,-3,3);

fprintf("%d\n", Overlapping(R1, R2));

hold on

ShowRect(R1, "r");
ShowRect(R2, "b");

hold off