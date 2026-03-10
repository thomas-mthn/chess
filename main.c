#include <stdbool.h>
#include <stdint.h>

#define STD_OUTPUT_HANDLE -11
#define STD_INPUT_HANDLE -10
#define ENABLE_PROCESSED_INPUT 0x0001
#define ENABLE_LINE_INPUT 0x0002
#define ENABLE_ECHO_INPUT 0x0004

#define ENABLE_PROCESSED_OUTPUT 0x0001
#define ENABLE_WRAP_AT_EOL_OUTPUT 0x0002

#define WM_SIZE 0x0005
#define WM_ACTIVATE 0x0006
#define WM_PAINT 0x000F
#define WM_MOUSEACTIVATE 0x0021
#define WM_SETICON 0x0080
#define WM_KEYDOWN 0x0100
#define WM_MOUSEMOVE 0x0200
#define WM_LBUTTONDOWN 0x0201
#define WM_LBUTTONUP 0x0202
#define WM_RBUTTONDOWN 0x0204
#define WM_RBUTTONUP 0x0205
#define WM_MBUTTONDOWN 0x0207
#define WM_PRINT 0x0317
#define WM_CLOSE 0x0010
#define WM_SETREDRAW 0x000B

#define stdcall _stdcall

#define countof(ARRAY) (sizeof(ARRAY) / sizeof((ARRAY)[0]))

#define structure(NAME) typedef struct NAME NAME;struct NAME
#define enumeration(NAME) typedef enum NAME NAME;enum NAME

#define loop for(;;)

#if __GNUC__
#define DLLIMPORT(RETURN) __attribute__((dllimport,stdcall)) RETURN
#else
#define DLLIMPORT(RETURN) _declspec(dllimport) RETURN stdcall
#endif

typedef int8_t   int8;
typedef uint8_t  uint8;
typedef int16_t  int16;
typedef uint16_t uint16;
typedef int32_t  int32;
typedef uint32_t uint32;
typedef int64_t  int64;
typedef uint64_t uint64;

#if _WIN64
typedef unsigned long long Wparam;
typedef long long Lparam;
typedef long long Lresult;
#else
typedef unsigned Wparam;
typedef int Lparam;
typedef int Lresult;
#endif

structure(Point){
    int x;
    int y;
};

structure(Rect){
    int left;
    int top;
    int right;
    int bottom;
};

structure(Msg){
    void* hwnd;
    unsigned message;
    unsigned wParam;
    int lParam;
    unsigned time;
    Point pt;
};

structure(WndClassA){
    unsigned style;
    Lresult (stdcall* wnd_proc)(void*,unsigned,Wparam,Lparam);
    int cls_extra;
    int wnd_extra;
    void* instance;
    void* window_icon;
    void* cursor;
    void* background;
    const char* menu_name;
    const char* class_name;
};

#define FW_NORMAL 400
#define OUT_OUTLINE_PRECIS      8
#define CLIP_DEFAULT_PRECIS    0
#define CLEARTYPE_QUALITY      5
#define VARIABLE_PITCH         2

#define WS_OVERLAPPED   0x00000000L
#define WS_POPUP        0x80000000L
#define WS_CHILD        0x40000000L
#define WS_MINIMIZE     0x20000000L
#define WS_VISIBLE      0x10000000L
#define WS_DISABLED     0x08000000L
#define WS_CLIPSIBLINGS 0x04000000L
#define WS_CLIPCHILDREN 0x02000000L
#define WS_MAXIMIZE     0x01000000L
#define WS_CAPTION      0x00C00000L
#define WS_BORDER       0x00800000L
#define WS_DLGFRAME     0x00400000L
#define WS_VSCROLL      0x00200000L
#define WS_HSCROLL      0x00100000L
#define WS_SYSMENU      0x00080000L
#define WS_THICKFRAME   0x00040000L
#define WS_GROUP        0x00020000L
#define WS_MINIMIZEBOX  0x00020000L
#define WS_TABSTOP      0x00010000L
#define WS_MAXIMIZEBOX  0x00010000L

#define DEFAULT_CHARSET 1

#define FOREGROUND_BLUE  (1 << 0)
#define FOREGROUND_GREEN (1 << 1)
#define FOREGROUND_RED   (1 << 2)

#define TRANSPARENT 1

DLLIMPORT(void) ExitProcess(unsigned exit_code);
DLLIMPORT(void*) CreateFontA(
	int    height,
	int    width,
	int    escapement,
	int    orientation,
	int    weight,
	unsigned  italic,
	unsigned  underline,
	unsigned  strikeout,
	unsigned  char_set,
	unsigned  out_precision,
	unsigned  clip_precision,
	unsigned  quality,
	unsigned  pitch_and_family,
	const char* face_name
);
DLLIMPORT(void*) GetStdHandle(unsigned std_handle);
DLLIMPORT(int) SetConsoleTextAttribute(
	void* console_output,
	short attributes
);
DLLIMPORT(int) WriteConsoleA(
	void* console_output,
	const void* buffer,
	unsigned number_of_chars_to_write,
	unsigned* number_of_chars_written,
	void* reserved
);
DLLIMPORT(int) ReadConsoleA(
	void*  console_input,
	const void* buffer,
	unsigned number_of_chars_to_write,
	unsigned* number_of_chars_written,
	void*  input_control
);
DLLIMPORT(int) FlushConsoleInputBuffer(
	void* console_input
);
DLLIMPORT(int) SetConsoleMode(
	void* console_handle,
	unsigned mode
);
DLLIMPORT(void) Sleep(
	unsigned milli_seconds
);
DLLIMPORT(int) GetLastError();
DLLIMPORT(int) DefWindowProcA(void* wnd,unsigned msg,Wparam wparam,Lparam lparam);
DLLIMPORT(uint16) RegisterClassA(WndClassA *wnd_class);
DLLIMPORT(void*) CreateWindowExA(
    unsigned ex_style,
    const char* class_name,
    const char* window_name,
    int style,
    int x,
    int y,
    int width,
    int height,
    void* wnd_parent,
    void* menu,
    void* instance,
    void* param
);
DLLIMPORT(int) DispatchMessageA(Msg* msg);
DLLIMPORT(unsigned) GetMessageA(
    Msg* msg,
    void*  wnd,
    unsigned msg_filter_min,
    unsigned msg_filter_max
);
DLLIMPORT(int) PeekMessageA(
    Msg* msg,
    void*  wnd,
    unsigned msg_filter_min,
    unsigned msg_filter_max,
    unsigned remove_msg
);
DLLIMPORT(int) TextOutW(
	void*     hdc,
	int     x,
	int     y,
	short* string,
	int     c
);
DLLIMPORT(void*) GetDC(void* window);
DLLIMPORT(void*) CreateFontA(
	int height,
	int width,
	int escapement,
	int orientation,
	int weight,
	unsigned  italic,
	unsigned  uderline,
	unsigned  strikeOut,
	unsigned  char_set,
	unsigned  out_precision,
	unsigned  clip_precision,
	unsigned  quality,
	unsigned  pitch_and_family,
	const char* face_name
);
DLLIMPORT(void*) SelectObject(void* hdc,void* h);
DLLIMPORT(int) ScreenToClient(void* window,Point* point);
DLLIMPORT(int) GetClientRect(void* hWnd,Rect* lpRect);
DLLIMPORT(int) GetCursorPos(Point* point);
DLLIMPORT(int) FillRect(void* dc,const Rect *rect,void* brush);
DLLIMPORT(int) SetBkMode(void* hdc,int mode);
DLLIMPORT(void*) CreateSolidBrush(unsigned color);
DLLIMPORT(int) SetWindowPos(void* window,void* window_insert_after,int x,int y,int cx,int cy,unsigned flags);
DLLIMPORT(int) LockWindowUpdate(void* wnd_lock);
DLLIMPORT(int) SendMessageA(void*  hWnd,unsigned   Msg,unsigned wParam,int lParam);
DLLIMPORT(int) RedrawWindow(void* window,const Rect* proc_update,void* region_update,unsigned flags);
DLLIMPORT(int) MessageBoxA(void* window,const char* text,const char* caption,unsigned type);

