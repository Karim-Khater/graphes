#include <stdio.h>
#include "address.h"
int main()
{
	address test=0x8F85;
	printf("%d\n",test );
	address of = a_offset(test);
	printf("%d\n", of);
	printf("%d\n", a_block(test));
	printf("%d\n",a_index(test));
	printf("%d\n",a_tag(test));
	printf("%d\n", a_full_from_bl(test,of));

	return 0;
}