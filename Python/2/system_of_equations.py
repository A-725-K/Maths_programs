from z3 import *

mySolver = Solver();

iv = IntVector('x', 4)

#with 4 equations ---> 1 sol
#with 3 equations ---> inf sol
mySolver.add( iv[1] + 2*iv[2] - iv[3] == 1 )
mySolver.add( iv[0] + iv[2] + iv[3] == 4 )
mySolver.add( -iv[0] + iv[1] - iv[3] == 4 )
mySolver.add( 7*iv[1] + 3*iv[2] - iv[3] == 4 )

i = 1
while mySolver.check() == sat:
    m = mySolver.model()
    print "***"
    print i
    print "***"
    i += 1
    print m
    mySolver.add(Or(iv[0] != m[iv[0]], iv[1] != m[iv[1]], iv[2] != m[iv[2]], iv[3] != m[iv[3]]))
