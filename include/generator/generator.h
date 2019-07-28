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

#ifndef __MAP_GENERATOR_INTERFACE_H__
#define __MAP_GENERATOR_INTERFACE_H__

#define OCCRATE_UB 0.99
#define OCCRATE_LB 0.001

#include <string>
#include <vector>

namespace mapgrt {


class Generator {
protected:
    double dOccRate;

public:
    
    Generator():dOccRate(OCCRATE_LB){}

    /*
     * Input: the x, y, z dimension user should specify for the map
     *        If the z dimension is 0, 2D map is generated
     * Output: null
     */
    virtual void SetDimension(int mRow_, int mColumn_, int mHeight_) = 0;

    /*
     * Input: the rate of (obstacle space) / (whole space)
     *        this value should be between 0.0 and 1.0
     * Output: null
     */
    inline void setOccupyRate(double rate_) {
        dOccRate = rate_ < OCCRATE_LB ? OCCRATE_LB : rate_;
        dOccRate = rate_ > OCCRATE_UB ? OCCRATE_UB : rate_;
    }

    /*
     * Input: null
     * Output: null
     */
    virtual void GenerateMap() = 0;

    /*
     * Input: target file name;
     * Output: null
     */
    virtual void WriteToFile(const std::string&) = 0;
};

}  // namespace mapgrt

#endif