#define SCALE (1 << 0)
#define ALPHA_BETA true
#define PLAYER_COLOR WHITE

#define MATE_VALUE 5000

static int tMin(int v1,int v2){
	return v1 < v2 ? v1 : v2;
}

static int tMax(int v1,int v2){
	return v1 > v2 ? v1 : v2;
}

static int tAbs(int v){
	return v < 0 ? -v : v;
}

#include <intrin.h>

static int x86Rdtsc(){
    return __rdtsc();
}

static unsigned tHash(unsigned x){
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
	return x;
}

static unsigned tRnd(){
	return tHash(x86Rdtsc());
}

enumeration(Piece){
	VOID,
	PAWN = 1,
	KNIGHT,
	BISSCHOP,
	ROOK,
	QUEEN,
	KING,
	COLOR_FLAG = 1 << 4
};

structure(Move){
	int source;
	int destination;
	int value;
};

static int move_buffer_ptr;
static Move move_buffer[0x1000];

static int good_move_buffer_ptr;
static Move good_move_buffer[0x1000];
/*
static bool castle_right[4] = {true,true,true,true};

static int board[64] = {
	ROOK,KNIGHT,BISSCHOP,KING,QUEEN,BISSCHOP,KNIGHT,ROOK,
	PAWN,PAWN,PAWN,PAWN,PAWN,PAWN,PAWN,PAWN,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	PAWN | COLOR_FLAG,PAWN | COLOR_FLAG,PAWN | COLOR_FLAG,PAWN | COLOR_FLAG,
	PAWN | COLOR_FLAG,PAWN | COLOR_FLAG,PAWN | COLOR_FLAG,PAWN | COLOR_FLAG,
	ROOK | COLOR_FLAG,KNIGHT | COLOR_FLAG,BISSCHOP | COLOR_FLAG,KING | COLOR_FLAG,
	QUEEN | COLOR_FLAG,BISSCHOP | COLOR_FLAG,KNIGHT | COLOR_FLAG,ROOK | COLOR_FLAG,
};
*/

static bool castle_right[4] = {true,true,true,true};
static int board[64] = {
	ROOK,KNIGHT,BISSCHOP,KING,QUEEN,BISSCHOP,KNIGHT,ROOK,
	PAWN,PAWN,PAWN,PAWN,PAWN,PAWN,PAWN,PAWN,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	ROOK | COLOR_FLAG,0,0,KING | COLOR_FLAG,0,0,0,ROOK | COLOR_FLAG,
};

structure(Coord){
	int x;
	int y;
};

Coord knight_move_table[] = {
	{-2,-1},
	{-2,1},
	{-1,-2},
	{-1,2},
	{1,-2},
	{1,2},
	{2,-1},
	{2,1},
};

Coord king_move_table[] = {
	{-1,-1},
	{-1, 0},
	{-1, 1},
	{0 ,-1},
	{0 , 1},
	{1 ,-1},
	{1 , 0},
	{1,  1},
};

enumeration(Color){
	WHITE,
	BLACK
};

static void addMove(int source,int destination){
	move_buffer[move_buffer_ptr].source = source;
	move_buffer[move_buffer_ptr].destination = destination;
	move_buffer_ptr += 1;
}

static void printNumber(int number){
	int length = 0;
	int length_copy;
	char buffer[0x10];
    bool negative = false;
	int number_copy;

    if(number < 0){
        length++;
        negative = true;
        number = -number;
    }
	number_copy = number;

    if(!number)
        length = 1;
    else{
        while(number_copy){
            number_copy /= 10;
            length++;
        }
    }
	length_copy = length;

    while(length--){
        buffer[length] = number % 10 + '0';
        number /= 10;
    }
    if(negative)
        buffer[0] = '-';
	WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE),buffer,length_copy,0,0);
}

static void printMove(Move move){
	char l1 = (7 - move.source % 8) + 0x61;
	char n1 = move.source / 8 + 0x31;

	char l2 = (7 - move.destination % 8) + 0x61;
	char n2 = move.destination / 8 + 0x31;
	
	WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE),&l1,1,0,0);
	WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE),&n1,1,0,0);
	WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE)," - ",3,0,0);
	WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE),&l2,1,0,0);
	WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE),&n2,1,0,0);
	WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE)," = ",3,0,0);
	printNumber(move.value);
	WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE),"\n",1,0,0);
}

static void printBoard(void){
	for(int i = 0;i < 8;i++){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
		char l = '1' + i;
		WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE),&l,1,0,0);
		WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE)," ",1,0,0);
		for(int j = 0;j < 8;j++){
			if(board[i * 8 + j] == VOID)
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
			else
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),board[i * 8 + j] & COLOR_FLAG ? FOREGROUND_BLUE : FOREGROUND_RED);

			switch(board[i * 8 + j] & ~COLOR_FLAG){
				case VOID:
					WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE),(i ^ j) & 1 ? "." : ",",1,0,0); break;
				case PAWN:
					WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE),"P",1,0,0); break;
				case KNIGHT:
					WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE),"N",1,0,0); break;
				case BISSCHOP:
					WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE),"B",1,0,0); break;
				case ROOK:
					WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE),"R",1,0,0); break;
				case QUEEN:
					WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE),"Q",1,0,0); break;
				case KING:
					WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE),"K",1,0,0); break;
			}
		}
		WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE),"\n",1,0,0);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
	WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE),"\n  ",3,0,0);
	for(int i = 0;i < 8;i++){
		char n = 'h' - i;
		WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE),&n,1,0,0);
	}	
	WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE),"\n",1,0,0);
}

