.section .data
  entrada:
    .int 7
  
  primo_True:
    .ascii "Numero eh primo"

  finalT:
    .equ primo_True_Tam, finalT - primo_True 

  primo_False:
    .ascii "numero nao eh primo"
    
  finalF:
    .equ primo_False_Tam, finalF - primo_False


.section .text
  .globl _start
    _start:      
      call funcao_zerar

      mov entrada, %eax #EAX receber os valor de entrada
      mov entrada, %ebx #EBX recebe o valor de entrada
      mov entrada, %ecx #ECX recebe o valor de entrada
      jmp repeticao      #saldo

    repeticao: //isso rotulo
      cmp $0, %ecx   #comparando 0 com valor de ecx
      je valida      #vai direto para a dalida se ECX = 0
      xor %edx, %edx #zerando resto da divisao (EDX)
      div %ecx       #EAX/ECX | EAX = coeficiente | EDX = resto da divisao
      cmp $0, %edx   #compra resto da divisao(EDX) com zero
      je contar      #vai direto para contar se EDX = 0
      dec %ecx      
      mov %ebx,%eax  #copia o valor de EBX e joga em EAX 
      jne repeticao  #vai direto para 
 
    contar:
       inc %rdi       #0 + 1 = 1 (RDI ++) para impilhar
       dec %ecx       #ECX- 6 
       mov %ebx,%eax  #copia valor de EBX e joga em EAX | EAX = 7
       cmp $0, %ecx   #comparacao
       push %rdi      #empilhar 
       je valida
       jmp repeticao  #vai para REPETIR

    valida:
      pop %rdi                      #desempilhar
      cmp $2, %rdi
      je imprimir_primo_verdadeiro
      jmp imprimir_primo_falso

    imprimir_primo_verdadeiro:
      movl $4, %eax
      movl $1, %ebx
      movl $primo_True, %ecx
      movl $primo_True_Tam, %edx
      int $0x80
      jmp fim

    imprimir_primo_falso:
      movl $4, %eax
      movl $1, %ebx
      movl $primo_False, %ecx
      movl $primo_False_Tam, %edx
      int $0x80
      jmp fim

    funcao_zerar:
    #ZERANDO CADA RESTISTADOR
      xor %rax, %rax
      xor %rbx, %rbx
      xor %rcx, %rcx
      xor %rdx, %rdx 
      xor %rdi, %rdi 
      ret

    fim:
      movl $0, %ebx 
      movl $1, %eax
      int $0x80
