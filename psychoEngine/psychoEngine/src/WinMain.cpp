#include "pch.h"
/*---------------------------------------------------*/
/* Arquivo: WinMain.cpp                              */
/* Autor: Matheus Roger                              */
/*---------------------------------------------------*/

/*---------------------------------------------------*/
/* Váriaveis Globais                                 */
/*---------------------------------------------------*/
#pragma region VariaveisGlobais
WCHAR WindowClass[MAX_NAME_STRING];
WCHAR WindowTitle[MAX_NAME_STRING];

INT WindowWidth;
INT WindowHeight;
#pragma endregion
/*---------------------------------------------------*/



/*---------------------------------------------------*/
/* Pré-Declarações                                           */
/*---------------------------------------------------*/
#pragma region Funções
VOID InicializarVariaveis();
VOID ConfigJanela();
VOID InicializarJanela();
VOID MessageLoop();
#pragma endregion
/*---------------------------------------------------*/


/*----------------------------------------------------------------*/
/* Operações                                                      */
/*----------------------------------------------------------------*/
INT CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	InicializarVariaveis();
	ConfigJanela();
	InicializarJanela();
	MessageLoop();



	return 0;
}
/*----------------------------------------------------------------*/


/*----------------------------------------------------------------*/
/* Função para encerrar processo do programa após fechamento!     */
/* Essa função será usada como processo do lpfnWndProc            */
/*----------------------------------------------------------------*/
LRESULT CALLBACK WindowProcess(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}
/*----------------------------------------------------------------*/



/*----------------------------------------------------------------*/
/* Funções                                                        */
/*----------------------------------------------------------------*/
#pragma region Funções

VOID InicializarVariaveis() {
	/* - Starta as variaveis globais - */
	LoadString(HInstance(), IDS_PERGAMENAME, WindowTitle, MAX_NAME_STRING);
	LoadString(HInstance(), IDS_WINDOWCLASS, WindowClass, MAX_NAME_STRING);

	WindowWidth = 1366;
	WindowHeight = 768;
}

VOID ConfigJanela() {
	/* - Configurações da janela - */
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH); // NULL BRUSH = WHITE BACKGROUND
	wcex.hIcon = 0; // Window Icon and TaskBar
	wcex.hIconSm = 0; // Process Icon
	wcex.lpszClassName = WindowClass;
	wcex.lpszMenuName = nullptr;
	wcex.hInstance = HInstance();
	wcex.lpfnWndProc = WindowProcess;
	RegisterClassEx(&wcex);
}

VOID InicializarJanela() {
	/* - Cria e mostra a janela - */

	HWND hWnd = CreateWindow(WindowClass, WindowTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, WindowWidth, WindowHeight, nullptr, nullptr, HInstance(), nullptr);
	if (!hWnd) {
		MessageBox(0, L"Falha ao criar a janela!", 0, 0);
		PostQuitMessage(0);
	}
	ShowWindow(hWnd, SW_SHOW);
}

VOID MessageLoop() {
	/* - Escuta eventos de mensagem - */
	MSG msg = { 0 };
	while (msg.message != WM_QUIT) {
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}
#pragma endregion
/*----------------------------------------------------------------*/