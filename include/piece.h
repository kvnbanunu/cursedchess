#define INIT_H 8
#define INIT_W 8
#define MAX_H 16
#define MAX_W 16
#define N_MOV 6
#define N_PTYPE 6

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
    DUAL,
    FWD,
    BKWD,
    HORIZ,
    D_FWD,
    D_BKWD
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
    int     val;              /* Value of each piece matching official chess rules */
    int     mov_range[N_MOV]; /* Ranges in the order of Movement enum */
    char    ch;               /* The character used to represent this piece in ncurses */
} model_t;

/*
 * This is the actual piece in play
 */
typedef struct Piece
{
    ptype_t type;
    coord_t pos;
} piece_t;

model_t *get_model(ptype_t type);
