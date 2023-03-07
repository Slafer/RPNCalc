#pragma once

/// <summary>
/// Структура для хранения элементов стека
/// </summary>

struct elem
{
	/// <summary>
	/// Сохраняемое в стеке значение
	/// </summary>
	char x;
	/// <summary>
	/// Указатель на следующий элемент в стеке
	/// </summary>
	elem* next = nullptr;
};

/// <summary>
/// Добавление элемента в стек
/// </summary>
/// <param name="stack">Указатель на вершину стека</param>
/// <param name="x">Размещаемый в стеке элемент</param>
void push(elem*& stack, char x);

/// <summary>
/// Удаляет из стека элемент и возвращает его значение
/// </summary>
/// <param name="stack">Указатель на вершину стека</param>
/// <param name="x">Возвращаемый элемент</param>
/// <returns>
/// true, если удалось изъять из стека элемент и
/// false в противном случае
/// </returns>
bool pop(elem*& stack, char& x);

/// <summary>
/// Возвращает значение элемента с вершины стека, но оставляет сам элемент в стеке
/// </summary>
/// <param name="stack">Указатель на вершину стека</param>
/// <param name="x">Возвращаемое значение элемента с вершины стека</param>
/// <returns>
/// true, если удалось получить из стека элемент и
/// false в противном случае
/// </returns>
bool peek(const elem* stack, char& x);

/// <summary>
/// Функция удаления стека из памяти 
/// </summary>
/// <param name="stack">Указатель на вершины удаляемого стека</param>
void clear(elem*& stack);

struct elem_i
{
	/// <summary>
	/// Сохраняемое в стеке значение
	/// </summary>
	double x;
	/// <summary>
	/// Указатель на следующий элемент в стеке
	/// </summary>
	elem_i* next = nullptr;
};

/// <summary>
/// Добавление элемента в стек
/// </summary>
/// <param name="stack">Указатель на вершину стека</param>
/// <param name="x">Размещаемый в стеке элемент</param>
void push(elem_i*& stack, double x);

/// <summary>
/// Удаляет из стека элемент и возвращает его значение
/// </summary>
/// <param name="stack">Указатель на вершину стека</param>
/// <param name="x">Возвращаемый элемент</param>
/// <returns>
/// true, если удалось изъять из стека элемент и
/// false в противном случае
/// </returns>
bool pop(elem_i*& stack, double& x);

/// <summary>
/// Возвращает значение элемента с вершины стека, но оставляет сам элемент в стеке
/// </summary>
/// <param name="stack">Указатель на вершину стека</param>
/// <param name="x">Возвращаемое значение элемента с вершины стека</param>
/// <returns>
/// true, если удалось получить из стека элемент и
/// false в противном случае
/// </returns>
bool peek(const elem_i* stack, double& x);

/// <summary>
/// Функция удаления стека из памяти 
/// </summary>
/// <param name="stack">Указатель на вершины удаляемого стека</param>
void clear(elem_i*& stack);
