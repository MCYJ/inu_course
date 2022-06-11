function alfa = Cont(R1,R2)
R1_in_R2 = (R2.top >= R1.top) && (R2.left <= R1.left) && (R2.bot <= R1.bot) && (R2.right >= R1.right);
R2_in_R1 = (R1.top >= R2.top) && (R1.left <= R2.left) && (R1.bot <= R2.bot) && (R1.right >= R2.right);
alfa = R1_in_R2 || R2_in_R1;