structure(MoveHash){
	uint32 hash;
	int occured;
};

MoveHash move_history_table[0x1000];

static int evaluate_draw;

static void moveHistoryPush(void){
	unsigned hash = 1;
	for(int i = 0;i < countof(board);i++)
		hash = tHash(hash ^ board[i]);
	int index = hash % countof(move_history_table);
	while(move_history_table[index].hash && move_history_table[index].hash != hash){
		index += 1;
		index %= countof(move_history_table);
	}
	move_history_table[index].hash = hash;
	move_history_table[index].occured += 1;

	if(move_history_table[index].occured == 3)
		evaluate_draw += 1;
}

static void moveHistoryPop(void){
	unsigned hash = 1;
	for(int i = 0;i < countof(board);i++)
		hash = tHash(hash ^ board[i]);
	int index = hash % countof(move_history_table);
	while(move_history_table[index].hash && move_history_table[index].hash != hash){
		index += 1;
		index %= countof(move_history_table);
	}
	move_history_table[index].occured -= 1;
	if(move_history_table[index].occured == 2)
		evaluate_draw -= 1;

	if(!move_history_table[index].occured)
		move_history_table[index].hash = 0;
}

static bool moveHistoryAdd(void){
	unsigned hash = 1;
	for(int i = 0;i < countof(board);i++)
		hash = tHash(hash ^ board[i]);
	int index = hash % countof(move_history_table);
	while(move_history_table[index].hash && move_history_table[index].hash != hash){
		index += 1;
		index %= countof(move_history_table);
	}
	move_history_table[index].hash = hash;
	move_history_table[index].occured += 1;

	if(move_history_table[index].occured == 3){
		MessageBoxA(0,"threefold repetition, draw","the end",0);
		return false;
	}
	return true;
}

static int evaluate(void);
static int evaluateRecursive(bool color,int depth,int q_depth,int alpha,int beta);

static int evaluateLine(bool color,Coord position,Coord direction){
	Coord position_copy = position;
	int value = 0;
	loop{
		position.x += direction.x;
		position.y += direction.y;
		if(position.x < 0 || position.x > 7 || position.y < 0 || position.y > 7)
			return value;
		int index = position.x * 8 + position.y;
		if(board[index] != VOID){
			value += 3;
			return value;
		}
		value += 1;
	}
}

static int evaluate(void){
	int value = 0;
	for(int i = 0;i < 8;i++){
		for(int j = 0;j < 8;j++){
			int index = i * 8 + j;
			int add = board[index] & COLOR_FLAG ? -1 : 1;
			bool piece_color = board[index] & COLOR_FLAG;
			switch(board[index] & ~COLOR_FLAG){
				case PAWN:{
					int row_offset = piece_color ? -8 : 8;
					int begin_rank = piece_color ? 6 : 1;
					if(board[index + row_offset] == VOID){
						value += add;
						if(i == begin_rank && board[index + row_offset * 2] == VOID)
							value += add;
					}
					if(j != 0){
						if(board[index + row_offset - 1] != VOID)
							value += add * 3;
					}
					if(j != 7){
						if(board[index + row_offset + 1] != VOID)
							value += add * 3;
					}
					value += 10 * add;
				} break;
				case KNIGHT:{
					for(int c = 0;c < countof(knight_move_table);c++){
						Coord coord = knight_move_table[c];
						if(i + coord.x < 0 || i + coord.x > 7 || j + coord.y < 0 || j + coord.y > 7)
							continue;
						if(board[index + coord.x * 8 + coord.y] != VOID)
							value += add * 3;
						else
							value += add;
					}
					value += 30 * add;
				} break;
				case BISSCHOP:{
					value += evaluateLine(piece_color,(Coord){i,j},(Coord){-1,-1}) * add;
					value += evaluateLine(piece_color,(Coord){i,j},(Coord){-1, 1}) * add;
					value += evaluateLine(piece_color,(Coord){i,j},(Coord){ 1,-1}) * add;
					value += evaluateLine(piece_color,(Coord){i,j},(Coord){ 1, 1}) * add;
					value += 30 * add;
				} break;
				case ROOK:{
					value += evaluateLine(piece_color,(Coord){i,j},(Coord){-1, 0}) * add;
					value += evaluateLine(piece_color,(Coord){i,j},(Coord){ 1, 0}) * add;
					value += evaluateLine(piece_color,(Coord){i,j},(Coord){ 0,-1}) * add;
					value += evaluateLine(piece_color,(Coord){i,j},(Coord){ 0, 1}) * add;
					value += 50 * add;
				} break;
				case QUEEN:{
					value += evaluateLine(piece_color,(Coord){i,j},(Coord){-1,-1}) * add;
					value += evaluateLine(piece_color,(Coord){i,j},(Coord){-1, 1}) * add;
					value += evaluateLine(piece_color,(Coord){i,j},(Coord){ 1,-1}) * add;
					value += evaluateLine(piece_color,(Coord){i,j},(Coord){ 1, 1}) * add;
					value += evaluateLine(piece_color,(Coord){i,j},(Coord){-1, 0}) * add;
					value += evaluateLine(piece_color,(Coord){i,j},(Coord){ 1, 0}) * add;
					value += evaluateLine(piece_color,(Coord){i,j},(Coord){ 0,-1}) * add;
					value += evaluateLine(piece_color,(Coord){i,j},(Coord){ 0, 1}) * add;
					value += 90 * add;
				} break;
				case KING:{
					for(int c = 0;c < sizeof(king_move_table) / sizeof(Coord);c++){
						Coord coord = king_move_table[c];
						if(i + coord.x < 0 || i + coord.x > 7 || j + coord.y < 0 || j + coord.y > 7)
							continue;
						if(board[index + coord.x * 8 + coord.y] == VOID)
							value += add;
						else
							value += add * 3;
					}
					value += 10000 * add;
				} break;
			}
		}
	}
	return -value;
}

