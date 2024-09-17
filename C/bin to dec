#include<stdio.h>
#include<string.h>

unsigned long binaryToDecimal(char *binary, int length);
int validate(char *binary, int length);

int main(void)
{
	char binary[65];
	int length;
	unsigned long decimal;
	
	scanf("%64s", binary);
	length = strlen(binary);
	if(validate(binary, length))
	{
		decimal = binaryToDecimal(binary, length);
		printf("%s in binary is %lu in decimal\n", binary, decimal);
	}
	else
	{
		printf("The input should be a binary number, containing only zeros(0) and ones(1).\n");
	}
	
	return 0;
}

unsigned long binaryToDecimal(char *binary, int length)
{
	int i;
	unsigned long decimal = 0;
	unsigned long weight = 1;
	binary += length - 1;
	weight = 1;
	for(i = 0; i < length; ++i, --binary)
	{
		if(*binary == '1')
			decimal += weight;
		weight *= 2;
	}
	
	return decimal;
}

int validate(char *binary, int length)
{
	int i;
	for(i = 0; i < length; ++i, binary++)
	{
		if((*binary != '0') && (*binary != '1'))
			return 0;
	}
	return 1;
}
