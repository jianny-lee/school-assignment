package practice;

public class Example6 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		byte byteValue1=10;
		byte byteValue2=20;
		
		int intValue1=byteValue1+byteValue2;
		System.out.println(intValue1);
		
		char charValue1='A';
		char charValue2=1;
		
		int intValue2=charValue1+charValue2;
		System.out.println("유니코드: "+intValue2);
		System.out.println("출력문자: "+(char)intValue2);
		
		int intValue3=10;
		int intValue4=intValue3/4;
		System.out.println(intValue4);

	}

}
