package practice;

public class Example4 {
	public static void main(String[] args){
		char c1='A';
		char c2=65;
		char c3='\u0041';
		System.out.println(c1);
		System.out.println(c2);
		System.out.println(c3);
		
		char c4='°¡';
		char c5=44032;
		System.out.println(c4);
		System.out.println(c5);
		
		int unicode=c4;
		System.out.println(unicode);
	}

}
