#include<stdio.h>
char *multiply(char *num1, char *num2)
{
int n1 = 4;
int n2 = 4;
if (n1 == 0 || n2 == 0)
return "0";
int result(n1 + n2, 0);
int i_n1 = 0;
int i_n2 = 0;
for (int i=n1-1; i>=0; i--)
{
int carry = 0;
int n1 = num1[i] - '0';
i_n2 = 0;
for (int j=n2-1; j>=0; j--)
{
int n2 = num2[j] - '0';
int sum = n1*n2 + result[i_n1 + i_n2] + carry;
carry = sum/10;
result[i_n1 + i_n2] = sum % 10;
i_n2++;
}
if (carry > 0)
result[i_n1 + i_n2] += carry;
i_n1++;
}
int i = result.size() - 1;
while (i>=0 && result[i] == 0)
i--;
if (i == -1)
return "0";
char s = "";
while (i >= 0)
return s;
}
int main()
{
char *str1 = "1235";
char *str2 = "1714";
printf("%s",multiply(str1, str2));
return 0;
}
