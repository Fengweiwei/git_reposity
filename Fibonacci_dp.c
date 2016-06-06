/*
 * Fibonacci_dp.c
 *
 *  Created on: 2016年5月27日
 *      Author: hadex
 */
int fib(int x){
	if(x<=2)
		return 1;

	return fib(x-1) + fib(x-2);
}


int buf[1000];
int fib_dp(int x){
	/*如果已经计算出结果了，那么直接返回就可以了*/
	if(buf[x]!=0)
		return buf[x];
	/*否则的话计算F(X)，并保存到buf*/
	else{
		if(x<=2){
			buf[x] = 1;
		}else{
			buf[x] = fib_dp(x-1) + fib_dp(x-2);
		}
	}

	return buf[x];
}
