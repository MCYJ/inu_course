function alfa = Overlapping(R1, R2)
R1_top = (R2.top >= R1.top) && (R1.top > R2.bot);
R1_bot = (R2.top > R1.bot) && (R1.bot >= R2.bot);
R1_left = (R2.left <= R1.left) && (R1.left < R2.right);
R1_right = (R2.left < R1.right) && (R1.right <= R2.right);
alfa = (R1_top || R1_bot) && (R1_left || R1_right);