static int moveAndEvaluate(bool color,int source,int destination,int current_value,int alpha,int beta,int depth,int q_depth){
	int cache = board[destination];
	board[destination] = board[source];
	board[source] = VOID;

	moveHistoryPush();
		
	if(evaluate_draw){
		moveHistoryPop();
		board[source] = board[destination];
		board[destination] = cache;
		return 0;
	}

	int value;
	
	value = color == WHITE ? -evaluate() : evaluate();
	if(tAbs(value) > MATE_VALUE){
		if(value * color > 0)
			value -= depth * 500;
		else
			value += depth * 500;
	}
	else if(depth == 0){
		if(tAbs(tAbs(current_value) - tAbs(value)) > 50)
			value = -evaluateRecursive(color ^ true,0,q_depth + 1,-beta,-alpha);
	}
	else{
		value = -evaluateRecursive(color ^ true,depth - 1,q_depth,-beta,-alpha);
	}
	moveHistoryPop();
	board[source] = board[destination];
	board[destination] = cache;

	return value;
}

static int castleAndEvaluate(bool color,int source,int destination,int current_value,int alpha,int beta,int depth,int q_depth){
	int cache = board[destination];
	board[destination] = board[source];
	board[source] = VOID;

	moveHistoryPush();
		
	if(evaluate_draw){
		moveHistoryPop();
		board[source] = board[destination];
		board[destination] = cache;
		return 0;
	}

	int value;
	
	value = color == WHITE ? -evaluate() : evaluate();
	if(tAbs(value) > MATE_VALUE){
		if(value * color > 0)
			value -= depth * 500;
		else
			value += depth * 500;
	}
	else if(depth == 0){
		if(tAbs(tAbs(current_value) - tAbs(value)) > 50)
			value = -evaluateRecursive(color ^ true,0,q_depth + 1,-beta,-alpha);
	}
	else{
		value = -evaluateRecursive(color ^ true,depth - 1,q_depth,-beta,-alpha);
	}
	moveHistoryPop();
	board[source] = board[destination];
	board[destination] = cache;

	return value;
}

static int evaluateRecursiveLine(bool color,Coord position,Coord direction,int current_value,int* value,int* alpha,int* beta,int depth,int q_depth){
	Coord position_copy = position;
	int source_index = position.x * 8 + position.y;
	loop{
		position.x += direction.x;
		position.y += direction.y;
		if(position.x < 0 || position.x > 7 || position.y < 0 || position.y > 7)
			return true;
		int index = position.x * 8 + position.y;
		if(board[index] != VOID){
			if(!!(board[index] & COLOR_FLAG) != color){
				int value_n = moveAndEvaluate(color,source_index,index,current_value,*alpha,*beta,depth,q_depth);
				*value = tMax(*value,value_n);
				if(ALPHA_BETA){
					*alpha = tMax(*value,*alpha);
					if(*alpha >= *beta)
						return false;
				}
			}
			return true;
		}
		int value_n = moveAndEvaluate(color,source_index,index,current_value,*alpha,*beta,depth,q_depth);
		*value = tMax(*value,value_n);
		if(ALPHA_BETA){
			*alpha = tMax(*value,*alpha);
			if(*alpha >= *beta)
				return false;
		}
	}
}

static bool evaluateRecursivePromotion(bool color,int current_value,int index,int row_offset,int* value,int* alpha,int* beta,int depth,int q_depth){
	int cache_src = board[index];
	int cache_dst = board[index + row_offset];
	board[index] = VOID;
	board[index + row_offset] = QUEEN | cache_src & COLOR_FLAG;

	int value_n;
	if(depth == 0){
		value_n = color == WHITE ? evaluate() : -evaluate();
		if(!q_depth && tAbs(tAbs(current_value) - tAbs(*value)) > 50)
			*value = -evaluateRecursive(color ^ true,0,-*beta,-*alpha,q_depth + 1);
	}
	else{
		value_n = -evaluateRecursive(color ^ true,depth - 1,-*beta,-*alpha,q_depth);
	}
	*value = tMax(*value,value_n);

	board[index] = cache_src;
	board[index + row_offset] = cache_dst;

	if(ALPHA_BETA){
		*alpha = tMax(*value,*alpha);
		if(*alpha >= *beta)
			return false;
	}
	return true;
}

