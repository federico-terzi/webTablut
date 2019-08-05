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

    void calculate_available_moves(const int * board, int is_white, int * out_moves, int x, int y) {
        Board b;
        b.load_board(board, is_white);
        
        ArnoldMoveGenerator move_generator;
         
        auto moves {move_generator.generate(b)};
        int current = 0;
        for (auto move : moves) {
            if (move.from.col == x && move.from.row == y) {
                out_moves[current] = move.to.col;
                out_moves[current+1] = move.to.row;
                current += 2;
            }
        }
        out_moves[current] = -1;
    }

    int calculate_board(const int * board, int * out_board, int fx, int fy, int tx, int ty) {
        Board b;
        b.load_board(board, true);
        
        Board new_board {Board::from_board(b, Position{fx, fy}, Position{tx,ty})};
        int current = 0;
        for (int x = 0; x<9; x++) {
            for (int y=0; y<9; y++) {
                if (new_board.has_king(x, y)) {
                    out_board[current] = 3;
                }else if(new_board.has_white(x,y)){
                    out_board[current] = 1;
                }else if(new_board.has_black(x,y)){
                    out_board[current] = 2;
                }else{
                    out_board[current] = 0;
                }
                current++;
            }
        }

        if (new_board.is_white_win()) {
            return 1;
        }else if(new_board.is_black_win()) {
            return 2;
        }else{
            return 0;
        }
    }
}
