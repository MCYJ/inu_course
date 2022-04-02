% 1) 
% a=1, b=1일 경우, P1,P2,P3중 가장 2PI와 가까운 수식은 무엇인가?
% a,b선언
a=1.0;
b=1.0;
% h선언
h = ((a-b)/(a+b))^2;

P1 = pi*(a+b)*(64-3*(h^2))/(64-16*h);
P2 = pi*(a+b)*(1+3*h/(10+sqrt(4-3*h)));
P3 = pi*sqrt(2*(a^2+b^2)-((a-b)^2)/2);

P1_err = abs(P1-2*pi);
P2_err = abs(P2-2*pi);
P3_err = abs(P3-2*pi);

fprintf("1) a=1,b=1의 경우 원의 둘레 계산\n");
fprintf("P1 : %12.6f\nP2 : %12.6f\nP3 : %12.6f\n", P1, P2, P3);
fprintf("모두 같은 값으로 계산됨\n");
fprintf("오차의 절댓값\n");
fprintf("P1_err : %12.6f\nP2_err : %12.6f\nP3_err : %12.6f\n", P1_err, P2_err, P3_err);
% 2)
% a=1, b=0.1인 경우 P1,P2,P3의 수식으로 타원의 둘레의 길이 근사화
% a,b선언
a=1;
b=0.1;
% h선언
h = ((a-b)/(a+b))^2;

P1 = pi*(a+b)*(64-3*(h^2))/(64-16*h);
P2 = pi*(a+b)*(1+3*h/(10+sqrt(4-3*h)));
P3 = pi*sqrt(2*(a^2+b^2)-((a-b)^2)/2);

P1_err = abs(P1-2*pi);
P2_err = abs(P2-2*pi);
P3_err = abs(P3-2*pi);

fprintf("2) a=1,b=0.1의 경우 원의 둘레 계산\n");
fprintf("P1 : %12.6f\nP2 : %12.6f\nP3 : %12.6f\n", P1, P2, P3);

