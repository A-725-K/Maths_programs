from z3 import *
import sys
from string import ascii_lowercase

if ( len(sys.argv) != 3 ):
    print "Usage: python magic_square.py <dimension> <magic_number>"
    quit()

dim = int( sys.argv[1] )  #dimension of the magic square
magicN = int( sys.argv[2] ) #the magic sum

mySolver = Solver()

lst = []

#initialize lst with one variable each entry of the magic square
arg = ''
c = 1
for i in range(0, dim):
    for j in range(0, dim):
        arg += ( 'a' + str(i) + str(j) )
        if ( c != dim*dim ):
            arg += ' '
        c += 1

lst = Ints(arg)

#added some rules to the solver
for i in lst:
    mySolver.add( i > 0 )   #each number must be greater than 0
    #mySolver.add( i <= dim*dim )   #each value must be less than the number of boxes in the square (optional)
                                
mySolver.add( Distinct(lst) )   #each number must be different from the others

#diagonals
sum_diag_1 = 0
sum_diag_2 = 0

i = 0
j = dim-1
while i < len(lst):
    sum_diag_1 += lst[i]
    sum_diag_2 += lst[j]
    
    i += (dim+1)
    j += (dim-1)
   
mySolver.add( sum_diag_1 == magicN )
mySolver.add( sum_diag_2 == magicN )

#rows
sum_row = 0

i = 0
while i < len(lst):
    for j in range(0, dim):
        sum_row += lst[i + j]
    mySolver.add( sum_row == magicN )
    sum_row = 0
    i += dim

#columns
sum_col = 0

for i in range(0, dim):
    j = 0
    while j < len(lst):
        sum_col += lst[i + j]
        j += dim
    mySolver.add( sum_col == magicN )
    sum_col = 0
    j += 1

#check if a solution exists
check = mySolver.check()

print "The problem is:\t%s\n\n" % check

#if the magic number exists prints the solution
if check == sat:
    m = mySolver.model()
    s = ''
    i = 0
    while i < len(lst):
        for j in range(0, dim):
            sys.stdout.write(str(m[lst[i+j]]) + " ")
        print ""
        i += dim
        s = ''
else:
    print "Sorry, there is no solution:"
    print " _____________"
    print "/             \\"
    print "|  /\     /\  |"
    print "|  \/     \/  |"
    print "|   _______   |"
    print "|  /       \  |"
    print "\_____________/"

