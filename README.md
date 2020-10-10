# Push swap

### About
Push Swap is the project of ***School 42***. The aim is to sort data on stack, with the limited set of instructions, using the lowest possible number of actions.
At this project we must produce two programms, `checker` and `push_swap`. Also, you may get acquainted with the algorithm used in that program [here](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a).

The instruction set that can be used is defined bellow.

### Grade


***Score 98/100***

```
Mandatory part 86/100

Bonus part 10/25
```

# How to install and use #

### Installation:
```
git clone https://github.com/ykrotitel/push_swap.git

cd push_swap

make
```

### Usage:
```
ARG=`ruby -e "puts (1..50).to_a.shuffle.join(' ')"`

./push_swap $ARG | ./checker $ARG
```

# Instruction set

Name	| Instruction			| What do
--------|-----------------------|----------------------------------------------
***sa***	| swap `a`				| swap the fist 2 elements at the top of stack `a`
***sb***	| swap `b`				| swap the fist 2 elements at the top of stack `b`
***ss***	| swap `a` + swap `b`		| ***sa*** and ***sb*** at the same time
***pa***	| push `a`				| take the first element at the top of `b` and put it at the top of `a`
***pb***	| push `b`				| take the first element at the top of `b` and put it at the top of `b`
***ra***	| rotate `a`				|  shift up all elements of stack `a` by 1
***rb***	| rotate `b`				|  shift up all elements of stack `b` by 1
***rr***	| rotate `a` + rotate `b`	| ***ra*** and ***rb*** at the same time
***rra***	| reverse rotate `a`		| shift down all elements of stack `a` by 1
***rrb***	| reverse rotate `b`		| shift down all elements of stack `b` by 1
***rrr***	| reverse rotate `a` + reverse rotate `b`	| ***rra*** and ***rrb*** at the same time
