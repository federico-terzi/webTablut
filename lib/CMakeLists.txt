add_executable(osarracino
        model/Board.cpp model/Board.h
        evaluator/Evaluator.h
        model/Position.cpp model/Position.h
        evaluator/TorettoWhiteEvaluator.cpp evaluator/TorettoWhiteEvaluator.h
        evaluator/BlackEvaluator.cpp evaluator/BlackEvaluator.h
        movegenerator/MoveGenerator.h
        util/BitUtils.h util/BoardUtils.cpp util/BoardUtils.h
        movegenerator/ArnoldMoveGenerator.cpp movegenerator/ArnoldMoveGenerator.h
        search/SearchEngine.h search/RamboSearchEngine.h util/Timer.h
        web/WebInterface.cpp)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
#set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
#set(CMAKE_CXX_FLAGS_RELEASE "-O3 -march=native")

target_include_directories (osarracino PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(osarracino PROPERTIES LINK_FLAGS "-s WASM=1 -s BINARYEN_METHOD='native-wasm' -s EXPORTED_FUNCTIONS='[_calculate_board, _calculate_move, _get_fx, _get_fy, _get_tx, _get_ty, _calculate_available_moves]' -s EXTRA_EXPORTED_RUNTIME_METHODS='[\"ccall\", \"cwrap\"]'")
