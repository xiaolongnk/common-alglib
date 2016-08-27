/*
 *
 * catlan number BigInteger;
 * xiaolongnk
 * 2013-10-24 17:51:36
 *
 */

import java.util.*;
import java.math.*;
import java.io.*;

public class Main{
	
	public static BigInteger get(int n){
		BigInteger s=BigInteger.valueOf(n);
		return s;
	}

	public static BigInteger comb (int n, int m){
		BigInteger s= new BigInteger("1");
		
		for(int i=0,j=1;i<m; i++){
			s=s.multiply(get(n-i));
			for( ;j<=m && (s.mod(get(j)).equals(new BigInteger("0"))); j++){
				s=s.divide(get(j));
			}
		
		}
		return s;
	}

	public static void main(String args[]) {
		Scanner cin = new Scanner(System.in);
		int n;
		while(cin.hasNext()){
			n=cin.nextInt();	// get n;
			BigInteger up=new BigInteger("0");
			up=comb(2*n,n);
			up = up.divide(get(n+1));
			System.out.println(up.toString());
		}
	}
}
