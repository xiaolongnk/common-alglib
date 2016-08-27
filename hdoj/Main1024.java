import java.util.Scanner;

public class Main
{
       private int n;
       private int m;
       private int[] a;
       private int max;
       Main( int n,int m )
       {
             this.n = n;
             this.m = m;
             this.a = new int[n+1];
             this.max = 0;
       }
       public void setA( int i,int b )
       {
              this.a[i] = b;
       }
       public void prMax()          
       {
              System.out.println( this.max ); 
       }
       public void setMax()
       {
              int[] curr_best = new int[n+1];
              int[] pre_best = new int[n+1];
              
              for( int i=0;i<=n;i++ )
              {
                   curr_best[i] = 0;
                   pre_best[i] = 0;
              }
              int i=0;
              int j=0;
              for( i=1;i<=m;i++ )
              {
                   this.max = -90000000;
                   for( j=i;j<=n;j++ )
                   {
                        curr_best[j] = this.max_two( curr_best[j-1]+a[j],pre_best[j-1]+a[j] );
                        pre_best[j-1] = this.max;
                        if( this.max<curr_best[j] )
                        {
                            this.max = curr_best[j];
                        }
                   }
                   pre_best[j-1] = this.max;
              }
       }
       public int max_two( int a,int b )
       {
              if( a>b )  return a;
              else       return b;
       } 
       public static void main(String[] args)
       {
              int n;
              int m;
              Scanner s = new Scanner(System.in);
              while( s.hasNext() )
              {
                     m = s.nextInt();
                     n = s.nextInt();
                     Main main = new Main( n,m );
                     for( int i=1;i<=n;i++ )
                     {
                          int b = s.nextInt();
                          main.setA( i,b );
                     }
                     main.setMax();
                     main.prMax();
              }
       }
}
