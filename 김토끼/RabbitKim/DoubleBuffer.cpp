#include "DoubleBuffer.h"


DoubleBuffer* DoubleBuffer::m_pInstance = NULL;

DoubleBuffer::DoubleBuffer(void) : m_iBufferIndex(0)
{
	
}

DoubleBuffer::~DoubleBuffer(void)
{

}

// ���� ����
void DoubleBuffer::CreateBuffer(const int& _width, const int& _height)
{
	CONSOLE_CURSOR_INFO DeCursor;            // �ܼ�â �����̴� Ŀ��
	COORD size = { (short)_width-1, (short)_height-1 };     // ���� ũ�⸦ �����ϴ� ����ü
	SMALL_RECT rect;                    // â ũ�⸦ �����ϴ� ����ü


	rect.Left = 0;
	rect.Right = CONSOL_MAX_WIDTH;
	rect.Top = 0;
	rect.Bottom = CONSOL_MAX_HEIGHT;

	// 1�� ���� ����
	m_HBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE , 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(m_HBuffer[0], size);  // ���� ũ�� ����
	SetConsoleWindowInfo(m_HBuffer[0], TRUE, &rect); // â ũ�� ����


	// 2�� ���� ����
	m_HBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE , 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(m_HBuffer[1], size);  // ���� ũ�� ����
	SetConsoleWindowInfo(m_HBuffer[1], TRUE, &rect); // â ũ�� ����


	DeCursor.dwSize = 1;
	DeCursor.bVisible = FALSE;


	SetConsoleCursorInfo(m_HBuffer[0], &DeCursor); // 1�� ���ۿ� �����̴� Ŀ�� ����
	SetConsoleCursorInfo(m_HBuffer[1], &DeCursor); // 2�� ���ۿ� �����̴� Ŀ�� ����
}

// ���� ����
void DoubleBuffer::WriteBuffer(int x, int y, char* _str, int _color)
{
	DWORD dw;                           // ��ǥ ���� ����ü
	COORD CursorPosition = { (short)x, (short)y };    // ��ǥ ����

	// ��ǥ �̵�
	SetConsoleCursorPosition(m_HBuffer[m_iBufferIndex], CursorPosition);

	SetColor(_color);

	// ���ۿ� ����
	WriteFile(m_HBuffer[m_iBufferIndex], _str, (DWORD)strlen(_str), &dw, NULL);
}

void DoubleBuffer::WriteBuffer(int x, int y, int _ivalue, int _color)
{
	DWORD dw;	// ��ǥ ���� ����ü
	COORD CursorPosition = { (short)x, (short)y };    // ��ǥ ����

	// ��ǥ �̵�
	SetConsoleCursorPosition(m_HBuffer[m_iBufferIndex], CursorPosition);

	char* cStr = NULL;

	cStr = new char[sizeof(int) + 1];
	_itoa(_ivalue, cStr, 10);

	SetColor(_color);
	// ���ۿ� ����
	WriteFile(m_HBuffer[m_iBufferIndex], cStr, (DWORD)strlen(cStr), &dw, NULL);
}

// ���� ��ȯ
void DoubleBuffer::FlippingBuffer()
{
	// ���� Ȱ��ȭ. ������ ������ �ѹ��� ���
	SetConsoleActiveScreenBuffer(m_HBuffer[m_iBufferIndex]);
	m_iBufferIndex = !m_iBufferIndex; // ���� ���� ����
}

// ���� �����
void DoubleBuffer::ClearBuffer()
{
	COORD Coor = { 0, 0 };  // �Ʒ� �Լ��� ���� ����ü
	DWORD dw;               // �Ʒ� �Լ��� ���� ����ü

	// �ش� ������ Coor ��ǥ���� ' '���� ä���� ������ ��ó�� �����
	FillConsoleOutputCharacter(m_HBuffer[m_iBufferIndex], ' ', CONSOL_MAX_WIDTH * CONSOL_MAX_HEIGHT, Coor, &dw);
}

// ���� ����
void DoubleBuffer::DestroyBuffer()
{
	MyCloseHandle(m_HBuffer[0]);    // 1�� ���� ����
	MyCloseHandle(m_HBuffer[1]);    // 2�� ���� ����
	// (HANDLE�� ������ �������� �״��. �ش� ������ ���� HANDLE Ŀ�θ� ����)
}

// �����ϰ� CloseHandle�� ó���ϱ� ���� MyCloseHandle ����
bool DoubleBuffer::MyCloseHandle(HANDLE& hFile)
{
	if (INVALID_HANDLE_VALUE != hFile)
	{
		hFile = INVALID_HANDLE_VALUE;
	}
	return false;
}

void DoubleBuffer::SetColor(int color)
{
	SetConsoleTextAttribute(m_HBuffer[m_iBufferIndex], color);
}
