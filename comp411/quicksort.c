#include <stdio.h>

int data[] = {
 46,78,19,16,40,86,72,54,1,24,77,97,96,17,45,99,6,77,38,60,
 16,66,65,37,2,91,30,29,53,75,31,47,65,57,65,66,13,64,45,24
};

void quickSort(int* arr, int left, int right) {
  int i = left;
  int j = right;
  int tmp = left + right;
  tmp = tmp / 2;
  int pivot = arr[tmp];
  int *pi, *pj, ai, aj;

  /* partition */
  while (1) {
    if (!(i <= j)) break;
    while (1) {
      pi = arr + i;
      ai = *pi;
      if (!(ai < pivot)) break;
      i++;
    }
    while (1) {
      pj = arr + j;
      aj = *pj;
      if (!(aj > pivot)) break;
      j--;
    }
    if (i <= j) {
      *pi = aj;
      *pj = ai;
      i++;
      j--;
    }
  };

  /* recursion */
  if (left < j) {
    /* you'll need to save arr, i, right, and $ra on the stack
       before making this call and restore them when you get
       back here */
    quickSort(arr, left, j);
  }
  if (i < right) {
    /* this is tail recursion, we can simply tweak the parameters and
     * jump to the top */
    quickSort(arr, i, right);
  }
}

void main() {
  /* 39 below is the length(data) - 1 */
  quickSort(data, 0, 39);

  for(int i=0; i<40; i++) {
    printf("%d %d\n", i, data[i]);
  }
}


quickSort:
       add $t0, $zero, $a1
       add $t1, $zero, $a2
       add $t2, $a1, $a2
       srl $t2, $t2, 1
       sll $t3, $t2, 2
       add $t3, $a0, $t3
       lw $t3, 0($t3)
wh1:
       slt $t4, $t1, $t0
       bne $t4, $zero, endwh1
wh2:
       sll $t9, $t0, 2
       add $t5, $a0, $t9
       lw $t6, 0($t5)
       slt $t4, $t6, $t3
       beq $t4, $zero, wh3
       addi $t0, $t0, 1
       j wh2
wh3:
       sll $t9, $t1, 2
       add $t7, $a0, $t9
       lw $s0, 0($t7)
       slt $t4, $t3,$s0
       beq $t4, $zero, endwh3
       addi $t1, $t1, -1
       j wh3
endwh3:
       slt $t4, $t1, $t0
       bne $t4, $zero, wh1
       sw $s0, 0($t5)
       sw $t6, 0($t7)
       addi $t0, $t0, 1
       addi $t1, $t1, -1
endwh1:
       slt $t4, $a1, $t1
       beq $t4, $zero, nextif
       addi $sp,$sp, -16
       sw $a0, 0($sp)
       sw $t0, 4($sp)
       sw $a2, 8($sp)
       sw $ra, 12($sp)
       add $a2, $t1, $zero
       jal quickSort
       lw $a0, 0($sp)
       lw $t0, 4($sp)
       lw $a2, 8($sp)
       lw $ra, 12($sp)
       addi $sp,$sp, 16
nextif:
       slt $t4, $t0, $a2
       beq $t4, $zero, end
       add $a1, $t0, $zero
       j quickSort
end:
       jr $ra
