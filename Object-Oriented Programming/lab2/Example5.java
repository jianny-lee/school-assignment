package practice;

public class Example5 {
	
	public static void main(String[] args){

		char c1='A';
		int intValue=c1;
		System.out.println(intValue);

		int intValue1=200;
		double doubleValue1=intValue1;
		System.out.println(doubleValue1);

		
		//int->byte 강제 타입 변환
		int var1=10;
		byte var2=(byte)var1;
		System.out.println(var1+" -> "+var2);
	
		//사용을 하지 않는것이 좋음
		int var3=100000;
		byte var4=(byte)var3;
		System.out.println(var3+" -> "+var4);
	}

}
