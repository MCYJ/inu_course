//  [4] 단계 메소드가 다른 클래스에 있을 때
class Num_Method    // 추가함 
{                  // 추가함
    public static string abc(int a, int b)    // public 추가해 줌
    {
        string r_value = "";
        if (a < b)
        {
            r_value = "너무 커요";
        }
        else if (a > b)
        {
            r_value = "너무 작어요";
        }
        else if (a == b)
        {
            r_value = "정답요";

        }
        return r_value;
    }  // 리턴값으로 너무 커, 너무작어, 정답  으로 함
}
// //[4] 단계 끝

