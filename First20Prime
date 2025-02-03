// This program computes the first 20 prime numbers and stores them sequentially in an array in the memory

.data
.align 4
Primearray:
.space 80               /* each element takes up 4 bytes so to store 20 elements we must create 80 bytes of space in the memory */
.text
.global main
main: nop

                        // defining each register so that it is easier to keep track of what each register is for
#define cur_num r0      // current number we are testing
#define prime_count r1  /* counting how many prime numbers we have stored into the array*/
#define array r6         /*will hold the address of the first space for the array in the memory */
#define prime r2       //switch to verify that cur_num is a prime or not
#define limit r3       // limit for the number of multiples we must check
LDR array, =Primearray /*load array with the address of the array in the memory*/
MOV cur_num, #3       // load cur_num with the first number we will test: 3
MOV prime_count, #0   //Initialize prime_count with 0
for1:
CMP prime_count, #20 // compare prime_count and 20
BGE endfor1         // if prime_count>=20 break out of for1 loop
MOV prime, #1       // load 1 into the prime switch
MOV limit, cur_num // load cur_num into limit
MOV r4, #0         // load 0 into r4
                  /*r4 will temporarily store the quotient of dividing limit by 2*/
divlim:           //this is a loop that will divide limit by 2
CMP limit, #2     // compare limit and 2
BLT enddivlim     // if limit is less than 2 bridge to enddivlim
SUB limit, limit, #2   /* subtract 2 from limit and store difference in limit*/
ADD r4, r4, #1   //increment r4 by 1
b divlim         // bridge back to divlim
enddivlim:
MOV limit, r4       //load r4 into limit. limit now holds cur_num/2
MOV r5, limit       //load limit into r5 (temp store for limit)
MOV r4, #2         // load 2 into r4 which will be a counter
for2:
CMP r4, r5         // compare r4 and r5
BGE endfor2       // bridge to endfor2 if r4>=r5
MOV r7, cur_num       // load cur_num into r7
modnum:     /* this will give us the remainder after dividing i by j*/
CMP r7, r4 //compare r7 and r4
BLT endmodnum /* if r7<r4 bridge to endmodnum*/
SUB r7, r7 and r4 // r7=r7-r4
b modnum // bridge to modnum
endmodnum:
if1:
CMP r7, #0 // compare r7 and 0
BNE fi1 // bridge to fi1 if r7 is not equal to 0
MOV prime, #0 // load prime with 0
b endfor2
fi1:
ADD r4, r4, #1 // r4=r4+1
b for2
endfor2:
if2:
CMP prime, #1 //compare prime and 1
BNE fi2 //bridge to fi2 if prime is not equal to 1
ADD prime_count, primecount, #1
STR r0, [array] /* store the current number we are testing
in the address in the memory that array holds*/
ADD array, #4
fi2:
ADD cur_num, cur_num, #2 /*now we can test the next odd
number*/
b for1
endfor1:
stop:
nop
b stop
