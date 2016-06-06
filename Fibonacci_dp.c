/*
 * Fibonacci_dp.c
 *
 *  Created on: 2016��5��27��
 *      Author: hadex
 */
int fib(int x){
	if(x<=2)
		return 1;

	return fib(x-1) + fib(x-2);
}


int buf[1000];
int fib_dp(int x){
	/*����Ѿ����������ˣ���ôֱ�ӷ��ؾͿ�����*/
	if(buf[x]!=0)
		return buf[x];
	/*����Ļ�����F(X)�������浽buf*/
	else{
		if(x<=2){
			buf[x] = 1;
		}else{
			buf[x] = fib_dp(x-1) + fib_dp(x-2);
		}
	}

	return buf[x];
}
