'''
 * New BSD License
 * ---------------
 *
 * Copyright © 2019 Wei Du (ddwwzzyy@gmail.com) All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 * * Neither the name of Wei Du nor the names of its contributors may be used to
 *   endorse or promote products derived from this software without specific
 * prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS “AS IS”
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
'''
'''
    Loading the map and visualizing expands and solutions
    the command line arguments should be <*.map> <*.cfg> <envdebug.txt>(optional) <sol.txt>(optional)
'''

import sys
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.image as mpimg

argList = sys.argv
numFile = len(argList)
 
''' parsing maps '''
fMap = open(argList[1],'r')
# # filter out heads
mapContent = fMap.readline()
mapContent = fMap.readline()
mapContent = fMap.readline()
mapContent = fMap.readline()

mapArr=[]
for line in fMap:
    tmpLine = list(line.strip())
    # '@', 'O', 'T' are obstacles
    for p, char in enumerate(tmpLine):
        if char == '@' or char == 'O' or char == 'T':
            tmpLine[p] = 1
        else:
            tmpLine[p] = 0
    mapArr.append(tmpLine)
fMap.close()
plt.imshow(mapArr,cmap='binary')

# plt.savefig('rlt.eps',bbox_inches = 'tight', dpi=1000)
plt.show()
