#include <windows.h>
#include <string>
#include <time.h>
#include <stdlib.h>


//ID for the objects like txtbox and buttons
#define ID_BtRange_Number_Ramdom 1
#define ID_TxtStart_NumberRamdom 2
#define ID_TxtEnd_NumberRamdom 3
#define ID_TxtNumber 4
#define ID_LbResult 5
#define ID_BtNumber 6


//Declared all var and txtbox, buttons and a label for the result
static HWND TxtRange_Number_Start;
static HWND TxtRange_Number_End;
static HWND TxtNumber;
static HWND Lb_Result;
static HWND Button_Range_Number;
static HWND Button_Number;
static int Number_Ramdom_Start = 1;
static int Number_Ramdom_End = 100;
static int Number_Ramdom = Number_Ramdom_Start + rand()%Number_Ramdom_End;


/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT PaintStruct;
	HDC hDC;
	static int Number_Ramdom = 100;

	
	switch(Message) {
		
		case WM_CREATE:{
			
			//This create a new Label or STATIC TEXT
			Lb_Result = CreateWindow(TEXT("STATIC"), TEXT("."), 
			WS_VISIBLE | WS_CHILD, 
			140, 180, 200, 30,
			hwnd, (HMENU) ID_LbResult, NULL, NULL);
			
			//This create a new TextBox where the user can put something/
			TxtRange_Number_Start = CreateWindow(TEXT("EDIT"), TEXT(""), 
			WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL, 
			60, 65, 80, 20,
			hwnd, (HMENU) ID_TxtStart_NumberRamdom, NULL, NULL
			);
			
			//This create a new TextBox where the user can put something/
			TxtRange_Number_End = CreateWindow(TEXT("EDIT"), TEXT(""), 
			WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL, 
			60, 85, 80, 20,
			hwnd, (HMENU) ID_TxtEnd_NumberRamdom, NULL, NULL
			);
			
			
			//This create a new TextBox where the user can put something/
			TxtNumber = CreateWindow(TEXT("EDIT"), TEXT(""), 
			WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL, 
			125, 120, 80, 20,
			hwnd, (HMENU) ID_TxtNumber, NULL, NULL
			);
			
			//This create a new Button where the user can do a action/
			Button_Range_Number = CreateWindow(TEXT("BUTTON"), TEXT("Ingresar"), 
			WS_VISIBLE | WS_CHILD, 
			180, 70, 80, 30,
			hwnd, (HMENU) ID_BtRange_Number_Ramdom, NULL, NULL
			);
			
			//This create a new Button where the user can do a action/
			Button_Number = CreateWindow(TEXT("BUTTON"), TEXT("Ingresar"), 
			WS_VISIBLE | WS_CHILD, 
			10, 140, 80, 30,
			hwnd, (HMENU) ID_BtNumber, NULL, NULL
			);
			
			break;
		}
		
		case WM_COMMAND:{
			//Action of the buttons
			
			//Action of Button for the range for random number
			if(LOWORD(wParam) ==  ID_BtRange_Number_Ramdom){
				int Length_Start_Number_Ramdom = GetWindowTextLength(TxtRange_Number_Start) + 1;
				int Length_End_Number_Ramdom = GetWindowTextLength(TxtRange_Number_End) + 1;
				static char Range_Number_Ramdom[500];

				GetWindowText(TxtRange_Number_Start, Range_Number_Ramdom, Length_Start_Number_Ramdom);
				
				SetWindowText(Lb_Result, Range_Number_Ramdom);
			}
			
			
			//Action of Button Number for trying
			if(LOWORD(wParam) ==  ID_BtNumber){
				int Length_Number = GetWindowTextLength(TxtNumber) + 1;
				static char Number[500];
				
				GetWindowText(TxtNumber, Number, Length_Number);
				
				if(Number_Ramdom != Number_Ramdom){
					
				}
				
				SetWindowText(Lb_Result, Number);
			}
			break;
		}
		
		case WM_PAINT:{
			//paint about the text static, for not use a lot Windows
				hDC = BeginPaint(hwnd, &PaintStruct);
				// Text: Introduccion Juego
				TextOut(hDC, 10, 5, "Este programa es un juego de adivina el numero!", 48 );
				TextOut(hDC, 10, 25, "Puedes poner el rango del numero o el programa tomara del 1 al 100", 66);
				// Text: Rango
				TextOut(hDC, 10, 45, "Rango del numero", 16);
				TextOut(hDC, 10, 65, "Inicio: ", 7);
				TextOut(hDC, 10, 85, "Final: ", 6);
				TextOut(hDC, 10, 120, "Dame el numero:  ", 17);
				EndPaint(hwnd, &PaintStruct);
				break;
		}
			
		/* Upon destruction, tell the main thread to stop */
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		
		/* All other messages (a lot of them) are processed using default procedures */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG msg; /* A temporary location for all messages */

	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	
	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Juego Numero Aleatorio",WS_VISIBLE|WS_SYSMENU,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		470, /* width */
		300, /* height */
		NULL,NULL,hInstance,NULL);

	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	/*
		This is the heart of our program where all input is processed and 
		sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
		this loop will not produce unreasonably high CPU usage
	*/
	while(GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&msg); /* Translate key codes to chars if present */
		DispatchMessage(&msg); /* Send it to WndProc */
	}
	return msg.wParam;
}
