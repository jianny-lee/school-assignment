//1615051 �̿���
package automata;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Automata {
	public static int makeKey(int a, int b, int c) {
		return a * c + b;
	}

	public static void main(String[] args) {

		//HashMap�� ruleMap�̶�� ���ο� ��ü�� �����Ѵ�.
		HashMap<String, ArrayList<String>> ruleMap = new HashMap<String, ArrayList<String>>();
		System.out.println("Production Rule�� ������ �Է��Ͻÿ�.");
		
		Scanner scan = new Scanner(System.in);//scan�̶�� Scanner�� ���ο� ��ü�� �����Ѵ�.
		int size = scan.nextInt();//size�� ������ �Է¹޴´�.

		scan.nextLine();//��ü scan�� ���ڿ� ��ü�� �Է¹޴´�.

		System.out.println("Production Rule�� �Է��Ͻÿ�.");
		for (int i = 0; i < size; i++) {//i�� �Է��� ������ ������ �� ����
			String str = scan.nextLine();//string str�� ���ڿ� ��ü�� �Է��Ѵ�.
			String[] strArr = str.split(">");//�Է��� ���ڿ��� ">"�� ������ �̰��� �������� split�� �Ͽ� �и��Ѵ�.
			if (!ruleMap.containsKey(strArr[1])) {// rulemap�� strArr[1]�� key��
													// �ִ��� value�� �ִ��� Ȯ��
				ArrayList<String> vars = new ArrayList<String>();//ArrayList�� vars�� ��ü�� ����
				vars.add(strArr[0]);// ������ ���� ���Ѵ�.
				ruleMap.put(strArr[1], vars);// ruleMap�� strArr[1](key),vars(value)�� �ִ´�.
			} else {
				ruleMap.get(strArr[1]).add(strArr[0]);
			}
		}

		//parseVarMap�̶�¶� �ٸ�  HashMap�� ��ü ����
		HashMap<Integer, ArrayList<String>> parseVarMap = new HashMap<Integer, ArrayList<String>>();

		System.out.println("���ڿ� w�� �Է��Ͻÿ�.");
		String w = scan.nextLine();//string w�� ���ڿ� ��ü�� �Է��Ѵ�.
		for (int len = 1; len <= w.length(); len++) {
			for (int i = 1, j = len; j <= w.length(); i++, j++) {
				int newkey = i * w.length() + j;//parseVarMap�� ���� ���ο� key
				ArrayList<String> newVars = new ArrayList<String>();
				if (i == j) {
					String findkey = w.substring(i - 1, i);//�ɺ� ����
					ArrayList<String> ruleVar = ruleMap.get(findkey); //�ɺ��� ���� �ִ� ���� ã��
					if (ruleVar != null && !ruleVar.isEmpty()) {
						for (String var : ruleVar) { //ruleVar�� �迭�� �ִ� var�� ������
							newVars.add(var); //newVars�� ��ü�� var�� ���Ѵ�
						}

					}
					parseVarMap.put(newkey, newVars); //newKey�� newVars�� hashMap�� parseVarMap�� �ִ´�
				} else {
					for (int k = i; k < j; k++) {
						Integer key1 = makeKey(i, k, w.length());
						Integer key2 = makeKey(k + 1, j, w.length());
						for (String var1 : parseVarMap.get(key1)) { //parseVarMap���� ������ key1�� �ش��ϴ� �����͸� var1���� ��ȯ�Ѵ�.
							for (String var2 : parseVarMap.get(key2)) {//parseVarMap���� ������ key2�� �ش��ϴ� �����͸� var2���� ��ȯ�Ѵ�.
								String findkey = var1 + var2; //��ȯ�� var1�� var2�� ���Ͽ� findkey�� ����
								ArrayList<String> ruleVar = ruleMap.get(findkey); //findkey�� �ش��ϴ� �����͸� ArrayList�� ��ȯ�Ѵ�.
								if (ruleVar != null && !ruleVar.isEmpty()) {
									for (String var : ruleVar) { //ruleVar�� �迭�� �ִ� var�� ������
										if (!newVars.contains(var)) //���� newVars�� var�� ���� �ʴٸ�
											newVars.add(var); //var�� newVars�� �ִ´�.
									}
								}
							}
						}

					}
					parseVarMap.put(newkey, newVars); //newkey�� newVars�� ������ ���ο� �����͸� �߰��Ѵ�.
				}
			}
		}
		int lastkey = 1 * w.length() + w.length();

		System.out.print("��� : ");
		if (parseVarMap.get(lastkey).contains("S")) {
			System.out.println("Accept");
		} else {
			System.out.println("Reject");
		}

	}
}
