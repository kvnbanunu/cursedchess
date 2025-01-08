#ifndef PIECE_H
#define PIECE_H

#define N_MOV 8
#define N_PTYPE 6
#define N_PIECES_PER_SIDE 16
#define N_PIECES 32
#define N_PAWNS 8

typedef enum PieceType
{
    KING,
    QUEEN,
    ROOK,
    BISHOP,
    KNIGHT,
    PAWN
} ptype_t;

enum Movement
{
    FWD,
    BKWD,
    HORIZ,
    D_FWD,
    D_BKWD,
};

typedef struct Coordinate
{
    int x;
    int y;
} coord_t;

/*
 * Model for each type of game piece
 */
typedef struct Model
{
    int  val;              /* Value of each piece matching official chess rules */
    int  mov_range[N_MOV]; /* Ranges in the order of Movement enum */
    char ch;               /* The character used to represent this piece in ncurses */
} model_t;

/*
 * This is the actual piece in play
 */
typedef struct Piece
{
    int     id;
    ptype_t type;
    coord_t pos;
    int     color;
} piece_t;

void init_models(model_t models[N_PTYPE]);

#endif
