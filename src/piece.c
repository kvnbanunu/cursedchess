#include "../include/piece.h"
#include <string.h>

void init_models(model_t models[N_PTYPE])
{
    model_t temp[N_PTYPE] = {
        {0, 1,  1,  1,  1,  1,  'K'}, // King
        {9, 16, 16, 16, 16, 16, 'Q'}, // Queen
        {5, 16, 16, 16, 0,  0,  'R'}, // Rook
        {3, 0,  0,  0,  16, 16, 'B'}, // Bishop
        {3, 2,  2,  2,  0,  0,  'N'}, // Knight
        {1, 1,  0,  0,  1,  0,  'p'}  // Pawn
    };
    memcpy(models, temp, sizeof(model_t) * N_PTYPE);
}
