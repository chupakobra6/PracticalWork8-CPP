// PracticalWork8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <wtypes.h>
#include <array>
#include <list>
#include <forward_list>
#include <stack>
#include <queue>
#include <functional>

using namespace std;

struct Book
{
	string title, author, genre;
	int year;

	Book(const string& title, const string& author, const string& genre, int year) : title(title), author(author), genre(genre), year(year) {}

	bool operator<(const Book& other) const {
		return year < other.year;
	}
	bool operator>(const Book& other) const {
		return year > other.year;
	}
};

void printBooksStack(stack<Book>& books)
{
	cout << "Книги в обратном порядке (используя Stack):" << endl;
	while (!books.empty())
	{
		const Book& book = books.top();
		cout << "Название: " << book.title << ", Автор: " << book.author << ", Жанр: " << book.genre << ", Год выпуска: " << book.year << endl;
		books.pop();
	}
	cout << endl;
}

void printBooksQueue(queue<Book>& books)
{
	cout << "Книги в порядке записи (используя Queue):" << endl;
	while (!books.empty())
	{
		const Book& book = books.front();
		cout << "Название: " << book.title << ", Автор: " << book.author << ", Жанр: " << book.genre << ", Год выпуска: " << book.year << endl;
		books.pop();
	}
	cout << endl;
}

void printBooksPriorityQueue(priority_queue<Book, vector<Book>, greater<Book>>& books)
{
	cout << "Книги, отсортированные по году выпуска (используя Priority Queue):" << endl;
	while (!books.empty())
	{
		const Book& book = books.top();
		cout << "Название: " << book.title << ", Автор: " << book.author << ", Жанр: " << book.genre << ", Год выпуска: " << book.year << endl;
		books.pop();
	}
	cout << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	list<Book> bookList;
	forward_list<Book> bookForwardList;

	string title, author, genre;
	int year;

	cout << "Введите информацию о трёх книгах:" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "Книга " << i + 1 << ":" << endl << "Название: ";
		getline(cin, title);
		cout << "Автор: ";
		getline(cin, author);
		cout << "Жанр: ";
		getline(cin, genre);
		cout << "Год выпуска: ";
		cin >> year;
		cout << endl;

		cin.ignore();

		Book book(title, author, genre, year);
		bookList.push_back(book);
		bookForwardList.push_front(book);
	}

	array<Book, 3> bookArray = { bookList.front(), *(++bookList.begin()), bookList.back() };

	stack<Book> bookStack;
	queue<Book> bookQueue;
	priority_queue<Book, vector<Book>, greater<Book>> bookPriorityQueue;

	for (const Book& book : bookArray)
	{
		bookStack.push(book);
		bookQueue.push(book);
		bookPriorityQueue.push(book);
	}

	printBooksStack(bookStack);
	printBooksQueue(bookQueue);
	printBooksPriorityQueue(bookPriorityQueue);

	return 0;
}