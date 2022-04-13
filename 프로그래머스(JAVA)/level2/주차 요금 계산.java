import java.util.*;

class Solution {
    public int bTime, bFee, uTime, uFee;
    
    public int time(String in, String out){
        int t = 0;
        String[] iSplit = in.split(":");
        String[] oSplit = out.split(":");
        t = (Integer.parseInt(oSplit[0])- Integer.parseInt(iSplit[0]))* 60 + (Integer.parseInt(oSplit[1])- Integer.parseInt(iSplit[1]));
        
        return t;
    }
    
    public int fee(int t){
        int f = bFee;
        
        if(bTime < t){
            f += ((t-bTime)/uTime)*uFee;
            if((t-bTime)%uTime!=0){
                f += uFee;
            }
        }
        System.out.println("fee : " + f);
        return f;
    }
    
    public int[] solution(int[] fees, String[] records) {
        int[] answer = {};
        bTime = fees[0]; bFee = fees[1]; uTime = fees[2]; uFee = fees[3];
        
        HashMap<String, String> In = new HashMap<>();
        Map<String, Integer> mapTime = new TreeMap<>();
        for(int i=0; i<records.length; i++){
            String[] ss = records[i].split(" ");
            if(ss[2].equals("IN")){
                In.put(ss[1], ss[0]);
            }
            else{
                mapTime.put(ss[1], mapTime.getOrDefault(ss[1], 0) + time(In.get(ss[1]), ss[0]));
                In.remove(ss[1]); //제거
            }
            
        }
        
        for(HashMap.Entry<String, String> e : In.entrySet()){
            mapTime.put(e.getKey(), mapTime.getOrDefault(e.getKey(), 0) + time(e.getValue(), "23:59"));
        }
        
        answer = new int[mapTime.size()];
        
        int i = 0;
        for(Map.Entry<String, Integer> e : mapTime.entrySet()){
            System.out.println(e.getValue());
            answer[i] = fee(e.getValue());
            i++;
        }
        
        return answer;
    }
    
}