package practice;

public class Example5 {
	
	public static void main(String[] args){

		char c1='A';
		int intValue=c1;
		System.out.println(intValue);

		int intValue1=200;
		double doubleValue1=intValue1;
		System.out.println(doubleValue1);

		
		//int->byte ���� Ÿ�� ��ȯ
		int var1=10;
		byte var2=(byte)var1;
		System.out.println(var1+" -> "+var2);
	
		//����� ���� �ʴ°��� ����
		int var3=100000;
		byte var4=(byte)var3;
		System.out.println(var3+" -> "+var4);
	}

}
