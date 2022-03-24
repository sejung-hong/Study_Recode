import java.util.*;

public class 신고결과받기 {
    static class Solution {
        public static int[] solution(String[] id_list, String[] report, int k) {
            int[] answer = new int[id_list.length];
            HashMap<String, List<String>> hashmap = new HashMap<>();
            HashMap<String, Integer> report_id = new HashMap<>();
            for(int i=0; i< id_list.length; i++){
                List<String> l = new LinkedList<>();
                hashmap.put(id_list[i], l);
            }
            for(int i=0; i< report.length; i++) {
                String[] s = report[i].split(" ");
                if(hashmap.get(s[0]).contains(s[1]) == false){
                    hashmap.get(s[0]).add(s[1]);
                    if(report_id.containsKey(s[1]) == false){
                        report_id.put(s[1], 1);
                    }else {
                        report_id.put(s[1], report_id.get(s[1]) + 1);
                    }
                }

            }

            for(int i=0; i< id_list.length; i++){
                Integer num = 0;
                for(String s : hashmap.get(id_list[i])){
                    if(report_id.get(s) >= k){
                        num++;
                    }
                }
                answer[i] = num;
            }

            return answer;
        }
        public static void main(String[] args){
            String[] id_list = {"muzi", "frodo", "apeach", "neo"};
            String[] report = {"muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"};
            int k = 2;
            solution(id_list, report,k);
        }
    }

}
