#include "../include/piece.h"

static model_t models[N_PTYPE] = {
    {0, 0, 1, 1, 1, 1, 1, 'K'},
    {9, 0, 16, 16, 16, 16, 16, 'Q'},
    {5, 0, 16, 16, 16, 0, 0, 'R'},
    {3, 0, 0, 0, 0, 16, 16, 'B'},
    {3, 1, 2, 2, 2, 0, 0, 'N'},
    {1, 1, 1, 0, 0, 1, 0, 'p'}
};

model_t *get_model(ptype_t type)
{
    return &models[type];
}
