/*
 * HDOJ 1002  java biginteger
 * 2013-09-20 11:20:45
 * xiaolongnk
 */

import java.util.*;
import java.math.*;
import java.io.*;

public class Main {
	public static void main(String args[]) {
		Scanner cin = new Scanner(System.in);
		BigInteger n,m;
		int cnt=0;
		int T;
		T = cin.nextInt();
		for(int i=0; i<T; i++) {	
			cnt++;
			n = cin.nextBigInteger();
			m = cin.nextBigInteger();
			System.out.println("Case "+cnt+":");
			System.out.println(n.toString()+" + "+m.toString()+" = "+n.add(m).toString());
			if(i<T-1) System.out.println("");
		}
	}
}