static int evaluateRecursive(bool color,int depth,int q_depth,int alpha,int beta){
	int current_value = evaluate();

	int value = -999999;

	for(int i = 0;i < 8;i++){
		for(int j = 0;j < 8;j++){
			int index = i * 8 + j;
			int add = board[index] & COLOR_FLAG ? -1 : 1;
			if(!!(board[index] & COLOR_FLAG) != color)
				continue;
			switch(board[index] & ~COLOR_FLAG){
				case PAWN:{
					int row_offset = board[index] & COLOR_FLAG ? -8 : 8;
					int begin_rank = board[index] & COLOR_FLAG ?  6 : 1;
					int end_rank   = board[index] & COLOR_FLAG ?  1 : 6;
					if(board[index + row_offset] == VOID){
						if(i == end_rank){
							evaluateRecursivePromotion(color,current_value,index,row_offset,&value,&alpha,&beta,depth,q_depth);
						}
						else{
							int value_n = moveAndEvaluate(color,index,index + row_offset,current_value,alpha,beta,depth,q_depth);
							value = tMax(value,value_n);
							if(ALPHA_BETA){
								alpha = tMax(alpha,value);
								if(alpha >= beta)
									return value;
							}
							if(i == begin_rank && board[index + row_offset * 2] == VOID){
								int value_n = moveAndEvaluate(color,index,index + row_offset * 2,current_value,alpha,beta,depth,q_depth);
								value = tMax(value,value_n);
								if(ALPHA_BETA){
									alpha = tMax(alpha,value);
									if(alpha >= beta)
										return value;
								}
							}
						}
					}
					if(j != 0){
						if(board[index + row_offset - 1] != VOID && !!(board[index + row_offset - 1] & COLOR_FLAG) != color){
							if(i == end_rank){
								evaluateRecursivePromotion(color,current_value,index,row_offset - 1,&value,&alpha,&beta,depth,q_depth);
							}
							else{
								int value_n = moveAndEvaluate(color,index,index + row_offset - 1,current_value,alpha,beta,depth,q_depth);
								value = tMax(value,value_n);
								if(ALPHA_BETA){
									alpha = tMax(alpha,value);
									if(alpha >= beta)
										return value;
								}
							}
						}
					}
					if(j != 7){
						if(board[index + row_offset + 1] != VOID && !!(board[index + row_offset + 1] & COLOR_FLAG) != color){
							if(i == end_rank){
								evaluateRecursivePromotion(color,current_value,index,row_offset + 1,&value,&alpha,&beta,depth,q_depth);
							}
							else{
								int value_n = moveAndEvaluate(color,index,index + row_offset + 1,current_value,alpha,beta,depth,q_depth);
								value = tMax(value,value_n);
								if(ALPHA_BETA){
									alpha = tMax(alpha,value);
									if(alpha >= beta)
										return value;
								}
							}
						}
					}
				} break;
				case KNIGHT:{
					for(int c = 0;c < countof(knight_move_table);c++){
						Coord coord = knight_move_table[c];
						if(i + coord.x < 0 || i + coord.x > 7 || j + coord.y < 0 || j + coord.y > 7)
							continue;

						if(board[index + coord.x * 8 + coord.y] == VOID || !!(board[index + coord.x * 8 + coord.y] & COLOR_FLAG) != color){
							int value_n = moveAndEvaluate(color,index,index + coord.x * 8 + coord.y,current_value,alpha,beta,depth,q_depth);
							value = tMax(value,value_n);
							if(ALPHA_BETA){
								alpha = tMax(alpha,value);
								if(alpha >= beta)
									return value;
							}
						}
					}
				} break;
				case BISSCHOP:{
					Coord table[] = {{-1,-1},{-1,1},{1,-1},{1,1}};
					for(int d = 0;d < countof(table);d++){
						int v = evaluateRecursiveLine(color,(Coord){i,j},table[d],current_value,&value,&alpha,&beta,depth,q_depth);
						if(!v)
							return value;
					}
				} break;
				case ROOK:{
					Coord table[] = {{-1,0},{1, 0},{0,-1},{0, 1}};
					for(int d = 0;d < countof(table);d++){
						int v = evaluateRecursiveLine(color,(Coord){i,j},table[d],current_value,&value,&alpha,&beta,depth,q_depth);
						if(!v)
							return value;
					}
				} break;
				case QUEEN:{
					Coord table[] = {{-1,-1},{-1, 1},{ 1,-1},{ 1, 1},{-1,0},{1, 0},{0,-1},{0, 1}};
					for(int d = 0;d < countof(table);d++){
						int v = evaluateRecursiveLine(color,(Coord){i,j},table[d],current_value,&value,&alpha,&beta,depth,q_depth);
						if(!v)
							return value;
					}
				} break;
				case KING:{
					for(int c = 0;c < countof(king_move_table);c++){
						Coord coord = king_move_table[c];
						if(i + coord.x < 0 || i + coord.x > 7 || j + coord.y < 0 || j + coord.y > 7)
							continue;
						if(board[index + coord.x * 8 + coord.y] == VOID || !!(board[index + coord.x * 8 + coord.y] & COLOR_FLAG) != color){
							int value_n = moveAndEvaluate(color,index,index + coord.x * 8 + coord.y,current_value,alpha,beta,depth,q_depth);
							value = tMax(value,value_n);
							if(ALPHA_BETA){
								alpha = tMax(alpha,value);
								if(alpha >= beta)
									return value;
							}
						}
						int castle_offset = color == WHITE ? 0 : 7 * 8;
						if(castle_right[color * 2 + 0] && board[castle_offset + 1] == VOID && board[castle_offset + 2] == VOID){
							int value_n = castleAndEvaluate(color,index,index + coord.x * 8 + coord.y,current_value,alpha,beta,depth,q_depth);
							value = tMax(value,value_n);
							if(ALPHA_BETA){
								alpha = tMax(alpha,value);
								if(alpha >= beta)
									return value;
							}
						}
						if(castle_right[color * 2 + 1] && board[castle_offset + 4] == VOID && board[castle_offset + 5] == VOID && board[castle_offset + 6] == VOID){
							int value_n = castleAndEvaluate(color,index,index + coord.x * 8 + coord.y,current_value,alpha,beta,depth,q_depth);
							value = tMax(value,value_n);
							if(ALPHA_BETA){
								alpha = tMax(alpha,value);
								if(alpha >= beta)
									return value;
							}
						}
					}
				} break;
			}
		}
	}
	return value;
}

static void line(bool color,Coord position,Coord direction){
	Coord position_copy = position;
	loop{
		position.x += direction.x;
		position.y += direction.y;
		if(position.x < 0 || position.x > 7 || position.y < 0 || position.y > 7)
			return;
		int index = position.x * 8 + position.y;
		if(board[index] != VOID){
			if(!!(board[index] & COLOR_FLAG) != color)
				addMove(position_copy.x * 8 + position_copy.y,index);
			return;
		}
		addMove(position_copy.x * 8 + position_copy.y,index);
	}
}

#define BEST_MOVE true

#define DIFFICULTY -50

static Move bestMove(void){
	int max_value = -999999;
	for(int i = 0;i < move_buffer_ptr;i++){
		if(move_buffer[i].value > max_value)
			max_value = move_buffer[i].value;
		printMove(move_buffer[i]);
	}
	good_move_buffer_ptr = 0;
	for(int i = 0;i < move_buffer_ptr;i++){
		if(move_buffer[i].value == max_value)
			good_move_buffer[good_move_buffer_ptr++] = move_buffer[i];
	}
	int s = tRnd() % good_move_buffer_ptr;
	return good_move_buffer[s];
}

