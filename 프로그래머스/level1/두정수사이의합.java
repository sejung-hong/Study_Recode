class 두정수사이의합 {
    public static long solution(int a, int b) {
        long answer = 0;
        for(int i = Math.min(a,b); i<=Math.max(a,b); i++){
            answer += i;
        }
        return answer;
    }

    public static void main(String[] args) {
        int a = 3;
        int b = 5;
        System.out.println(solution(a, b));
    }
}

