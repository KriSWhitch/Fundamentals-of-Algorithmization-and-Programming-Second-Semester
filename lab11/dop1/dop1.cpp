///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <map>
#include <string>
#include <windows.h>
///////////////////////////////////////////////////////////////////////////////
struct  T_subscriber_node;
///////////////////////////////////////////////////////////////////////////////
typedef std::string                                 T_str;
typedef T_subscriber_node* T_subscriber_tree;
typedef std::map            <T_str, int     >   T_count_of_tariff;
///////////////////////////////////////////////////////////////////////////////
struct    T_subscriber
{
	//-------------------------------------------------------------------------
	T_str   phone_num_;
	T_str   name_;
	T_str   tariff_;

	T_str   phone_num_title_;
	T_str   name_title_;
	T_str   tariff_title_;
	//-------------------------------------------------------------------------
	T_subscriber()
		:
		phone_num_title_("номер телефона\t: "),
		name_title_("имя\t\t: "),
		tariff_title_("тариф\t\t: ")
	{}
	//-------------------------------------------------------------------------
	bool    operator<   (T_subscriber  const& subscriber)            const
	{
		return  phone_num_ < subscriber.phone_num_;
	}
	//-------------------------------------------------------------------------
	void    input()
	{
		std::cout << std::endl
			<< "Введите данные абонента:"
			<< std::endl;

		input_phone();

		std::cout << '\t' << name_title_;
		std::cin >> name_;

		std::cout << '\t' << tariff_title_;
		std::cin >> tariff_;
	}
	//-------------------------------------------------------------------------
	void    input_phone()
	{
		std::cout << '\t' << phone_num_title_;
		std::cin >> phone_num_;
	}
	//-------------------------------------------------------------------------
	void    print()                                                     const
	{
		std::cout << phone_num_title_ << phone_num_ << std::endl
			<< name_title_ << name_ << std::endl
			<< tariff_title_ << tariff_ << std::endl;
	}
	//-------------------------------------------------------------------------
};
///////////////////////////////////////////////////////////////////////////////
struct  T_subscriber_node
{
	//-------------------------------------------------------------------------
	T_subscriber        subscriber_;
	T_subscriber_tree   left_;
	T_subscriber_tree   right_;
	//-------------------------------------------------------------------------
	T_subscriber_node(T_subscriber     const& subscriber)
		:
		subscriber_(subscriber),
		left_(),
		right_()
	{}
	//-------------------------------------------------------------------------
};
///////////////////////////////////////////////////////////////////////////////
class   T_subscribers
{
	//-------------------------------------------------------------------------
	T_subscriber_tree   subscriber_tree_;
	//-------------------------------------------------------------------------
public:
	//-------------------------------------------------------------------------
	T_subscribers()
		:
		subscriber_tree_()
	{}
	//-------------------------------------------------------------------------
	void    add_subscriber()
	{
		T_subscriber    subscriber;
		subscriber.input();

		auto    bool_res = successfully_insert_subscriber_in_tree
		(
			subscriber,
			subscriber_tree_
		);

		std::cout << (
			bool_res
			? "Абонент успешно добавлен в базу."
			: "Абонент с таким номером телефона уже существует."
			)

			<< std::endl;
	}
	//-------------------------------------------------------------------------
	void    print_all_subscribers()                                     const
	{
		if (!subscriber_tree_)
		{
			std::cout << "База абонентов пуста."
				<< std::endl;
		}
		else
		{
			std::cout << "Все абоненты базы:"
				<< std::endl;

			int     counter = 0;

			print_tree
			(
				subscriber_tree_,
				counter
			);
		}//else
	}
	//-------------------------------------------------------------------------
	void    find_subscriber_by_phone_num()                              const
	{
		T_subscriber    subscriber_with_phone_num;
		std::cout << "Введите для поиска ";
		subscriber_with_phone_num.input_phone();

		auto    phone_num_tree = get_tree_with_phone_num
		(
			subscriber_tree_,
			subscriber_with_phone_num
		);

		if (!phone_num_tree)
		{
			std::cout << "Абонента с таким номером телефона не существует."
				<< std::endl;
		}
		else
		{
			std::cout << "Абонент с этим номером телефона найден:"
				<< std::endl;
			phone_num_tree->subscriber_.print();
		}
	}
	//-------------------------------------------------------------------------
	void    find_most_popular_tariff()                                  const
	{
		T_count_of_tariff   count_of_tariff;
		int                 popular_tariff_count{};
		T_str               popular_tariff;

		find_popular_tariff_in_tree
		(
			count_of_tariff,
			popular_tariff_count,
			popular_tariff,
			subscriber_tree_
		);

		if (!popular_tariff_count)
		{
			std::cout << "Тариф не найден."
				<< std::endl;
		}
		else
		{
			std::cout << "Самый популярный тариф у абонентов "
				<< popular_tariff
				<< "."
				<< std::endl;
		}
	}
	//-------------------------------------------------------------------------
private:
	//-------------------------------------------------------------------------
	bool    successfully_insert_subscriber_in_tree
	(
		T_subscriber    const& subscriber,
		T_subscriber_tree& subscriber_tree
	)
	{
		if (!subscriber_tree)
		{
			subscriber_tree = new     T_subscriber_node(subscriber);
			return  true;
		}
		else if (
			subscriber < subscriber_tree->subscriber_
			)
		{
			return  successfully_insert_subscriber_in_tree
			(
				subscriber,
				subscriber_tree->left_
			);
		}
		else if (
			subscriber_tree->subscriber_ < subscriber
			)
		{
			return  successfully_insert_subscriber_in_tree
			(
				subscriber,
				subscriber_tree->right_
			);
		}
		else
		{
			return  false;
		}
	}
	//-------------------------------------------------------------------------
	void    print_tree
	(
		T_subscriber_tree   subscriber_tree,
		int                 counter
	)                                                               const
	{
		if (subscriber_tree)
		{
			print_tree
			(
				subscriber_tree->left_,
				counter
			);

			std::cout << std::endl
				<< "Абонент № "
				<< ++counter
				<< std::endl;

			subscriber_tree->subscriber_.print();

			print_tree
			(
				subscriber_tree->right_,
				counter
			);
		}//if
	}
	//-------------------------------------------------------------------------
	T_subscriber_tree   get_tree_with_phone_num
	(
		T_subscriber_tree               subscriber_tree,
		T_subscriber        const& subscriber_with_phone_num
	)                                                               const
	{
		if (!subscriber_tree)
		{
			return  subscriber_tree;
		}
		else
		{
			if (
				subscriber_with_phone_num
				< subscriber_tree->subscriber_
				)
			{
				return  get_tree_with_phone_num
				(
					subscriber_tree->left_,
					subscriber_with_phone_num
				);
			}
			else if (
				subscriber_tree->subscriber_
				< subscriber_with_phone_num
				)
			{
				return  get_tree_with_phone_num
				(
					subscriber_tree->right_,
					subscriber_with_phone_num
				);
			}
			else
			{
				return  subscriber_tree;
			}
		}//else
	}
	//-------------------------------------------------------------------------
	void    find_popular_tariff_in_tree
	(
		T_count_of_tariff& count_of_tariff,
		int& popular_tariff_count,
		T_str& popular_tariff,
		T_subscriber_tree       subscriber_tree
	)                                                               const
	{
		if (subscriber_tree)
		{
			auto& tariff_cur = subscriber_tree->subscriber_.tariff_;
			auto        count_cur = ++count_of_tariff[tariff_cur];

			if (count_cur > popular_tariff_count)
			{
				popular_tariff_count = count_cur;
				popular_tariff = tariff_cur;
			}

			find_popular_tariff_in_tree
			(
				count_of_tariff,
				popular_tariff_count,
				popular_tariff,
				subscriber_tree->left_
			);

			find_popular_tariff_in_tree
			(
				count_of_tariff,
				popular_tariff_count,
				popular_tariff,
				subscriber_tree->right_
			);
		}//if
	}
	//-------------------------------------------------------------------------
};
///////////////////////////////////////////////////////////////////////////////
enum    class   T_action
{
	ADD_SUBSCRIBER = 1,
	PRINT_ALL_SUBSCRIBERS,
	FIND_SUBSCRIBER_BY_PHONE_NUM,
	FIND_MOST_POPULAR_TARIFF,
	EXIT
};
///////////////////////////////////////////////////////////////////////////////
void    print_menu()
{
	std::cout << std::endl
		<< "Выберите действие:"
		<< std::endl;

	std::cout
		<< '\t' << int(T_action::ADD_SUBSCRIBER)
		<< '\t' << "добавить абонента" << std::endl

		<< '\t' << int(T_action::PRINT_ALL_SUBSCRIBERS)
		<< '\t' << "напечатать данные всех абонентов" << std::endl

		<< '\t' << int(T_action::FIND_SUBSCRIBER_BY_PHONE_NUM)
		<< '\t' << "найти абонента по номеру телефона" << std::endl

		<< '\t' << int(T_action::FIND_MOST_POPULAR_TARIFF)
		<< '\t' << "напечатать самый популярный тариф" << std::endl

		<< '\t' << int(T_action::EXIT)
		<< '\t' << "выйти из программы" << std::endl;
}
///////////////////////////////////////////////////////////////////////////////
T_action    input_and_get_action()
{
	std::cout << "Введите номер действия: ";
	int    int_action;
	std::cin >> int_action;
	return  T_action(int_action);
}
///////////////////////////////////////////////////////////////////////////////
int     main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	T_subscribers   subscribers;

	for (;;)
	{
		print_menu();
		auto    action = input_and_get_action();

		if (action == T_action::EXIT)
		{
			break;
		}

		switch (action)
		{
		case   T_action::ADD_SUBSCRIBER:
			subscribers.add_subscriber();
			break;

		case   T_action::PRINT_ALL_SUBSCRIBERS:
			subscribers.print_all_subscribers();
			break;

		case   T_action::FIND_SUBSCRIBER_BY_PHONE_NUM:
			subscribers.find_subscriber_by_phone_num();
			break;

		case   T_action::FIND_MOST_POPULAR_TARIFF:
			subscribers.find_most_popular_tariff();
			break;

		default:
			;
		}
	}//for

	system("pause");
}