static void move(bool color){
	move_buffer_ptr = 0;
	int begin_rank = color == WHITE ? 1 : 6;
	int row_offset = color == WHITE ? 8 : -8;
	for(int i = 0;i < 8;i++){
		for(int j = 0;j < 8;j++){
			int index = i * 8 + j;
			if(!!(board[index] & COLOR_FLAG) != color)
				continue;
			switch(board[index] & ~COLOR_FLAG){
				case PAWN:{
					if(board[index + row_offset] == VOID){
						addMove(index,index + row_offset);
						if(i == begin_rank && board[index + row_offset * 2] == VOID)
							addMove(index,index + row_offset * 2);
					}
					if(j != 0){
						if(board[index + row_offset - 1] != VOID && !!(board[index + row_offset - 1] & COLOR_FLAG) != color)
							addMove(index,index + row_offset - 1);
					}
					if(j != 7){
						if(board[index + row_offset + 1] != VOID && !!(board[index + row_offset + 1] & COLOR_FLAG) != color)
							addMove(index,index + row_offset + 1);
					}
				} break;
				case KNIGHT:{
					for(int c = 0;c < sizeof(knight_move_table) / sizeof(Coord);c++){
						Coord coord = knight_move_table[c];
						if(i + coord.x < 0 || i + coord.x > 7 || j + coord.y < 0 || j + coord.y > 7)
							continue;
						if(board[index + coord.x * 8 + coord.y] == VOID || !!(board[index + coord.x * 8 + coord.y] & COLOR_FLAG) != color)
							addMove(index,index + coord.x * 8 + coord.y);
					}
				} break;
				case BISSCHOP:{
					line(color,(Coord){i,j},(Coord){-1,-1});
					line(color,(Coord){i,j},(Coord){-1, 1});
					line(color,(Coord){i,j},(Coord){ 1,-1});
					line(color,(Coord){i,j},(Coord){ 1, 1});
				} break;
				case ROOK:{
					line(color,(Coord){i,j},(Coord){-1, 0});
					line(color,(Coord){i,j},(Coord){ 1, 0});
					line(color,(Coord){i,j},(Coord){ 0,-1});
					line(color,(Coord){i,j},(Coord){ 0, 1});
				} break;
				case QUEEN:{
					line(color,(Coord){i,j},(Coord){-1,-1});
					line(color,(Coord){i,j},(Coord){-1, 1});
					line(color,(Coord){i,j},(Coord){ 1,-1});
					line(color,(Coord){i,j},(Coord){ 1, 1});
					line(color,(Coord){i,j},(Coord){-1, 0});
					line(color,(Coord){i,j},(Coord){ 1, 0});
					line(color,(Coord){i,j},(Coord){ 0,-1});
					line(color,(Coord){i,j},(Coord){ 0, 1});
				} break;
				case KING:{
					for(int c = 0;c < countof(king_move_table);c++){
						Coord coord = king_move_table[c];
						if(i + coord.x < 0 || i + coord.x > 7 || j + coord.y < 0 || j + coord.y > 7)
							continue;
						if(board[index + coord.x * 8 + coord.y] == VOID || !!(board[index + coord.x * 8 + coord.y] & COLOR_FLAG) != color)
							addMove(index,index + coord.x * 8 + coord.y);
					}
					int castle_offset = color == WHITE ? 0 : 7 * 8;
					if(castle_right[color * 2 + 0] && board[castle_offset + 1] == VOID && board[castle_offset + 2] == VOID)
						addMove(index,index - 2);
					if(castle_right[color * 2 + 1] && board[castle_offset + 4] == VOID && board[castle_offset + 5] == VOID && board[castle_offset + 6] == VOID)
						addMove(index,index + 2);
				} break;
			}
		}
	}
	if(!move_buffer_ptr)
		return;
	const int DEPTH = 3;

	int time = x86Rdtsc();
	for(int i = 0;i < move_buffer_ptr;i++){
		Move* move = &move_buffer[i];
		if((board[move->source] & ~COLOR_FLAG) == PAWN){
			if((board[move->source] & COLOR_FLAG) && move->source < 2 * 8){
				int cache_src = board[move->source];
				int cache_dst = board[move->destination];
				board[move->source] = VOID;
				board[move->destination] = QUEEN | COLOR_FLAG;

				move->value = -evaluateRecursive(color ^ true,DEPTH,0,-999999,999999);

				board[move->source] = cache_src;
				board[move->destination] = cache_dst;
				continue;
			}
			if(!(board[move->source] & COLOR_FLAG) && move->source >= 8 * 6){
				int cache_src = board[move->source];
				int cache_dst = board[move->destination];
				board[move->source] = VOID;
				board[move->destination] = QUEEN;

				move->value = -evaluateRecursive(color ^ true,DEPTH,0,-999999,999999);

				board[move->source] = cache_src;
				board[move->destination] = cache_dst;
				continue;
			}
		}
		if((board[move->source] & ~COLOR_FLAG) == KING){
			if(move->source - move->destination == -2){
				board[move->source + 4] = VOID;
				board[move->source + 1] = ROOK | COLOR_FLAG * color;

				int cache = board[move->destination];
				board[move->destination] = board[move->source];
				board[move->source] = VOID;
				move->value = -evaluateRecursive(color ^ true,DEPTH,0,-999999,999999);
				board[move->source] = board[move->destination];
				board[move->destination] = cache;

				board[move->source + 1] = VOID;
				board[move->source + 4] = ROOK | COLOR_FLAG * color;
				continue;
			}
			if(move->source - move->destination == 2){
				board[move->source - 3] = VOID;
				board[move->source - 1] = ROOK | COLOR_FLAG * color;

				int cache = board[move->destination];
				board[move->destination] = board[move->source];
				board[move->source] = VOID;
				move->value = -evaluateRecursive(color ^ true,DEPTH,0,-999999,999999);
				board[move->source] = board[move->destination];
				board[move->destination] = cache;

				board[move->source - 1] = VOID;
				board[move->source - 3] = ROOK | COLOR_FLAG * color;
				continue;
			}
		}
		int cache = board[move->destination];
		board[move->destination] = board[move->source];
		board[move->source] = VOID;
		move->value = -evaluateRecursive(color ^ true,DEPTH,0,-999999,999999);
		board[move->source] = board[move->destination];
		board[move->destination] = cache;
	}
	WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE),"time: ",6,0,0);
	printNumber(x86Rdtsc() - time);
	WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE),"\n",1,0,0);

	Move selected_move;

	if(BEST_MOVE){
		selected_move = bestMove();
	}
	else{
		bool multiple_choice = false;
		for(int i = 0;i < move_buffer_ptr;i++){
			if(move_buffer[i].value > DIFFICULTY)
				multiple_choice = true;
		}
		if(!multiple_choice){
			selected_move = bestMove();
		}
		else{
			int acc = 0;
			for(int i = 0;i < move_buffer_ptr;i++){
				move_buffer[i].value -= DIFFICULTY;
				if(move_buffer[i].value < 0)
					move_buffer[i].value = 0;
				printMove(move_buffer[i]);
				acc += move_buffer[i].value;
				//move_buffer[i].value *= move_buffer[i].value;
			}
			int s = tRnd() % acc;
			for(int i = 0;i < move_buffer_ptr;i++){
				s -= move_buffer[i].value;
				if(s < 0){
					selected_move = move_buffer[i];
					break;
				}
			}
		}
		WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE),"select: ",8,0,0);
		printNumber(selected_move.value);
		WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE),"\n",1,0,0);
	}
	//WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE),"selected move: ",15,0,0);
	//printMove(selected_move);
	int castle_offset = color == WHITE ? 0 : 7 * 8;
	if((board[selected_move.source] & ~COLOR_FLAG) == PAWN){
		if((board[selected_move.source] & COLOR_FLAG) && selected_move.source < 2 * 8){
			board[selected_move.destination] = QUEEN | COLOR_FLAG * color;
			board[selected_move.source] = VOID;
		}
		else if(!(board[selected_move.source] & COLOR_FLAG) && selected_move.source >= 8 * 6){
			board[selected_move.destination] = QUEEN;
			board[selected_move.source] = VOID;
		}
		else{
			board[selected_move.destination] = board[selected_move.source];
			board[selected_move.source] = VOID;
		}
	}
	else if((board[selected_move.source] & ~COLOR_FLAG) == ROOK){
		if(selected_move.source == castle_offset)
			castle_right[color * 2 + 0] = false;
		if(selected_move.source == castle_offset + 7)
			castle_right[color * 2 + 1] = false;
		board[selected_move.destination] = board[selected_move.source];
		board[selected_move.source] = VOID;
	}
	else if((board[selected_move.source] & ~COLOR_FLAG) == KING){
		if(selected_move.source - selected_move.destination == -2){
			board[selected_move.source + 4] = VOID;
			board[selected_move.source + 1] = ROOK | COLOR_FLAG * color;
		}
		if(selected_move.source - selected_move.destination == 2){
			board[selected_move.source - 3] = VOID;
			board[selected_move.source - 1] = ROOK | COLOR_FLAG * color;
		}
		board[selected_move.destination] = board[selected_move.source];
		board[selected_move.source] = VOID;
		castle_right[color * 2 + 0] = false;
		castle_right[color * 2 + 1] = false;
	}
	else{
		board[selected_move.destination] = board[selected_move.source];
		board[selected_move.source] = VOID;
	}
	if(-evaluateRecursive(!color,0,0,-999999,999999) < -MATE_VALUE)
		MessageBoxA(0,"you won","the end",0);
	//printBoard();
}

