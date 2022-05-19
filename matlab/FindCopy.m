function k = FindCopy(S, T)
k = 0;
for i = 1:length(T)-length(S)+1
    if strcmp(S,T(i:i+length(S)-1))
        k = i;
    end
end
