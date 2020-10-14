#include "L1List.h"
using namespace std;

element::element()
{
	data = "";
	next = nullptr;
}
element* element::get_next() { return next; }
string element::get_data() { return data; }
void element::set_next(element* new_element) { next = new_element; }
void element::set_data(string information) { data = information; }
element::~element() { }

L1List::L1List()
{
	head = nullptr;
	cur = nullptr;
	tail = nullptr;
}
element* L1List::get_head() { return head; }
element* L1List::get_cur() { return cur; }
element* L1List::get_tail() { return tail; }
void L1List::set_head(element* head_element) { head = head_element; }
void L1List::set_cur(element* current) { cur = current; }
void L1List::set_tail(element* tail_element) { tail = tail_element; }
void L1List::set_next(element* next_element) { cur->set_next(next_element); }
void L1List::set_data(string data) { cur->set_data(data); }
element* L1List::get_next() { return (cur->get_next()); }
string L1List::get_data() { return (cur->get_data()); }

bool L1List::isEmpty()
{
	if (head != nullptr)
		return false; // list is not empty
	return true;
}

void L1List::push_back(string data)
{
	element* new_element = new element;
	new_element->set_data(data);
	if (isEmpty())
		head = cur = tail = new_element;
	else
	{
		tail->set_next(new_element);
		tail = tail->get_next();
		cur = tail;
	}
}

void L1List::push_front(string data)
{
	element* new_element = new element;
	new_element->set_data(data);
	if (isEmpty())
		head = cur = tail = new_element;
	else
	{
		cur = new_element; // cur = new elem
		cur->set_next(head); // cur->next = head
		head = cur; // head = cur
	}
}

void L1List::pop_back()
{
	if (!isEmpty())
	{
		set_cur(get_head()); // cur = head
		if (get_next() == nullptr) // delete head
		{
			element* element_to_delete = head;
			cur = head = tail = nullptr;
			delete element_to_delete;
		}
		else
		{
			while (get_next()->get_next() != nullptr) // while cur->next->next exists
			{
				set_cur(get_next()); // cur = cur->next
			} // cur = the element before the last existing element
			element* element_to_delete = get_next();
			cur->set_next(nullptr);
			tail = cur;
			delete element_to_delete;
		}
	}
	else
		throw out_of_range("The List is empty");
}

void L1List::pop_front()
{
	if (!isEmpty())
	{
		cur = head;
		if (get_next() == nullptr) // delete head
		{
			element* element_to_delete = head;
			head = cur = tail = nullptr;
			delete element_to_delete;
		}
		else
		{
			element* element_to_delete = head;
			set_cur(head->get_next());// cur = head->next
			set_head(cur); // head = cur
			delete element_to_delete;
		}
	}
	else
		throw out_of_range("The List is empty");
}
size_t L1List::get_size()
{
	size_t List_size = 0;
	if (!isEmpty())
	{
		List_size = 1;
		set_cur(get_head()); // now = head
		while (get_next() != nullptr) // while cur->next exists
		{
			set_cur(get_next()); // cur = cur->next
			List_size++;
		} // cur = last existing element
	}
	return List_size;
}
void L1List::insert(string data, size_t index) // first index = 0
{
	if (index == get_size())
		push_back(data);
	else if (index == 0)
		push_front(data);
	else if (index > get_size())
		throw out_of_range("Invalid index");
	else
	{
		set_cur(get_head()); // now = head
		while (index > 1)
		{
			index--;
			set_cur(get_next()); // cur = cur->next
		} // cur is the element before the future new element
		element* new_element = new element;
		new_element->set_data(data);
		new_element->set_next(get_next()); //e->next = cur->next
		set_next(new_element); // cur->next = e
		set_cur(new_element);
	}
}

element* L1List::at(size_t index) // first index = 0
{
	if (index >= get_size())
		throw out_of_range("Invalid index");
	else if (index == 0)
		return head;
	else
	{
		cur = head;
		while (index > 0)
		{
			index--;
			set_cur(get_next()); // cur = cur->next
		} // cur is the element with data index
		return cur;
	}
}

void L1List::remove(size_t index)
{
	if (index >= get_size())
		throw out_of_range("Invalid index");
	else if (index == 0) // delete head
		pop_front();
	else if (index == get_size() - 1)
		pop_back();
	else
	{
		cur = head;
		while (index > 1)
		{
			index--;
			set_cur(get_next()); // cur = cur->next
		} // cur is the element before the deleting element
		element* element_to_delete = new element;
		element_to_delete = get_next();
		set_next(element_to_delete->get_next()); //cur->next = cur->next->next
		if (element_to_delete == nullptr)
			tail = cur;
		delete element_to_delete;
	}
}

void L1List::print_to_console()
{
	set_cur(get_head()); // now = head
	while (get_next() != nullptr)
	{
		cout << get_data() << endl;
		set_cur(get_next()); // cur = cur->next
	}
	cout << get_data() << endl;
}

void L1List::clear()
{
	if (!isEmpty())
	{
		set_cur(get_head()); // cur = head
		while (get_next() != nullptr) // while next exists
		{
			set_cur(get_next()); // cur = cur->next
			delete get_head();
			set_head(get_cur()); // head = cur

		} //cur - the last in the list
		element* element_to_delete = get_head();
		head = cur = tail = nullptr;
		delete element_to_delete;
	}
	else
		throw exception("The List is empty");
}

void L1List::set(size_t index, string data) // change data on index element
{
	if (index >= get_size())
		throw out_of_range("Invalid index");
	else if (index == 0)
		head->set_data(data);
	else if (index == get_size() - 1)
		tail->set_data(data);
	else
	{
		set_cur(get_head()); // now = head
		while (index > 0)
		{
			index--;
			set_cur(get_next()); // cur = cur->next
		} // cur is the element with data index
		cur->set_data(data);
	}
}

void L1List::push_front(L1List* L) // insertion another list into the begining of data
{
	if (!L->isEmpty())
	{
		push_front(L->get_head()->get_data()); // first in this is the same as the first in L now
		element* head_element = head; // now head is a new element because that's how my push_front works
		L->set_cur(L->get_head());
		while (L->get_next() != nullptr) // while cur->next exists
		{
			L->set_cur(L->get_next());
			insert(L->get_cur()->get_data(), 1);
			head = cur; // head is an inserted element - this is made for next iteration
		}
		set_head(head_element);
	}
}

L1List::~L1List()
{
	if (!isEmpty())
		clear();
}

int main()
{
	L1List main_List;
	L1List to_begining_List;
	to_begining_List.push_back("hey");
	to_begining_List.push_front("hmmm");
	to_begining_List.push_back("have you ever thought that...");
	main_List.push_back("maybe");
	main_List.push_back("today");
	main_List.push_back("is");
	main_List.push_back("a very");
	main_List.push_front(&to_begining_List);
	main_List.push_back("good");
	main_List.push_back("day?");
	main_List.print_to_console();
	main_List.clear();
	cout << main_List.isEmpty() << endl;
	return 0;
}
