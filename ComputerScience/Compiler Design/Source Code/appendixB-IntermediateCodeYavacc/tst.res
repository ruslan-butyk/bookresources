Reading from file tst.c . . .
1.......
Name	Type	Sub Type	Width

b	21		1		4
c	21		1		4
a	21		1		4
Name	Type	Sub Type	Width

Name	Type	Sub Type	Width

f	21		3		8
d	21		3		8
e	21		3		8
b	21		1		4
c	21		1		4
a	21		1		4
z	21		2		4
y	21		2		4
x	21		2		4
Program parsed successfully.
\nElements in vector:
 	=	10	 	a


 	=	20	 	b


 	=	30	 	c


 	++	a	postfix	t1


 	*	b	c	t2


 	+	a	t2	t3


 	+	t3	e	t4


 	/	d	f	t5


 	-	t4	t5	t6


 	=	t6	 	e


L1	<	a	b	t7


 	IFGO	t7	0	L2


 	*	d	f	t8


 	=	t8	 	c


 	*	f	x	t9


 	=	t9	 	e


 	>	x	y	t10


 	IFGO	t10	0	L3


 	=	10	 	x


 	GOTO	 	 	L4


L3	=	20	 	y


L4	GOTO	 	 	L1


L2	+	e	d	t11


 	=	t11	 	a

