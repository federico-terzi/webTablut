#include <string>
#include <model/Board.h>
#include <util/Timer.h>
#include <evaluator/TorettoWhiteEvaluator.h>
#include <evaluator/BlackEvaluator.h>
#include <movegenerator/ArnoldMoveGenerator.h>
#include <search/RamboSearchEngine.h>

extern "C" {
    int fx = -1;
    int fy = -1;
    int tx = -1;
    int ty = -1;

    void calculate_move(const int * board, int is_white, int timeout) {
        Timer timer {Timer(timeout)};

        Board b;
        b.load_board(board, is_white);
        
        RamboSearchEngine engine;
        engine.set_timer(timer);

        BlackEvaluator black_eval;
        TorettoWhiteEvaluator white_eval;
        ArnoldMoveGenerator move_generator;
         
        std::string result;
        if (is_white) {
            engine.make_decision(b, white_eval, move_generator, &fx, &fy, &tx, &ty);
        }else{
            engine.make_decision(b, black_eval, move_generator, &fx, &fy, &tx, &ty);
        }        
            
    }
    
    int get_fx() {
        return fx;
    }   
    int get_fy() {
        return fy;
    }

    int get_tx() {
        return tx;
    }

    int get_ty() {
        return ty;
    }

}
