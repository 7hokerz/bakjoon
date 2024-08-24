//package main;

import java.io.*;
import java.util.*;

public class P1009 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int T = Integer.parseInt(br.readLine());

        while(T-- > 0){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int res = 1;

            for(int i = 1;i<b+1;i++){
                res *= a;
                res %= 10;
            }
            if(res == 0) res = 10;

            bw.write(String.valueOf(res)+'\n');
        }
        bw.flush();
        bw.close();
    }
}