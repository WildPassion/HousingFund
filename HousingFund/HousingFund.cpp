#include "Header.h"

FundArray array;

char menu()
{
	printf("--- Menu ---");
	printf("\n 1. Enter information of housing fund");
	printf("\n 2. Output information");
	printf("\n 3. Sorting by number");
	printf("\n 4. Exit");
	printf("\n Your choice: ");
	return _getch();
}

bool isEmpty(Fund &f)
{
	bool isEmpty = false;
	if (f.number == NULL &&
		f.name == nullptr &&
		f.surname == nullptr &&
		f.address == nullptr &&
		f.phone == nullptr)
	{
		isEmpty = true;
	}
	return isEmpty;
}

void init(Fund &f)
{
	if (f.name == nullptr)
	{
		f.name = (char*)malloc(MAX_SIZE);
	}
	if (f.surname == nullptr)
	{
		f.surname = (char*)malloc(MAX_SIZE);
	}
	if (f.address == nullptr)
	{
		f.address = (char*)malloc(MAX_SIZE);
	}
	if (f.phone == nullptr)
	{
		f.phone = (char*)malloc(MAX_SIZE);
	}
}

void clear(Fund &f)
{
	f.number = NULL;
	if (f.name != nullptr)
		free(f.name);
	if (f.surname != nullptr)
		free(f.surname);
	if (f.address != nullptr)
		free(f.address);
	if (f.phone != nullptr)
		free(f.phone);
}

void clear()
{
	for (size_t i = NULL; i < array.size; i++)
	{
		if (!isEmpty(array.array[i]))
			clear(array.array[i]);
	}
	array.size = NULL;
}

void enter(Fund &f)
{
	printf("Contract number: ");
	scanf("%u", &f.number);
	printf("Enter information about consumer of housing fund\n");
	printf("Name: ");
	scanf("%s", f.name);
	printf("Surname: ");
	scanf("%s", f.surname);
	printf("Home address: ");
	scanf("%s", f.address);
	printf("Phone number: ");
	scanf("%s", f.phone);
}

void add()
{
	if (array.size >= MAX_SIZE)
	{
		printf("Addition error!");
	}
	else
	{
		do {
			init(array.array[array.size]);
			enter(array.array[array.size]);
			array.size++;
			printf("Do you want add element? (\"Enter 'y' - yes\")\n");
		} while (_getch() == 'y');
	}
}

void swap(Fund &first, Fund &second)
{
	Fund tmp;
	init(tmp);

	tmp.number = first.number;
	strcpy(tmp.name, first.name);
	strcpy(tmp.surname, first.surname);
	strcpy(tmp.address, first.address);
	strcpy(tmp.phone, first.phone);

	first.number = second.number;
	strcpy(first.name, second.name);
	strcpy(first.surname, second.surname);
	strcpy(first.address, second.address);
	strcpy(first.phone, second.phone);

	second.number = tmp.number;
	strcpy(second.name, tmp.name);
	strcpy(second.surname, tmp.surname);
	strcpy(second.address, tmp.address);
	strcpy(second.phone, tmp.phone);

	clear(tmp);
}

void sort()
{
	if (array.size == NULL)
	{
		printf("No data!\n");
	}
	else if (array.size != 1)
	{
		for (size_t i = 1; i < array.size; i++)
		{
			if (array.array[i].number < array.array[i - 1].number)
			{
				swap(array.array[i], array.array[i - 1]);
			}
		}
		printf("Sorting is done!\n");
	}
}

void show()
{
	if (array.size == NULL)
	{
		printf("No data!\n");
	}
	else
	{
		printf("+------------+----------------------+----------------------+----------------------+----------------------+\n");
		printf("| №          | Name                 | Surname              | Address              | Phone                |\n");
		printf("+------------+----------------------+----------------------+----------------------+----------------------+\n");
		for (size_t i = NULL; i < array.size; i++)
		{
			printf("| %10u | %20s | %20s | %20s | %20s |\n", array.array[i].number, array.array[i].name, array.array[i].surname, array.array[i].address, array.array[i].phone);
			printf("+------------+----------------------+----------------------+----------------------+----------------------+\n");
		}
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, new COORD);
	while (true)
	{
		system("cls");
		switch (menu())
		{
		case '1':
			system("cls");
			add();
			system("pause");
			break;
		case '2':
			system("cls");
			show();
			system("pause");
			break;
		case '3':
			system("cls");
			sort();
			system("pause");
			break;
		case '4':
			clear();
			return NULL;
		default:
			system("cls");
			printf("Enter number from 1 to 4\n\n");
			system("pause");
			break;
		}
	}
}