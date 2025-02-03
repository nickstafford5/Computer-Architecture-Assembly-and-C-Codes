/* This program generates an array of number 1-150 in the memory. Then it organizes this array into a stack and uses a subroutine called
“addsubroutine” that calculates the sum of all the elements in this stack. */


.data
.align 4
my_array: .space 600 //create space for the array
sumOfArray: .word 0x0 // create space for the variable in the memory
.text
.global main
.macro memorygenerate point, adr
mov r1, #1 // load 1 into register 1
loop:
cmp r1, \point //compare element in r1 and point parameter
bgt endloop // break out of the loop in r1>point
str r1, [\adr] // store element in r1 at the address in adr
add \adr, #4 // increment adr by 4
add r1, #1 //increment r1 by 1
b loop // bridge to start of the loop
endloop:
.endm
addsubroutine:
mov r0, #1 // load r0 with 1
loop2:
cmp r0, r3 // compare elements in r0 and r3
bge endloop2 // if r0>=r3 bridge to end of the loop
POP {R1} // pop the element at the top of the stack into r1
POP {R2} // pop the next element into r2
add r1, r2 // add both these elements and store in r1
PUSH {R1} /*now r1 hold the sum of all the elements popped from the stack.
push this sum onto the top of the stack*/
add r0, #1 // increment r0 by 1
b loop2 // bridge to start of the loop
endloop2:
bx lr // bridge back to where the subroutine was called in the main
main:
ldr r4, =my_array // load the address of my_array into r4
mov r3, #150 //load 150 into r3
memorygenerate r3, r4 // call memorygenerate and pass r3 and r4 as parameters
mov r5, #0 // load r5 with 0
sub r4, #4 // load r4 with the element in r4 minus 4
loop1:
cmp r5, r3 // compare the elements in r5 and r3
bge endloop1 // break out of the loop if r5>=r3
ldr r6, [r4] // load element in my_array that r4 is pointing to into r6
push {r6} // push this element onto a stack
sub r4, #4 // subtract 4 from r4 and store difference in r4
add r5, #1 // increment r5 by 1
b loop1 // bridge to start of the loop
endloop1:
bl addsubroutine /* call addsubroutine. this will add all the elements of the stack we just
created*/
/* once addsubroutine is finished running, the sum of all the elements in my_array is the only
element left in the stack. The sp is pointing at this element*/
ldr r0, [sp] // load the sum of the stack sp is pointing to into r0
ldr r1, =sumOfArray // load the address of sumOfArray in the memory into r1
str r0, [r1] // store the sum of all the elements of the stack at the address in r1.
// now sumOfArray is holding the sum of all the elements of my_array
stop: nop // terminate program
b stop 
