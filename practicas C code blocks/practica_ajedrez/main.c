/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { EMPTY, PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING } PieceType;
typedef enum { NONE, WHITE, BLACK } Color;

typedef struct {
    PieceType type;
    Color color;
} Piece;

Piece board[8][8];

void init_board() {
    // Limpiar tablero
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++) {
            board[i][j].type = EMPTY;
            board[i][j].color = NONE;
        }

    // Peones
    for (int i = 0; i < 8; i++) {
        board[1][i] = (Piece){PAWN, BLACK};
        board[6][i] = (Piece){PAWN, WHITE};
    }

    // Otras piezas
    PieceType layout[8] = {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK};
    for (int i = 0; i < 8; i++) {
        board[0][i] = (Piece){layout[i], BLACK};
        board[7][i] = (Piece){layout[i], WHITE};
    }
}

char piece_symbol(Piece p) {
    if (p.color == NONE) return '.';
    char symbols_white[] = {' ', 'P', 'R', 'N', 'B', 'Q', 'K'};
    char symbols_black[] = {' ', 'p', 'r', 'n', 'b', 'q', 'k'};
    return p.color == WHITE ? symbols_white[p.type] : symbols_black[p.type];
}

void print_board() {
    printf("\n  a b c d e f g h\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", 8 - i);
        for (int j = 0; j < 8; j++) {
            printf("%c ", piece_symbol(board[i][j]));
        }
        printf("%d\n", 8 - i);
    }
    printf("  a b c d e f g h\n");
}

int parse_coord(const char *coord, int *row, int *col) {
    if (strlen(coord) != 2) return 0;
    *col = coord[0] - 'a';
    *row = 8 - (coord[1] - '0');
    return (*col >= 0 && *col < 8 && *row >= 0 && *row < 8);
}

void move_piece(int from_row, int from_col, int to_row, int to_col) {
    board[to_row][to_col] = board[from_row][from_col];
    board[from_row][from_col].type = EMPTY;
    board[from_row][from_col].color = NONE;
}

int main() {
    char from[3], to[3];
    int from_row, from_col, to_row, to_col;
    int turn = 0;

    init_board();

    while (1) {
            system("color 2");
        print_board();
        printf("\nTurno de %s\n", (turn % 2 == 0) ? "BLANCAS" : "NEGRAS");

        printf("Mover (ej: e2 e4): ");
        scanf("%2s %2s", from, to);

        if (!parse_coord(from, &from_row, &from_col) || !parse_coord(to, &to_row, &to_col)) {
            printf("Movimiento inválido. Intenta de nuevo.\n");
            continue;
        }

        Piece selected = board[from_row][from_col];

        if (selected.color == NONE || (turn % 2 == 0 && selected.color != WHITE) || (turn % 2 == 1 && selected.color != BLACK)) {
            printf("Movimiento no permitido. Intenta de nuevo.\n");
            continue;
        }

        move_piece(from_row, from_col, to_row, to_col);
        turn++;
    }

    return 0;
}
*/

