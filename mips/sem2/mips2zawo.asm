.data
	printStartMsg: .asciiz "WYBIERZ CO CHCESZ ZROBIC:\nSzyfrowanie (S)\nDeszyfrowanie (D)\n"
	printKeyMsg: .asciiz "\nWpisz klucz przeksztalcenia: (liczba naturalna z przedzialu [0, 25])\n"
	printPromptForStringMsg: .asciiz "\nWpisz zdanie: \n"
	printAgainMsg: .asciiz "\nCzy chcesz powtorzyc?\nTAK (T)\nNIE (N)\n"
	printResultsMsg: .asciiz "\nWynik: "
	input: .space 50
	normalizedInput: .space 50
	output: .space 50
.text
main:
	li $v0, 4 #print string
	la $a0, printStartMsg
	syscall
	
	li $v0, 12 #read character
	syscall
	move $t1, $v0 #wybor S, D (szyfruj, deszyfruj)
	
	li $v0, 4 #print string
	la $a0, printKeyMsg
	syscall
	
	li $v0, 5 #read integer
	syscall
	move $t5, $v0 #wybor klucza

	li $v0, 4 #print string
	la $a0, printPromptForStringMsg
	syscall
	
	li $v0, 8 #read string
	li $a1, 50 #bedzie rozmiaru 50
	la $a0, input #wczytamy go tutaj
	syscall
	
	la $t4, normalizedInput #loading of the string with all uppercase letters, zarezerwowanie mu w pamieci 50 miejsc po kolei
	la $t0, input
	li $t3, 'A'
	li $t9, 'Z'
	b normalizeLoop
	
#=================== NORMALIZE ===================

normalizeLoop:
	lb $t2, ($t0) #load first byte from ($t0) to $t2
	sle $s0, $t3, $t2 #sprawdzamy czy 'A' <= $t2
	sle $s1, $t2, $t9 #sprawdzamy czy $t2 <= 'Z'
	and $s0, $s1, $s0 #sprawdzamy czy 'A' <= $t2 <= 'Z'
	bnez $s0, addToFinalString #jesli oba warunki spelnione dodajemy literke do finalnego slowa
	b getNextChar #iterate loop
addToFinalString:
	sb $t2, ($t4) #save $t2 into first byte of ($t4)
	add $t4, $t4, 1 #next char on final array
	b getNextChar #iterate loop
getNextChar:
	add $t0, $t0, 1 #next char on input array
	bne $t2, $zero, normalizeLoop #dopoki string istnieje
	sb $zero, ($t4) #ustaw t4 na $zero (0)
	bne $t1, 'D', negate
	b decipher
negate:
	subu $t5, $zero, $t5
	b decipher
	
#=================== DECIPHER ===================
	
decipher:
	la $t4, normalizedInput #wczytaj input
	la $t7, output #wczytaj output
	b decipherLoop
decipherLoop:
	lb $t2, ($t4)
	beq $t2, $zero, endingProgram
	sub $t2, $t2, $t5
	blt $t2, $t3, tooLowCorrection
	bgt $t2, $t9, tooHighCorrection
	b decipherIncrement
tooLowCorrection:
	add $t2, $t2, 26 #jak za malo to dodaj 26 znakow
	b decipherIncrement
tooHighCorrection:
	sub $t2, $t2, 26 #jak za duzo to odejmij 26 znakow
	b decipherIncrement
decipherIncrement:
	sb $t2, ($t7) #save $t2 into first byte of ($t7)
	add $t4, $t4, 1 #increment input array by 1
	add $t7, $t7, 1 #increment output array by 1
	b decipherLoop
	
#=================== END PROGRAM ===================
	
endingProgram:
	sb $zero,($t7)
	li $v0, 4 #print string
	la $a0, printResultsMsg
	syscall
	
	li $v0, 4 #print string wynikowy
	la $a0, output
	syscall
	
	li $v0, 4 #print string
	la $a0, printAgainMsg
	syscall
	
	li $v0, 12 #read char
	syscall
	move $t5, $v0
	
	beq $t5, 'T', main
	
	li $v0, 10 #end program
	syscall
