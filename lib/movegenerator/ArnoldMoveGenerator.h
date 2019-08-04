//
// Created by freddy on 17/04/19.
//

#ifndef OSARRACINO_ARNOLDMOVEGENERATOR_H
#define OSARRACINO_ARNOLDMOVEGENERATOR_H

#include "MoveGenerator.h"

class ArnoldMoveGenerator  : public MoveGenerator<ArnoldMoveGenerator>{
public:
    std::vector<Move> generate(const Board &b) const;

    std::string get_name() const {
        return "ArnoldMoveGenerator";
    }
};


#endif //OSARRACINO_ARNOLDMOVEGENERATOR_H
