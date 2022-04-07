% k의 값이 얼마나 올라가면 1 + 1/2^k는 1과 같은 것으로 인식할까?
k=0;
while (1+1/2^k) > 1
    k = k + 1;
end

% k의 값은 53이 된다.
% IEEE floating point standard에서는 mantisa를 최대 52bits로 설정되어있기 때문

fprintf("%d\n", k);

