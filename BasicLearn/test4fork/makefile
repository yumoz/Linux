.PHONY:all

all:test rn show gcd

test:test.c 
	arm-linux-gcc test.c -o test

rn:rn.c 
	arm-linux-gcc rn.c -o rn

gcd:gcd.c
	arm-linux-gcc gcd.c -o gcd

show:show.c
	arm-linux-gcc show.c -o show

.PHONY:clean

clean:
	rm -f test rn gcd show


