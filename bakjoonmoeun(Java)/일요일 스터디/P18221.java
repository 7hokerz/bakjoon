//package main;

import java.io.*;
import java.util.*;

public class P18221 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int N = Integer.parseInt(br.readLine());
        int a = 0, b = 0, c = 0, d = 0;
        int [][] arr = new int[N+1][N+1];

        for(int i = 1;i<N+1;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 1;j<N+1;j++){
                arr[i][j] = Integer.parseInt(st.nextToken());
                if(arr[i][j] == 2){a = i; b = j;}
                if(arr[i][j] == 5){c = i; d = j;}
            }
        }
        
        int mx = Math.max(b,d), my = Math.max(a,c);
        int nx = Math.min(b,d), ny = Math.min(a,c);
        
        int distx = Math.abs(mx - nx);
        int disty = Math.abs(my - ny);
        int dist = disty * disty + distx * distx; 
        
        if(Math.sqrt(dist) < 5) {System.out.print(0); return;}

        int person = 0;

        for(int i = ny;i<my+1;i++){
            for(int j = nx;j<mx+1;j++){
                if(arr[i][j] == 1) person++;
            }
        }

        if(person < 3) System.out.print(0);
        else System.out.print(1);
        
        br.close();
    }
}
/*
 System.out.println(N);
        for(int i = 1;i<N+1;i++){
            for(int j = 1;j<N+1;j++){
                System.out.print(arr[i][j] + " ");
            }System.out.println();
        }
 */