static Coord getCursorPosition(void* window){
	Point cur;
	Rect client;
	Coord r;
	GetCursorPos(&cur);
    ScreenToClient(window,&cur);
	GetClientRect(window,&client);
	return (Coord){cur.x,cur.y};
}

enumeration(PieceChar){
	WHITE_KING = 0x2654,
	WHITE_QUEEN,
	WHITE_ROOK,
	WHITE_BISHOP,
	WHITE_KNIGHT,
	WHITE_PAWN,
	BLACK_KING,
	BLACK_QUEEN,
	BLACK_ROOK,
	BLACK_BISHOP,
	BLACK_KNIGHT,
	BLACK_PAWN
};

static int PieceCharTable[] = {
	[KING] = WHITE_KING,
	[QUEEN] = WHITE_QUEEN,
	[ROOK] = WHITE_ROOK,
	[BISSCHOP] = WHITE_BISHOP,
	[KNIGHT] = WHITE_KNIGHT,
	[PAWN] = WHITE_PAWN,
	[COLOR_FLAG | KING] = BLACK_KING,
	[COLOR_FLAG | QUEEN] = BLACK_QUEEN,
	[COLOR_FLAG | ROOK] = BLACK_ROOK,
	[COLOR_FLAG | BISSCHOP] = BLACK_BISHOP,
	[COLOR_FLAG | KNIGHT] = BLACK_KNIGHT,
	[COLOR_FLAG | PAWN] = BLACK_PAWN,
};

static int* piece_hold;

static void* context;

static void* brush_square_light; 
static void* brush_square_dark;
static void* brush_square_coord;

#define BOARD_COORDINATES true

static void drawBoard(void){
	for(int i = 0;i < 8;i++){
		for(int j = 0;j < 8;j++){
			int x = i * 64 / SCALE;
			int y = j * 64 / SCALE;
			FillRect(context,&(Rect){y,x,y + 64 / SCALE,x + 64 / SCALE},(i ^ j) & 1 ? brush_square_dark : brush_square_light);
			if(PLAYER_COLOR == BLACK)
				TextOutW(context,y,x - 0x08 / SCALE,&PieceCharTable[board[i * 8 + j]],1);
			else
				TextOutW(context,y,x - 0x08 / SCALE,&PieceCharTable[board[63 - (i * 8 + j)]],1);
		}
	}
	if(BOARD_COORDINATES){
		for(int i = 0;i < 8;i++){
			int x = i * 64 / SCALE;
			int y = 8 * 64 / SCALE;
			FillRect(context,&(Rect){y,x,y + 64 / SCALE,x + 64 / SCALE},brush_square_coord);
			FillRect(context,&(Rect){x,y,x + 64 / SCALE,y + 64 / SCALE},brush_square_coord);
			TextOutW(context,(x + 0x08) / SCALE,(y - 0x08) / SCALE,&(int16){'A' + i},1);
			TextOutW(context,(y + 0x10) / SCALE,(x - 0x08) / SCALE,&(int16){'8' - i},1);
		}
	}
}

static bool validCheckLine(bool color,Coord end_position,Coord position,Coord direction){
	Coord position_copy = position;
	loop{
		position.x += direction.x;
		position.y += direction.y;
		if(position.x < 0 || position.x > 7 || position.y < 0 || position.y > 7)
			return false;
		int index = position.x * 8 + position.y;
		if(position.x == end_position.x && position.y == end_position.y)
			return true;
		if(board[index] != VOID)
			return false;
	}
}

static bool validCheck(bool color,int index){
	int source = piece_hold - board;
	Coord position = {index / 8,index % 8};
	Coord source_pos =  {source / 8,source % 8};

	int direction = color == WHITE ? 1 : -1;
	int begin_rank = color == WHITE ? 1 : 6;
	int castle_offset = color == WHITE ? 0 : 7 * 8;

	switch(*piece_hold & ~COLOR_FLAG){
		case PAWN:{
			if(source_pos.x == begin_rank){
				if(position.x - source_pos.x == 2 * direction && position.y == source_pos.y && board[(source_pos.x + 1 * direction) * 8 + source_pos.y] == VOID)
					return true;
			}
			if(position.x - source_pos.x != 1 * direction)
				return false;
			int t = board[(position.x + 1 * direction) * 8 + position.y];
			if(position.y == source_pos.y && board[position.x * 8 + position.y] == VOID)
				return true;
			if(tAbs(position.y - source_pos.y) == 1 * direction && !!(board[position.x * 8 + position.y] & COLOR_FLAG) != color)
				return true;
		} break;
		case KNIGHT:{
			for(int c = 0;c < sizeof(knight_move_table) / sizeof(Coord);c++){
				Coord coord = knight_move_table[c];
				if(source_pos.x + coord.x == position.x && source_pos.y + coord.y == position.y)
					return true;
			}
		} break;
		case BISSCHOP:{
			Coord table[] = {{-1,-1},{-1, 1},{ 1,-1},{ 1, 1}};
			for(int d = 0;d < sizeof(table) / sizeof(Coord);d++){
				if(validCheckLine(color,(Coord){index / 8,index % 8},(Coord){source / 8,source % 8},table[d]))
					return true;
			}
		} break;
		case ROOK:{
			Coord table[] = {{-1,0},{1, 0},{0,-1},{0, 1}};
			for(int d = 0;d < sizeof(table) / sizeof(Coord);d++){
				if(validCheckLine(color,(Coord){index / 8,index % 8},(Coord){source / 8,source % 8},table[d]))
					return true;
			}
		} break;
			break;
		case QUEEN:{
			Coord table[] = {{-1,-1},{-1, 1},{ 1,-1},{ 1, 1},{-1,0},{1, 0},{0,-1},{0, 1}};
			for(int d = 0;d < sizeof(table) / sizeof(Coord);d++){
				if(validCheckLine(color,(Coord){index / 8,index % 8},(Coord){source / 8,source % 8},table[d]))
					return true;
			}
		} break;
		case KING:{
			if(position.y == 5 && board[castle_offset + 4] == VOID && board[castle_offset + 6] == VOID)
				return true;
			if(position.y == 1 && board[castle_offset + 2] == VOID)
				return true;
			if(tAbs(position.x - source_pos.x) < 2 && tAbs(position.y - source_pos.y) < 2)
				return true;
			return false;
		} break;
	}
	return false;
}

