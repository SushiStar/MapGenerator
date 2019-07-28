/*
 *  BSD 3-Clause License
 *
 *  Copyright (c) 2019, Wei Du
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *
 *  1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 *  2. Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 *  3. Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */

// STL include
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>

// Project include
#include <generator/generator2D.h>

namespace mapgrt {

XYGen::~XYGen() {
    for (auto pRow : gridMap) {
        if (pRow != nullptr) {
            delete pRow;
            pRow = nullptr;
        }
    }
}

// '.' passable
// 'T' unpassable
void XYGen::SetDimension(int mRow_, int mColumn_, int mHight_) {
    mRow = mRow_;
    mColumn = mColumn_;

    gridMap.clear();
    gridMap.resize(mRow);

    for (auto& pRow : gridMap) {
        pRow = new std::vector<char>(mColumn, '.');
    }
}

inline std::pair<int, int> XYGen::RandCoord() {
    return std::make_pair(std::rand() % mRow, std::rand() % mColumn);
}

void XYGen::GenerateMap() {
    int numObs = (int)(mRow * mColumn * dOccRate + 0.5);

    int halfLen = 5;
    for (int i = 0; i < numObs;) {
        auto coords = RandCoord();
        if (gridMap[coords.first]->at(coords.second) == '.') {
            //++i;
            // gridMap[coords.first]->at(coords.second) = 'T';
            i += 25;
            int up = coords.first - halfLen > -1 ? coords.first - halfLen : 0;
            int dn = coords.first + halfLen < mRow ? coords.first + halfLen : mRow-1;
            int lt = coords.second - halfLen > -1 ? coords.second - halfLen : 0;
            int rt = coords.second + halfLen < mColumn ? coords.second + halfLen : mColumn-1;
            for (int j = up; j <= dn; ++j) 
                for (int k = lt; k <= rt; ++k )
                    gridMap[j]->at(k) = 'T';
        } else
            continue;
    }
}

void XYGen::WriteToFile(const std::string& sFName) {
    std::ofstream fOutput(sFName);

    fOutput << "type octile\n";
    fOutput << "height " << mRow << std::endl;
    fOutput << "width " << mColumn << std::endl;
    fOutput << "map\n";
    for (auto& pRow : gridMap) {
        for (int i = 0; i < mColumn; ++i) fOutput << pRow->at(i);
        fOutput << std::endl;
    }

    fOutput.close();
}

}  // namespace mapgrt

