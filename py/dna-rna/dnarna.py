import os

clear = lambda: os.system('cls')
user_input = ""

amino = {
    'UUU' : 'fenyloalanina',
    'UCU' : 'seryna',	
    'UAU' : 'tyrozyna',
    'UGU' : 'cysteina',
    
    'UUC' : 'fenyloalanina',
    'UCC' : 'seryna',
    'UAC' : 'tyrozyna',	
    'UGC' : 'cysteina',

    'UUA' : 'leucyna',
    'UCA' : 'seryna',
    'UAA' : 'Ochre (Stop)',	
    'UGA' : 'Opal (Stop)',

    'UUG' : 'leucyna',
    'UCG' : 'seryna',
    'UAG' : 'Amber (Stop)',
    'UGG' : 'tryptofan',
#4324324324324324324324234234324234234234234
    'CUU' : 'leucyna',
    'CCU' : 'prolina',
    'CAU' : 'histydyna',
    'CGU' : 'arginina',

    'CUC' : 'leucyna',
    'CCC' : 'prolina',
    'CAC' : 'histydyna',
    'CGC' : 'arginina',

    'CUA' : 'leucyna',
    'CCA' : 'prolina',
    'CAA' : 'glutamina', 
    'CGA' : 'arginina',

    'CUG' : 'leucyna',
    'CCG' : 'prolina'	,
    'CAG' : 'glutamina',
    'CGG' : 'arginina',
#34324324321434314132432141341241324132413413414
    'AUU' : 'izoleucyna',
    'ACU' : 'treonina',
	'AAU' : 'asparagina',
    'AGU' : 'seryna',

    'AUC' : 'izoleucyna',
    'ACC' : 'treonina',
    'AAC' : 'asparagina',
    'AGC' : 'seryna',

    'AUA' : 'izoleucyna',
    'ACA' : 'treonina',
    'AAA' : 'lizyna',
    'AGA' : 'arginina',

    'AUG' : 'metionina (Start)',
    'ACG' : 'treonina',
    'AAG' : 'lizyna',
    'AGG' : 'arginina',
#343124324343124234245345345345435435345435435345
    'GUU' : 'walina',
    'GCU' : 'alanina',
    'GAU' : 'asparaginian',
    'GGU' : 'glicyna',

    'GUC' : 'walina',
    'GCC' : 'alanina',
    'GAC' : 'asparaginian',
    'GGC' : 'glicyna',

    'GUA' : 'walina',
    'GCA' : 'alanina',
    'GAA' : 'glutaminian',
    'GGA' : 'glicyna',

    'GUG' : 'walina',
    'GCG' : 'alanina',
    'GAG' : 'glutaminian',
    'GGG' : 'glicyna'
}

clear()

def dna2RNA(dna):
    rna = ""
    for d in dna:
        if d == 'A': d = 'U'
        elif d == 'C': d = 'G'
        elif d == 'T': d = 'A'
        elif d == 'G': d = 'C'
        rna += d
    print("Komplementarna Sekwencja RNA: " + rna)

    rna = rna.split(' ')
    for r in rna:
        print(amino[r] + ' ')
    

while user_input != "exit":
    user_input = str(input("Podaj sekwencję odcinka DNA: "))
    dna2RNA(user_input)
    print()