static Lresult stdcall windowMessageHandler(void* window,unsigned msg,Wparam wparam,Lparam lparam){
	switch(msg){
		case WM_CLOSE:
			ExitProcess(0);
		case WM_LBUTTONDOWN:{
			Coord coord = getCursorPosition(window);
			int index = coord.y / (64 / SCALE) * 8 + coord.x / (64 / SCALE);
			if(PLAYER_COLOR == WHITE)
				index = 63 - index;
			if(index < 64 && index >= 0 && !!(board[index] & COLOR_FLAG) == PLAYER_COLOR)
				piece_hold = &board[index];
		} break;
		case WM_LBUTTONUP:{
			Coord coord = getCursorPosition(window);
			int index = coord.y / (64 / SCALE) * 8 + coord.x / (64 / SCALE);
			if(PLAYER_COLOR == WHITE)
				index = 63 - index;
			if(piece_hold){
				if(validCheck(PLAYER_COLOR,index) && (!!(board[index] & COLOR_FLAG) != PLAYER_COLOR || board[index] == VOID)){
					int source = piece_hold - board;
					Coord position = {index / 8,index % 8};
					Coord source_pos =  {source / 8,source % 8};
					int castle_offset = PLAYER_COLOR == WHITE ? 0 : 7 * 8;

					if((board[source] & ~COLOR_FLAG) == KING && position.y == 5){
						board[castle_offset + 7] = VOID;
						board[castle_offset + 4] = ROOK | COLOR_FLAG * PLAYER_COLOR;
					}
					if((board[source] & ~COLOR_FLAG) == KING && position.y == 1){
						board[castle_offset + 0] = VOID;
						board[castle_offset + 2] = ROOK | COLOR_FLAG * PLAYER_COLOR;
					}
					int end_rank = PLAYER_COLOR == WHITE ? 7 : 0;
					if((board[source] & ~COLOR_FLAG) == PAWN && position.x == end_rank)
						board[index] = QUEEN | COLOR_FLAG * PLAYER_COLOR;
					else
						board[index] = *piece_hold;
					*piece_hold = VOID;
					drawBoard();
					if(!moveHistoryAdd())
						break;
					move(!PLAYER_COLOR);
					if(!moveHistoryAdd())
						break;
				}
				piece_hold = 0;
				drawBoard();
			}
		} break;
	}
	return DefWindowProcA(window,msg,wparam,lparam);
}

int main(void){
	printNumber(evaluate());
	WndClassA wnd_class = {0};
	wnd_class.wnd_proc = windowMessageHandler;
	wnd_class.class_name = "a_class";

	RegisterClassA(&wnd_class);

	int window_size = (BOARD_COORDINATES ? 0x240 : 0x200) / SCALE;

	void* window = CreateWindowExA(0,"a_class","chess",WS_VISIBLE | WS_MINIMIZEBOX | WS_SYSMENU,20,20,window_size,window_size,0,0,wnd_class.instance,0);

	SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE),ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT | ENABLE_PROCESSED_INPUT);
	SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE),ENABLE_PROCESSED_OUTPUT | ENABLE_WRAP_AT_EOL_OUTPUT);

	Msg msg;
	context = GetDC(window);
	void* font = CreateFontA(80 / SCALE,0,0,0,FW_NORMAL,0,0,0,DEFAULT_CHARSET,OUT_OUTLINE_PRECIS,CLIP_DEFAULT_PRECIS,CLEARTYPE_QUALITY,VARIABLE_PITCH,"Segoe UI Symbol");
	SelectObject(context,font);
	int e = GetLastError();
	SetBkMode(context,TRANSPARENT);

	Rect client;
    GetClientRect(window,&client);
    SetWindowPos(window,0,150,50,window_size + (window_size - client.right),window_size + (window_size - client.bottom),0);
	
	brush_square_light = CreateSolidBrush(0x00404040);
	brush_square_dark  = CreateSolidBrush(0x00808080);
	brush_square_coord = CreateSolidBrush(0x00303060);

	if(PLAYER_COLOR == BLACK)
		move(WHITE);
	
	drawBoard();
	
	loop{
		while(PeekMessageA(&msg,window,0,0,0)){
			GetMessageA(&msg,window,0,0);
			DispatchMessageA(&msg);
		}
		if(piece_hold){
			drawBoard();
			Coord cursor = getCursorPosition(window);
			TextOutW(context,cursor.x - 0x08,cursor.y - 0x08,&PieceCharTable[*piece_hold],1);
		}
		Sleep(1);
	}
	
	/*
	int turn = BLACK;
	for(;;){
		while(PeekMessageA(&msg,window,0,0,0)){
			GetMessageA(&msg,window,0,0);
			DispatchMessageA(&msg);
		}
		move(turn);
		turn ^= true;
		drawBoard();
		//Sleep(500);
	}
	*/
	/*
	for(;;){
		move(Color::WHITE);
		//move(Color::BLACK);
		char console_buffer[5];
		unsigned dummy;
		ReadConsoleA(GetStdHandle(STD_INPUT_HANDLE),console_buffer,5,&dummy,0);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		int source = (console_buffer[1] - 0x31) * 8 + (7 - console_buffer[0] + 0x61);
		int destination = (console_buffer[4] - 0x31) * 8 + (7 - console_buffer[3] + 0x61);
		board[destination] = board[source];
		board[source] = VOID;
		ReadConsoleA(GetStdHandle(STD_INPUT_HANDLE),console_buffer,5,&dummy,0);
	}
	*/
}
